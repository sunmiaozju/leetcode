/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 *
 * https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (44.29%)
 * Likes:    131
 * Dislikes: 0
 * Total Accepted:    14.1K
 * Total Submissions: 31.8K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * 
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 * 
 * 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
 * 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 * 
 * 示例: 
 * 
 * 你可以将以下二叉树：
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * 序列化为 "[1,2,3,null,null,4,5]"
 * 
 * 提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode
 * 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
 * 
 * 说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if (!root) {
            return "";
        }
        queue<TreeNode*> q;
        string ans = "";
        q.push(root);
        ans += to_string(root->val) + " ";
        while (!q.empty()) {
            int size = q.size();
            bool has = false;
            string items;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    has = true;
                    items += to_string(node->left->val) + " ";
                } else {
                    items += "# ";
                }

                if (node->right) {
                    q.push(node->right);
                    has = true;
                    items += to_string(node->right->val) + " ";
                } else {
                    items += "# ";
                }
            }
            if (has) {
                ans = ans + items;
            }
        }
        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        if (data == "") {
            return NULL;
        }
        istringstream in(data);
        queue<TreeNode*> q;

        string val;
        in >> val;
        TreeNode* root = new TreeNode(stoi(val));
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!(in >> val)) {
                break;
            }
            if (val != "#") {
                TreeNode* item = new TreeNode(stoi(val));
                node->left = item;
                q.push(item);
            }
            if (!(in >> val)) {
                break;
            }
            if (val != "#") {
                TreeNode* item = new TreeNode(stoi(val));
                node->right = item;
                q.push(item);
            }
        }
        return root;
    }
};

// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         ostringstream s;
//         serial(root, s);
//         return s.str();
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         istringstream in(data);
//         return deserial(in);
//     }

//     void serial(TreeNode* node, ostringstream& s){
//         if(node){
//             s << to_string(node->val);
//             s << " ";
//         }else{
//             s << "# ";
//             return;
//         }
//         serial(node->left, s);
//         serial(node->right, s);
//     }

//     TreeNode* deserial(istringstream& s){
//         string val;
//         s >> val;
//         if(val == "#"){
//             return NULL;
//         }

//         TreeNode * node = new TreeNode(stoi(val));

//         node->left = deserial(s);
//         node->right = deserial(s);

//         return node;
//     }
// };

// // Your Codec object will be instantiated and called as such:
// // Codec codec;
// // codec.deserialize(codec.serialize(root));
// @lc code=end
