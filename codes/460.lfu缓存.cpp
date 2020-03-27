/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU缓存
 *
 * https://leetcode-cn.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (33.79%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    2.9K
 * Total Submissions: 8.5K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * 设计并实现最不经常使用（LFU）缓存的数据结构。它应该支持以下操作：get 和 put。
 * 
 * get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
 * put(key, value) -
 * 如果键不存在，请设置或插入值。当缓存达到其容量时，它应该在插入新项目之前，使最不经常使用的项目无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，最近最少使用的键将被去除。
 * 
 * 进阶：
 * 你是否可以在 O(1) 时间复杂度内执行两项操作？
 * 
 * 示例：
 * 
 * 
 * LFUCache cache = new LFUCache( 2  );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回 1
 * cache.put(3, 3);    // 去除 key 2
 * cache.get(2);       // 返回 -1 (未找到key 2)
 * cache.get(3);       // 返回 3
 * cache.put(4, 4);    // 去除 key 1
 * cache.get(1);       // 返回 -1 (未找到 key 1)
 * cache.get(3);       // 返回 3
 * cache.get(4);       // 返回 4
 * 
 */

// @lc code=start

#include <set>
#include <string>
#include <unordered_map>
using namespace std;

template <class KEY>
struct CacheKey {
    KEY key;
    int count;
    CacheKey(KEY k)
        : key(k)
        , count(1)
    {
    }
    void change(int x)
    {
        count += x;
    }
    int getcount()
    {
        return count;
    }
};

template <class KEY, class VAL>
struct CacheNode {
    CacheKey<KEY>* cacheKey;
    VAL val;
    CacheNode(CacheKey<KEY>* ck, VAL v)
        : cacheKey(ck)
        , val(v)
    {
    }
    CacheNode(KEY k, VAL v)
        : val(v)
    {
        cacheKey = new CacheKey<KEY>(k);
    }
};

template <class KEY>
struct CMP //仿函数，提供CacheKey的比较方式
{
    bool operator()(CacheKey<KEY> const* x, CacheKey<KEY> const* y)
    {
        return x->count < y->count;
    }
};

class LFUCache {
public:
    LFUCache(int capacity)
    {
    }

    int get(int key)
    {
    }

    void put(int key, int value)
    {
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

/*
LFU (least Frequently Used)
根据数据的历史访问次数来决定淘汰数据，也就是当前时刻访问次数大的数据，
在下一时刻也可能被访问到。
1.每个节点（数据块）都有一个访问次数
2.相同访问次数的依据时间排序，后插入的在前面
3.当需要淘汰数据时，会从尾部，也就是访问次数从小到大，开始淘汰
*/
template <class KEY, class VAL>
class Lfu {
public:
    Lfu(size_t size)
        : cacheSize(size)
    {
    }
    ~Lfu()
    {
        auto ite = cacheMap.begin();
        while (ite != cacheMap.end()) {
            delete ite->second->cacheKey;
            delete ite->second;
            ++ite;
        }
        cacheMap.clear();
        cacheSet.clear();
    }

public:
    void put(KEY key, VAL val)
    {
        this->check_cache_size();
        auto node = new CacheNode<KEY, VAL>(key, val);
        cacheMap[key] = node;
        cacheSet.insert(node->cacheKey);
    }

    bool get(KEY key, VAL* val)
    {
        if (cacheMap.count(key)) {
            auto node = this->removeFromSet(key);
            if (val)
                *val = node->val;
            node->cacheKey->change(1);
            cacheSet.insert(node->cacheKey);
            return true;
        }
        return false;
    }

    VAL get(KEY key)
    {
        VAL v;
        this->get(key, &v);
        return v;
    }

    void remove(KEY key)
    {
        if (cacheMap.count(key)) {
            auto node = cacheMap[key];
            this->removeFromSet(node->key);
            delete node->key;
            delete node;
            cacheMap.erase(key);
        }
    }

    bool exist(KEY key)
    {
        if (cacheMap.count(key))
            return true;
        return false;
    }

    void print_test()
    {
        auto ite = cacheSet.begin();
        while (ite != cacheSet.end()) {
            cout << "count: " << (*ite)->count << " key: " << (*ite)->key << endl;
            ++ite;
        }
        cout << "======================================" << endl;
    }

private:
    //将节点从set中删除，返回删除的node
    void removeFromSet(CacheKey<KEY>* key)
    {
        auto ite = cacheSet.find(key);
        while (ite != cacheSet.end()) {
            if (key == cacheMap[(*ite)->key]->key) {
                cacheSet.erase(ite);
                break;
            }
            auto itex = ite;
            ++ite;
            if (ite != cacheSet.end() && (*ite)->getcount() != (*itex)->getcount()) {
                break;
            }
        }
    }
    //检查缓存数量是否超出了大小限制
    void check_cache_size()
    {
        while (cacheMap.size() >= cacheSize) {
            auto ite = cacheSet.begin();
            cacheMap.erase((*ite)->key);
            cacheSet.erase(ite);
        }
    }

private:
    multiset<CacheKey<KEY>*, CMP<KEY>> cacheSet; //利用红黑树根据访问次数排序
    unordered_map<KEY, CacheNode<KEY, VAL>*> cacheMap; //缓存MAP
    size_t cacheSize; //缓存空间大小
};
