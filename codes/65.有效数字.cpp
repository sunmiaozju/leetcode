/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 *
 * https://leetcode-cn.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (17.89%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    8.9K
 * Total Submissions: 49.9K
 * Testcase Example:  '"0"'
 *
 * 验证给定的字符串是否可以解释为十进制数字。
 * 
 * 例如:
 * 
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * " -90e3   " => true
 * " 1e" => false
 * "e3" => false
 * " 6e-1" => true
 * " 99e2.5 " => false
 * "53.5e93" => true
 * " --6 " => false
 * "-+3" => false
 * "95a54e53" => false
 * 
 * 说明: 我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。这里给出一份可能存在于有效十进制数字中的字符列表：
 * 
 * 
 * 数字 0-9
 * 指数 - "e"
 * 正/负号 - "+"/"-"
 * 小数点 - "."
 * 
 * 
 * 当然，在输入中，这些字符的上下文也很重要。
 * 
 * 更新于 2015-02-10:
 * C++函数的形式已经更新了。如果你仍然看见你的函数接收 const char * 类型的参数，请点击重载按钮重置你的代码。
 * 
 */

// @lc code=start
class Solution {
public:
    bool isNumber(string s)
    {
        int i = 0, j = s.size() - 1;
        while (s[i] == ' ' || s[j] == ' ') {
            if (s[i] == ' ')
                i++;
            if (s[j] == ' ')
                j--;
        }
        s = s.substr(i, j - i + 1);
        if (s.empty()) {
            return false;
        }
        bool sign = false, exp = false, dot = false, num = false, numAfterE = true;
        for (int i = 0; i < s.size(); i++) {
            cout << s[i] << endl;
            if (i == s.size() - 1 && num == false && !(s[i] >= '0' && s[i] <= '9')) {
                return false;
            }
            if (i == 0) {
                if (!(s[i] == '+' || s[i] == '-' || (s[i] >= '0' && s[i] <= '9') || s[i] == '.')) {
                    return false;
                }
                if (s.size() == 1 && !(s[0] >= '0' && s[0] <= '9')) {
                    return false;
                }
                if (s[0] == '.') {
                    dot = true;
                }
                if (s[0] >= '0' && s[0] <= '9') {
                    num = true;
                }
            }
            // 符号
            else if (i > 0 && (s[i] == '+' || s[i] == '-')) {
                if (s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            }
            // 数字
            else if (s[i] >= '0' && s[i] <= '9') {
                if (exp) {
                    numAfterE = true;
                }
                num = true;
            }
            // 小数点
            else if (s[i] == '.') {

                if (s.size() == 1) {
                    return false;
                }
                if (exp == true) {
                    return false;
                }
                if (dot == true) {
                    return false;
                }
                dot = true;
            }
            // 自然底数
            else if (s[i] == 'e' || s[i] == 'E') {
                if (num == false) {
                    return false;
                }
                if (exp == true) {
                    return false;
                }
                exp = true;
                numAfterE = false;
            } else {
                return false;
            }
        }
        if (!numAfterE) {
            return false;
        }
        return true;
    }
};
// @lc code=end
