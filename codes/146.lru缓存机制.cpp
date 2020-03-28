/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (45.40%)
 * Likes:    446
 * Dislikes: 0
 * Total Accepted:    38.8K
 * Total Submissions: 83.9K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
 * 
 * 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
 * 写入数据 put(key, value) -
 * 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 * 
 * 进阶:
 * 
 * 你是否可以在 O(1) 时间复杂度内完成这两种操作？
 * 
 * 示例:
 * 
 * LRUCache cache = new LRUCache( 2 );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回  1
 * cache.put(3, 3);    // 该操作会使得密钥 2 作废
 * cache.get(2);       // 返回 -1 (未找到)
 * cache.put(4, 4);    // 该操作会使得密钥 1 作废
 * cache.get(1);       // 返回 -1 (未找到)
 * cache.get(3);       // 返回  3
 * cache.get(4);       // 返回  4
 * 
 * 
 */

// @lc code=start
class LRUCache {
public:
    class Node {
    public:
        Node* prev;
        Node* next;
        int val;
        int key;
        Node(int k, int v)
            : key(k)
            , val(v)
        {
            next = NULL;
            prev = NULL;
        }
    };

    int size = 0, cap = 0;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> map;

    LRUCache(int capacity)
    {
        cap = capacity;
        size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void dele_node(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert_node(Node* node)
    {
        Node* tail_tmp = head->next;
        head->next = node;
        node->prev = head;
        node->next = tail_tmp;
        tail_tmp->prev = node;
    }

    void move2head(Node* node)
    {
        dele_node(node);
        insert_node(node);
    }

    void pop_tail()
    {
        Node* tmp = tail->prev;
        dele_node(tmp);
        delete tmp;
    }

    int get(int key)
    {

        if (map.count(key)) {
            int ans = map[key]->val;
            move2head(map[key]);
            return ans;
        } else {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (map.count(key)) {
            map[key]->val = value;
            move2head(map[key]);
            return;
        }
        Node* node = new Node(key, value);
        map[key] = node;
        insert_node(node);
        size++;

        if (size > cap) {
            size--;
            map.erase(tail->prev->key);
            pop_tail();
        }
    }
};

class node {
public:
    int val;
    int key;
    node* next;
    node* prev;
    node(int v, int k)
        : key(k)
        , val(v)
    {
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, node*> map;
    node *head, *tail;

    int count = 0;
    int size = 0;

    void insert(node* item)
    {
        // cout << "---1" << endl;
        // node* head_tmp = head->next;
        //  cout << "---2" << endl;
        // head->next = item;
        // item->prev = head;
        // item->next = head_tmp;
        // head_tmp->prev = item;

        node* tail_tmp = head->next;
        head->next = item;
        item->prev = head;
        item->next = tail_tmp;
        tail_tmp->prev = item;
    }

    void remove(node* item)
    {
        item->prev->next = item->next;
        item->next->prev = item->prev;
    }

    void move2head(node* item)
    {
        remove(item);
        insert(item);
    }

    void remove_tail()
    {
        node* item = tail->prev;
        remove(item);
    }

    LRUCache(int capacity)
    {
        size = capacity;
        node* head = new node(0, 0);
        node* tail = new node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        cout << "get: " << key << endl;
        int ans = map[key]->val;
        move2head(map[key]);
        return ans;
    }

    void put(int key, int value)
    {
        cout << "put: " << key << " " << value << endl;
        if (map.count(key)) {
            map[key]->val = value;
            move2head(map[key]);
        } else {

            node* item = new node(value, key);
            map[key] = item;
            cout << "+++" << endl;
            insert(item);
            count++;
            cout << "--" << endl;
            if (count > size) {
                map.erase(map.find(tail->prev->key));
                remove_tail();
                count--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
