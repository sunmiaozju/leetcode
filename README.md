# leetcode

[TOC]

---

- [二分搜索法总结](./docs/binary_search.md)

- [动态规划总结]

- [回溯法总结](./docs/backtracking.md)

---

## 1. Two sum

使用 hash 表来记录已经存储的数据，新来的数据与 target 做差，判断是否在 hash 表中存在

## 5. Longest Palindromic Substring

正常方法要区分奇偶串，但是也可以首先便遍历中间重复的字符，将奇数偶数串统一处理

或者使用动态规划的方法，dp[i][j]表示这个 ij 区间内的是回文字符串，那么有递推公式：

```c++
dp[i][j] = true
{
if i==j
if j-1<2 && s[i]==s[j]
if dp[i+1][j-1]==true && s[i]==s[j]
}
```

## 6. zig-zag Conversion

o(n)time o(1)space 的算法是找到每一排循环的规律，是按照一定的周期循环的，或者可以使用 o(n)space ,不断的调整填充辅助数组的方向进行填充

## 7. reverse integer

这里要求时说如果 int 反转之后超如了有符号位 32 位大小的限制范围，那么就要返回 0，可以将结果先用 long 保存，然后在计算，并比较最后的结果是否超出了范围，并返回比较后的结果

## 9. Palindrome Number

这里如果是负数一定不是 Palindrome Number， 然后可以转化为字符串用双指针来做，也可以将数字进行反转，然后比较二者是否相等，或者可以比较一半，这种方法最快，就是将原本剩下砍掉的数字和新累乘的数字进行比较，知道新的数字大于剩下砍掉的数字，但是要注意边界条件，数字可以被 10 整除的是非常特殊的。

## 14. Longest Common Prefix

先排序，排好序找到最短的字符串的长度，然后遍历最短字符串长度，逐个比较排序后的第一个字符串和最后一个字符串

## 15. three-num

类似于 two num 题目的解法，但是不同的是要固定一个数字，然后找到另外两个数字，同时需要注意不要有重复的组合出现，解决方法是对于相同的数字，我们就将 index 跳过。

## 17. letter combination of a phone number

递归解法，类似于回溯的层级递归解法，整体的结构就是一个树形网络，在数行网络的最低端返回结果

补充：典型的回溯解法，就是设置 help 的参数一般包括&path，&paths,遇到层级底部，将 path 添加到 paths，然后函数返回并，将 path 最后一位去掉，这样就可以遍历所有情况。回溯和 DFS 很像，但是也有区别的地方，主要是以下几点：

Backtracking（回溯）属于 DFS。

- 普通 DFS 主要用在 可达性问题 ，这种问题只需要执行到特点的位置然后返回即可。
- 而 Backtracking 主要用于求解 排列组合 问题，例如有 { 'a','b','c' } 三个字符，求解所有由这三个字符排列得到的字符串，这种问题在执行到特定的位置返回之后还会继续执行求解过程。

因为 Backtracking 不是立即返回，而要继续求解，因此在程序实现时，需要注意对元素的标记问题：

- 在访问一个新元素进入新的递归调用时，需要将新元素标记为已经访问，这样才能在继续递归调用时不用重复访问该元素；
- 但是在递归返回时，需要将元素标记为未访问，因为只需要保证在一个递归链中不同时访问一个元素，可以访问已经访问过但是不在当前递归链中的元素。

## 19. Remove Nth Node From End of List

这道题目让去除链表里面倒数第 n 个元素。

可以开始让 head 不断前进，然后 count 计数。如果计数大于等于 n，另一个指针 item 开始前进，当 head 到达末尾的时候，item 就到达了目标位置。需要注意的是细节的处理，使用 pre 指针很方便。

## 21. Merge Two Sorted Lists

这道题目是将两个已经排序的链表进行融合，注意的一点就是设置一个 pre 指针，然后不断的添加就可以。

## 24. Swap Nodes in Pairs

这道题目是按照次序交换相邻的两个节点。注意处理好 next 的关系和循环停止条件。

## 34. find first ans last position of element in sorted array

二分查找，可以使用两次二分，也可以使用一次二分之后，将 target 加 1,继续进行二分。本质是一道二分查找第一个大于等于 target 的位置的题目。

## 39. combination

组合求和。这道题目要求根据提供的数字来组合出来和为 target 的数字组合，每个数字可以使用多次，但是最终的结果不能重复。

还是经典的组合问题，用回溯法进行解决。设计的关键有两点，一点是如何判断添加到 paths 的条件，这里就是 path 各个元素的和等于 target。另一个就是如何添加新的元素到 path，这里就是如果新的元素大于等于 path 的末尾元素，那么就可以添加进去，目的是确保没有重复的组合出现，因为 2，2, 3 和 2, 3, 2 是同一种组合。

## 40. combination-sum-2

组合求和 2. 这道题目还是根据提供的数字组合出来和为 target 的数字组合，但是备选数字有重复，而且每个位置的数字只能使用一次，最终结果也不能重复。

由于是组合，那么 2,2,3 和 2,3,2 是一个组合。

因此，还是经典的组合问题，使用回溯方法进行解决。需要注意的是，这里由于结果必须是不同的组合，因此最好先对数组进行排序，然后新添加的数字必须大于等于 path 最后一个数字。

又由于备选数字有重复，因此每次添加新数字的时候，如果前一个数字没有访问标记，并且当前数字等于前一个数字，那么说明这两个数字是位于同一个地位的相同数字，不能使用两次，因此跳过。同时如果当前数字已经被访问过，那么也不能重复访问，也直接跳过。

## 46. permutation

这道题目是排列组合所有可能的数字组合，但是数字只能使用一次，且数字之间都是互不相同的。这是典型的组合问题，可以使用回溯方法进行解决。注意每次插入新的数字的时候，要插入和 path 里面已有的数字的不同的数字

## 47. permutations-2

这道题目是排列组合题目的一个变形，不同之处在于数字之间可能有重复，每个位置的数字可以使用一次。生成的最后结果不能相互有重复。

注意每次添加新的数字的时候，前一个数字如果没有访问标记（visit）,并且当前数字等于前一个数字，说明这两个数字是位于同一个地位的相同数字，不能使用两次，因此直接跳过。同时，如果当前数字已经被标记（visit）,那么不重复访问，也直接跳过。

## 53. maximum subarray

有两种方法，一种是迭代的方法，就是分而治之。那么最大值就是左侧数组的最大值，右侧数组的最大值，以及从中间值向两边进行遍历，记录遍历过程中经过的最大值。那么最大值就是这三个最大值中的较大那个。另一种方法是比较巧妙，设置两个变量，分别是总的最大值，一个是当前遍历的临时最大值。然后用临时最大值加上当前遍历的数值，如果和小于当前数值，那么说明前面的累计是负面效应的，还不如只用当前遍历的数字，那么就更新临时最大值为当前便利的数值。如果和大于当前数值，那么说明前面的累计是有正面作用的，将临时最大值更新为新的和。同时，在每次更新临时最大值的时候都更新总的最大值，用 max 函数，记录这些更新历史过程中的总的最大值，即为最后结果。

## 62. unique-paths

典型的动态规划问题，要求是要寻找矩阵从左上角到右下角的所有可能的情况，那么某一点的情况是他左侧点的情况和上面点的情况的加和。注意最上边和最左边都是 1,然后遍历填满 dp 矩阵即可。

## 64. minimum-path-sum

典型的动态规划问题，由于是二维矩阵，建立一个二维 dp 数组比较合适。

递推关系式是到达 grid[i][j]的最短距离，取决于达到该点左侧和上侧最短距离之间的最小值，在加上该点的距离，然后 for 循环遍历一遍，填满 dp 数组就可以了。

## 67. add-binary

实现二进制加法。

首先将 a 确保为较长的字符串（使用 swap 交换）,然后设计一个 up 参数，如果两个数相加等于 0, 等于 1，等于 2,等于 3,分别进行不同的处理。

最后注意，如果 up 最后还是等于 1,那么就在前面还要加一个 1.

## 69. sqrt-x

可以使用数学解法进行球见，就是找到等式，转化为牛顿法，牛顿法的递推公式就是 Xn+1 = Xn - fx / fx'。 还有一种通用的解法，就是使用二分法

## 70. 爬梯子

典型的动态规划题目，递归和动态规划都是将原问题拆成多个子问题然后求解，他们之间最本质的区别是，动态规划保存了子问题的解，避免重复计算。

第 i 个楼梯可以从第 i-1 和 i-2 个楼梯再走一步到达，走到第 i 个楼梯的方法数为走到第 i-1 和第 i-2 个楼梯的方法数之和。`dp[i] = dp[i-1]+dp[i-2];`

## 72. edit-distance

这道题目是使用三种手段来将两个字符串变成一致，分别时删除，增加，修改。

使用 dp[i][j]用来表示字符串 1 的 0~i-1、字符串 2 的 0~j-1 的最小编辑距离；
我们可以知道边界情况：dp[i][0] = i、dp[0][j]=j；
同时对于两个字符串的子串，都能分为最后一个字符相等或者不等的情况：
如果 words[i-1] == words[j-1]：dp[i][j] = dp[i-1][j-1]；也就是说当前的编辑距离和位置 i 和 j 的字符无关；
如果 words[i-1] != words[j-1]：则存在三种可能的操作：

```
向 word1 插入：dp[i][j] = dp[i][j-1] + 1;
从 word1 删除：dp[i][j] = dp[i-1][j] + 1;
替换 word1 元素：dp[i][j] = dp[i-1][j-1] + 1;
```

## 75. sort colors

荷兰国旗问题，可以设置三个索引指针来进行解决，分别是左侧，当前，右侧

## 77. conbination

这道题目属于比较经典的组合问题，只不过这道题目的组合的长度是自定义可以变化的，仅仅需要修改添加到 paths 的条件即可。

## 78. subsets

递归，回溯法。要设置的变量 paths , path， index, nums(输入变量)

## 79. word search

这道是一个典型的回溯的题目，回溯是 DFS 的一种，但是有一个区别就是回溯在每次调用函数进行递归结束之后要把标记删除掉，这样下次其他递归还可以使用相应的对象。普通 DFS 是找一个可达性，而回溯包括一些匹配与排列组合的概念在里面，因此一个排列组合不对，要把标记清楚，可能其他排列组合就用上了。

还有要注意的一点就是，对于结果是 bool 类型，要把 bool 结果作为函数进行返回，多个返回之间进行取或，因为或操作如果有一个是 true 就整体是 true，后面的就不需要判断了，因此这样能加快函数进行，如果放在&参数里面进行返回，那么每一种情况都会进行，会白跑一些情况。

## 83. Remove Duplicates from Sorted List

这道题目是去除有序链表里面的重复数组，关键的步骤就是如果判断 head->val == head->next->val 那么就 head->next = head->next->next;

## 84. Maximal Rectangle

使用类似于 84 的解法，将原来的矩阵从上到下，具有连续 1 的累加起来，不连续的变为 0，这样没一个新产生的行使用 84 的解法计算，找到最大值。

## 87. scramble-string

可以使用递归或者动态规划的解法。（1）递归解法就是遍历不同的切割方法，但是每种情况不仅要左右对称比较，还要左右交叉比较。需要注意的是，要预先比较两个字符串字符是不是字母都一样，如果不一样肯定返回 false，这样可以加快速度，否则递归会超时。（2）DP 解法是设计三维的 dp 矩阵，三个维度分别是左串起始，右串起始，长度。递推方案是先解决所有长度为 1 的情况，遍历即可。然后对于长度高一层级的情况，都有低一层级的所有子情况推出来，具体递推公式就是左右对称比较和交叉比较，然后逐渐升高长度大小，最终得到最终结果。

动态规划的过程可以看作就情况的逆过程，递推是从最高维度向下分解，但是分解的子情况可能有很多是重复的，这时候会增加计算量，动态情况是找到里面的构建规律，然后逐渐推倒到我们想要的结果，是从最简单情况到复杂情况的过程，而递推是复杂情况渐分解到最简单情况的过程。

## 88. merge-sorted-array

双指针。从尾部开始遍历，逐渐把较大的数字往后放。注意结束的条件是两种：2 数组先到头，那么直接结束，因为 1 数组前面的数字还在原来的位置上。另一种情况是 1 数组先到头，那么就不用比较了，直接将剩下的 2 数组内容依次填好。

## 90. subsets 2

求子集，这道题目是根据备选的数字，找到所有可能组合的子集。注意备选的数字可能有重复。

这里由于备选的数字有重复，因此对于前一个数字没有访问标记，但是当前数字和前一个数字相同的，说明处于同一个位置，那么直接跳过。

由于组合不能有重复，因此新的数字要大于等于 path 的末尾数字，同时对于当前已经正在访问的数组，直接跳过。

## 91. Decode Ways

动态规划解法，使用一个数组 dp 表示记录的数据，列写出动态规划的递推方程，dp[i]=dp[i-1]+dp[i-2],不过这里的递推公式因为边界条件不一样而有所不同。

## 93. restore ip addresses

使用回溯法进行解决，但是要主要判断几个条件不能当作 ip 地址中间的段，分别是：要在 0 ～ 255 之间，不能有 010,001 这样的情况，段的大小要和 i 相等，否则可能在最终结果中加入了相同的东西。

还可以暴力一点，四个 for 循环便利所有可能情况，并对总数目等于 s 大小的去进一步判断，判断每一个段是不是符合那几个条件，如果符合就是最终结果。

## 95. unique binary search trees 2

分而治之思想，这里也可以使用记忆 hash 表或者记忆数组进行记录，本质上，使用记忆数组的递归是动态规划的一种。

## 101. symmetric-tree

使用递归的思想可以判断，判断右子树的左子树是不是相等，判断左子树的右子树是不是相等。

## 104. Maximum Depth of Binary Tree

计算树的高度，使用递归的思想可以完成。

## 110. Balanced Binary Tree

这道题目是判断是不是平衡二叉树，首先需要判断二叉树的高度，然后使用递归的思想判断是不是 BST,如果一个树是 BST，那么他的两个子树都是 BST，且两个子树的高度相差不超过 1。

## 111. Minimum Depth of Binary Tree

这道题目是计算根节点到叶子节点的最短路径，可以使用递归实现。

## 112. path sum

这道题目也可以使用递归进行判断，然后注意边界条件就可以。

## 121. Best Time to Buy and Sell Stock

设置两个变量一个是最大利润，一个是到当前之间为止，前面的最小买入价格，然后遍历，再每次遍历的时候，计算当前卖出价格和前面最小买入价格的差价

## 122. Best Time to Buy and Sell Stock 2

使用贪心的思想，只要后一天比前一天价格高，就会有利润，因此可以计算后一天比前一天收益大于 0 并累积

## 123. Best Time to Buy and Sell Stock III

这道是买股票的最佳时间系列问题中最难最复杂的一道，前面两道 Best Time to Buy and Sell Stock 和 Best Time to Buy and Sell Stock II 的思路都非常的简洁明了，算法也很简单。而这道是要求最多交易两次，找到最大利润，还是需要用动态规划 Dynamic Programming 来解，而这里我们需要两个递推公式来分别更新两个变量 local 和 global，参见网友 Code Ganker 的博客，我们其实可以求至少 k 次交易的最大利润，找到通解后可以设定 k = 2，即为本题的解答。我们定义 local[i][j]为在到达第 i 天时最多可进行 j 次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。然后我们定义 global[i][j]为在到达第 i 天时最多可进行 j 次交易的最大利润，此为全局最优。它们的递推式为：

local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)

global[i][j] = max(local[i][j], global[i - 1][j])

其中局部最优值是比较前一天并少交易一次的全局最优加上大于 0 的差值，和前一天的局部最优加上差值中取较大值，而全局最优比较局部最优和前一天的全局最优

---

这道题是 Best Time to Buy and Sell Stock 的扩展，现在我们最多可以进行两次交易。我们仍然使用动态规划来完成，事实上可以解决非常通用的情况，也就是最多进行 k 次交易的情况。
这里我们先解释最多可以进行 k 次交易的算法，然后最多进行两次我们只需要把 k 取成 2 即可。我们还是使用“局部最优和全局最优解法”。我们维护两种量，一个是当前到达第 i 天可以最多进行 j 次交易，最好的利润是多少（global[i][j]），另一个是当前到达第 i 天，最多可进行 j 次交易，并且最后一次交易在当天卖出的最好的利润是多少（local[i][j]）。下面我们来看递推式，全局的比较简单，

global[i][j]=max(local[i][j],global[i-1][j])，

也就是去当前局部最好的，和过往全局最好的中大的那个（因为最后一次交易如果包含当前天一定在局部最好的里面，否则一定在过往全局最优的里面）。对于局部变量的维护，递推式是

local[i][j]=max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff)，

也就是看两个量，第一个是全局到 i-1 天进行 j-1 次交易，然后加上今天的交易，如果今天是赚钱的话（也就是前面只要 j-1 次交易，最后一次交易取当前天），第二个量则是取 local 第 i-1 天 j 次交易，然后加上今天的差值（这里因为 local[i-1][j]比如包含第 i-1 天卖出的交易，所以现在变成第 i 天卖出，并不会增加交易次数，而且这里无论 diff 是不是大于 0 都一定要加上，因为否则就不满足
local[i][j]必须在最后一天卖出的条件了）。
上面的算法中对于天数需要一次扫描，而每次要对交易次数进行递推式求解，所以时间复杂度是 O(n\*k)，如果是最多进行两次交易，那么复杂度还是 O(n)。空间上只需要维护当天数据皆可以，所以是 O(k)，当 k=2，则是 O(1)。代码如下： 
————————————————
版权声明：本文为 CSDN 博主「Code_Ganker」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/linhuanmars/article/details/23236995

## 125. Valid Palindrome

双指针，两边开始便利，但是要注意边界条件：如果一个字母也没有

## 127. word ladder

BFS 查找，主要是要判断好只相差一个字母的两个字符串，如果只相差一个字母，就认为他们在图上是相邻的。

## 130. surrounded regions

先遍历四周，将遍历的区域全部变为第三个字母，比如‘T’，然后全部扫描一遍，将 O 变成 X,将 T 变成 O,这里遍历可以使用 BFS 或者 DFS，同时，主要到 DFS 可以使用递归来实现，写一个 help 函数 dfs，如果找到联通的点，就递归进去，直到最深处在回来，和 DFS 的本质思想是一样的

## 131. palindrome-partition

这道题目是根据给定的字符串，然后找到所有可能将字符串进行分割，使得分开的每一个字符串都是一个回文序列。

首先写一个工具函数，判断是个字符串是不是回文序列。

然后因为本质上还是组合问题，因此仍然使用回溯法。回溯 help 函数参数包括 paths，path，和起始 index。 从起始 index 起始遍历所有长度 length, 直到起始 index+length==s.size()，判断子字符串是不是回文序列。

如果是回文序列，就添加到 path 里面，并继续深入进行探索，但是起始 index 要增加 length。

最终判断是否添加到 paths，就是看看起始 index 是否达到了 s 的大小，说明已经探索到了末尾。

## 136. single number

使用异或进行处理，异或满足交换率和结合率，可以将两个相同大小的数字消掉。

## 137. single number 2

使用标记的 ones twos 变量进行每一个位的 1 的个数的记录，也可以推广到其他的问题， 比如三个四个重复的数字

## 139. word-break

这道题目是计算是否可以从备选的单词片段中组成目标单词。

dict 中的单词没有使用次数的限制，因此这是一个完全背包问题。

该问题涉及到字典中单词的使用顺序，也就是说物品必须按一定顺序放入背包中，例如下面的 dict 就不够组成字符串 "leetcode"：

["lee", "tc", "cod"]

求解顺序的完全背包问题时，对物品的迭代应该放在最里层，对背包的迭代放在外层，只有这样才能让物品按一定顺序放入背包中。

## 141. linked list cycle

使用双指针，一个指针每次移动一个节点，一个指针每次移动两个节点，如果存在环，那么这两个指针一定会相遇。如果快指针到达末尾，则说明没有环。

## 153. find minimum in rotated sorted array

二分查找，关键是找到二分查找的分割条件。

## 160. Intersection of Two Linked Lists

这道题目是确定两个链表的相交焦点。

可以使用循环两次的方法，当其中一个链表到达结尾之后，跳转到另一个链表。

如果有焦点，那么循环两次之后一定在焦点相遇，如果没有焦点，那么一定在链表的末尾相遇，而且都是 NULL;

## 167. two sum 2

这里是用双指针，不断判断当前两个数字的和与 target 的大小，然后移动相应的指针，指导两个指针相遇或者找到了两个匹配的数字

## 168. excel-sheet-column-title

这里就是注意将输入的数字减一进行处理，可以用递归也可以不用递归

## 169. majority-element

寻找数组中最大 majority，即数目超过 n/2 的个数的数字，这里可以使用很多种方法：（1）排序，返回中间值。（2）摩尔计数。即确定一个摩尔基数器，开始赋值为 0,当预选数字和当前遍历的数字相等的时候，计数器加一，当不相等的时候，计数器减一。如果计数器等于 0 了，那么赋值当前预选数字为当前遍历的数字。所有数字全部遍历完成后，预选数字即为 majority。（3）位操作。如果一个数字是 majority，那么每一个位上面的最大个数的位（0 或 1），组成的二进制数字就是 majority，可以遍历每一个位来寻找。（4）递归+分而治之。可以分左右两个子数组进行递归，返回的左右结果如果相同，那么就是 majority，如果不同，需要比较两个数字的个数谁大。（5）hash 表。可以按顺序遍历，存放到 hash 表中，如果相同就加一，直到个数超过 n/2 就返回。

## 171. excel-sheet-column-number

和 168 本质是一样的，就是注意字母的对应关系是：数字减一与相应字母对应

## 172. Factorial Trailing Zeroes

这道题目是计算 n 的阶乘的末尾 0 的数量。

尾部的 0 由 2 \* 5 得来，2 的数量明显多于 5 的数量，因此只要统计有多少个 5 即可。

对于一个数 N，它所包含 5 的个数为：N/5 + N/5^2 + N/5^3 + ...，其中 N/5 表示不大于 N 的数中 5 的倍数贡献一个 5，N/5^2 表示不大于 N 的数中 5^2 的倍数再贡献一个 5 ...。

## 188. Best Time to Buy and Sell Stock IV

这道题目是题目 123 的一般性推广，递推公式可以参考题目 123,但是需要注意的是，如果 k >= prices.size()/2,直接使用贪心算法计算即可（参考题目 122）。

## 190. reverse bits

可以按照单独一个位一个位进行处理，也可以按照四个位或更多的位一起进行处理，但是要提前计算好对应的映射表

## 191. numbers of 1 bits

可以使用 n&(n-1)， 它的作用是可以把 n 的二进制表示中的最低位为 1 的改为 0，每更改一次计数器+1，直到 n=0 停止

## 198. house-robber

动态规划经典题目，递推公式是 dp[i] = max(dp[i-1], dp[i-2]+ nums[i]) 也可以修改为长量的额外空间算法，使用 pre 和 pre_pre 两个变量代表 dp[i-1]和 dp[i-2],并不断更新这两个变量

## 200. number of islands

BFS 或 DFS 和题目 695 很像，这道题目不需要计数，只需要遍历完毕之后，在总数目上面加 1 即可，不需要求最大面积。只需要求岛的个数。

## 204. count-primes

这道题目是计算小于 n 的所有质数，质数是因子仅仅包括自己和 1 的数字。1 不是质数。

这道题目的思想是： 从 2 开始遍历到 n，先找到第一个质数 2，然后将其所有的倍数全部标记出来，然后到下一个质数 3，标记其所有倍数，一次类推，直到根号 n，此时数组中未被标记的数字就是质数。我们需要一个 n-1 长度的 bool 型数组来记录每个数字是否被标记， 这就是实现埃拉托斯特尼筛法，难度并不是很大。

## 206. Reverse Linked List

链表反转。

包括迭代方法和递归方法。迭代方法就是设置一个 pre 指针，然后不断插入到 pre->next。递归方法就是不断进行递归，每次递归返回一个头指针，注意保存临时变量。

重要注意的点就是算清楚 next 的链接关系。

## 213. house-robber2

这道题目也是典型的动态规划问题，可以得到递推公式就是当前所抢劫的户的最大钱数，等于到上上一个户的最大钱数加上当前户的钱数 与 抢劫到上一个户最大钱数的 的二者最大值。

这道题目多了一个要求，就是户是环型的，最后一个户和第一个户不能一起抢。那么可以将这个环问题拆开，我先只抢 0 ～ n-2，在抢 1 ～ n-1，这样第一个户和最后一个户不会被同时抢到，我们再取这两种情况的最大值就可以了。

## 215. kth largest element in an array

可以使用很多种方法：（1）使用 std 的函数 nth_element() 或者 partial_sort() (2) 使用小顶堆，维护一个 K 大小的大顶對，遍历数组，如果当前数字小于小顶堆的最小值，就添加进去，并删除堆顶元素。（3）使用大顶堆，将数组所有元素添加进去，然后不断弹出 K 次堆顶元素。（4）使用快速排序的思想，对数组进行分区。 对于使用堆的方法，可以使用 std 的 priority_queue 来构建，也可以使用 multiset()来构建，也可以使用自己构建的数组来自行构建堆结构。

## 216. combination-sum-3

组合求和，这道题目是根据 1-9 备选数字，选出特定组合求和等于 target 的组合，注意这个组合不能有重复的，而且数组 1-9 只能使用一次，而且长度等于 k 的组合。

这里组合不能有重复的，我们考虑后来新添加到 path 的数字必须大于 path 末尾的数字，这样就能保证数组之间没有重复的。

而且对于 path 能够进入 paths 的标准，如果 path_sum 大于 target,那么直接返回，如果 path 的长度达到了 k,那么判断 path_sum 如果等于 target，那么就可以进入 path_sum,如果不等于，那么就直接返回。

## 226. Invert Binary Tree

这道题目是翻转二叉树，使用递归的思想即可以。

## 234. Palindrome Linked List

这道题目判断链表是不是回文序列。
使用快慢指针，可以找到链表的最中间的位置，一个指针从头开始，一个指针从中间开始， 然后可以判断链表两半部分是不是相等。

## 238. Product of Array Except Self

这道题给定我们一个数组，让我们返回一个新数组，对于每一个位置上的数是其他位置上数的乘积，并且限定了时间复杂度 O(n)，并且不让我们用除法。如果让用除法的话，那这道题就应该属于 Easy，因为可以先遍历一遍数组求出所有数字之积，然后除以对应位置的上的数字。但是这道题禁止我们使用除法，那么我们只能另辟蹊径。我们想，对于某一个数字，如果我们知道其前面所有数字的乘积，同时也知道后面所有的数乘积，那么二者相乘就是我们要的结果，所以我们只要分别创建出这两个数组即可，分别从数组的两个方向遍历就可以分别创建出乘积累积数组。

我们可以对上面的方法进行空间上的优化，由于最终的结果都是要乘到结果 res 中，所以可以不用单独的数组来保存乘积，而是直接累积到结果 res 中，我们先从前面遍历一遍，将乘积的累积存入结果 res 中，然后从后面开始遍历，用到一个临时变量 right，初始化为 1，然后每次不断累积，最终得到正确结果.

## 241. different ways to add parentheses

可以使用分而治之进行解决，改进一点是可以使用 hash 表记录一些映射，以时间换空间提高计算效率。本题就是按照计算符号将原来的子符串分为两边，两边分别调用原来函数递归得到结果。对于左右的结果，分别遍历交叉计算得到最终的结果。

## 278. first bad version

二分查找

## 279. perfect squares

动态规划。将原问题思考为最初始的简单问题的汇总，这里就是从 n=1 开始，逐渐增加 n,递推关系为 dp[i] = min(dp[i - j * j] + 1, dp[i]);也可以使用 BFS，思路就是假想有一个 graph，里面每个节点如果满足 i=j+squares 即代表二者相连（Node j is connected to node i via an edge if  
and only if either j = i + (a perfect square number) or i = j + (a perfect square number).）。使用广度优先便利即可以找到最短路径。

## 300. longest-increasing-subsquence

这道题目是求最长子序列。可以使用动态规划进行求解

设计一个数组 dp，dp[i]代表以 nums[i]结尾的最长子序列的长度，然后对于 nums[i],遍历前面的 nums[i](j < i), 如果 nums[i] > nums[j] ，就在 dp[j]上加 1, 说明 nums[j]可以添加到后面的序列中，统计最大值作为 dp[i],然后不断迭代更新。

## 303. range-sum-query-immutable

这道题目比较特殊，构造函数使用一次，子函数调用很多次，所以要求构造函数多做一些任务，子函数做的任务小一些。

这里题目的作用就是返回 i 到 j 之间的求和，那么在构造函数里面，就创建一个数组，数组 i 存储累计到 i 为止的所有元素的和。

子函数直接计算 j-i 就是 i 到 j 之间的和了。

## 309. Best Time to Buy and Sell Stock with Cooldown

这道题目计算股票的最大收益，但是添加了一个条件就是卖出后有一天的冷却期。

设计两个数组，分别是：

have[i],代表第 i 天手里持有股票时的最大收益。

nothave[i]，代表第 i 天手里没有股票是的最大收益。

递推关系式是：

```c++
have[i] = max(have[i-1], (i>=2 ? nothave[i-2] : 0) - prices[i]);
nothave[i] = max(nothave[i-1], have[i-1] + prices[i]);
```

第 i 天 have[i]说明手里有股票，如果没有操作，那么取决于 have[i-1],如果是当天买了，那么取决于 nothave[i-2] - prices[i]，因为有冷却期，取决于前天卖出的最大收益。

第 i 天 nothave[i]说明手里没有股票，如果没有操作，那么取决于 nothave[i-1]，如果当天是卖出，那么取决于 have[i-1]。

## 322. coin-change

这道题目是完全背包问题：想比于普通背包问题，也叫 01 背包问题（例如题目 416），二者区别在于：

> 1. 完全背包问题可以使用无限次物品
> 2. 01 背包问题只能使用一次物品

具体就是体现在循环队列是正序还是倒序列。

我知道，背包问题的递推公式如下：

```c
dp[i] = min(dp[i], dp[i-num]+1);
```

在进行循环遍历的样子如下：

完全背包：

```c
for(int num : coins){
    for(int i=num;i<=amount;i++){
        dp[i] = min(dp[i], dp[i-num]+1);
    }
}
```

01 背包：

```c
for(int num : coins){
    for(int i=amount;i>=num;i--){
        dp[i] = min(dp[i], dp[i-num]+1);
    }
}
```

为什么 01 背包要倒序呢，这是因为 01 背包必须物品只能使用一次，如果正序的话，比如 dp[3]更新了一次，说明使用了当前遍历的物品，那么后续遍历的时候，dp[8]可能用到了 dp[3],又更新一次，那么这个物品又被使用了一次，这是不符合 01 背包物品只能使用一次的规则的。因此倒序进行，先更新 dp[8],这时候使用的 dp[3]肯定是没有被更新过得，保证整个遍历的过程中，物品仅仅被使用一次。

那么对于完全背包问题，由于物品可以使用无限次，那么必须使用正序，倒序反而不合适。

## 326. Power of Three

这道题目是判断 n 是不是 3 的倍数。

一种巧妙的方法，利用对数的换底公式来做，高中学过的换底公式为 logab = logcb / logca，那么如果 n 是 3 的倍数，则 log3n 一定是整数，我们利用换底公式可以写为 log3n = log10n / log103，注意这里一定要用 10 为底数，不能用自然数或者 2 为底数，否则当 n=243 时会出错，原因请看这个帖子。现在问题就变成了判断 log10n / log103 是否为整数，在 c++中判断数字 a 是否为整数，我们可以用 a - int(a) == 0 来判断

## 328. odd even linked list

这道题给了我们一个链表，让我们分开奇偶节点，所有奇节点在前，偶节点在后。我们可以使用两个指针来做，pre 指向奇节点，cur 指向偶节点，然后把偶节点 cur 后面的那个奇节点提前到 pre 的后面，然后 pre 和 cur 各自前进一步，此时 cur 又指向偶节点，pre 指向当前奇节点的末尾，以此类推直至把所有的偶节点都提前了即可

## 343. integer-break

这道题目是将一个整数进行拆分，以计算拆分后的各部分积求得最大值。

这道题目一个技巧就是，拆分越多的 3,最终的积的最大。所以拆分求得 3 越多越好，再把剩下的部分乘进去。如果剩下的是>=5,那么继续拆分，如果是 4,那么就乘进去。

还可以用动态规划进行求解，任意一个数字 n，设计一个动态规划数组 dp，代表可以求得的最大积，逐步计算到 dp[n]

对于一个数字 i,可以遍历他其中的一个和因子 j,那么他的另外一部分就是 i-j.

如果不对 i-j 进行拆分，那么求积就是 j\*(i-j), 如果对 i-j 进行拆分，那么求积就是 j\*(dp[i-j]), 二者取最大就是最大积。

## 345. reverse vowels of a string

可以使用 hash 表存储元音字母，然后使用双指针从两边遍历，如果是元音，则交换。另一种方法是 find_last_of 与 find_first_of 函数，不使用 hash 表

## 347. top k frequent elements

使用 hashmap 储存每个数据出现的次数，然后可以使用大顶堆来选出 top k,也可以使用桶排序来计算，桶排序就是将相同出现次数的数字放在一个桶中，然后全部放进去之后，从后向前遍历桶

## 367. Valid Perfect Square

遍历从 2 到 n/2 的范围，检测是否 i\*i==num，如果检测大于 num，那么直接 false，如果等于 num，那么直接 true。

## 376. wiggle-subsequence

这道题目求最长摆动子序列。 动态规划方式进行解决，设计两个数组 up 和 down, 代表到 i 为止以上升沿和下降沿为止的摆动序列的最长长度。

如果 nums[i] > nums[i-1], 则上升沿数组更新（在 down[i-1]上加一），下降沿数组维持上一个不变。如果 nums[i] < nums[i-1], 则下降沿数组更新（在 up[i-1]上加一），上升沿数组维持上一个不变。

## 377. combination-sum-4

这是一道完全背包问题，里面的数字可以使用很多次，而且计算可以组成 target 的序列，顺序是有区别的，比如{1,2,1}和{1,1,2}是两个答案，这个可以使用动态规划来进行计算。

如果使用递归来进行计算会耗时很严重，因为它只需要计算个数，所以我们使用动态规划来解决。

经典的完全背包形式：

```c++
    dp[0] = 1;

    for(long i=1;i<=target;i++){
        for(long num : nums){
            if(i >= num){
                dp[i] += dp[i-num];
            }
        }
    }
```

## 392. is subsequence

遍历母数组，设置子数组遍历 index，如果可以匹配上，那么 index++，如果子数组可以遍历完全，那么代表是子串。

## 404. Sum of Left Leaves

这道题目是计算所有左叶子节点的总和，可以使用递归实现。

## 405. Convert a Number to Hexadecimal

对正数进行 16 进制转换，对负数以补码的形式进行 16 进制转换。

```c++
for(int i=0;num && i<8;i++){
    int item = num & 0x0f;
    if(item>=10){
        ans = map[item-10] + ans;
    }else{
        ans = to_string(item) + ans;
    }
    num = num >> 4;

}
```

使用位操作可以对正负数进行相同的操作。

## 406. queue reconstruction height

首先要确定好如何进行排序，要先安排个子高的同学，然后再去插入个子低的同学。所以排序方式就是先按照个子排序，对于个子相同的，按照第二个数字小的放在前面

## Arithmetic Slices

这道题目是求出数字序列可以拆分成为等差递增序列的个数。

设计一个 dp 数组，其含义是以 A[i]数字为结尾的等差序列的个数。其递推关系式是 dp[i] = dp[i-1] + 1

然后再遍历 dp 数组求和，就可以得到所有的个数了。

## 415. Add Strings

这道题目是字符串相加，和题目 67 很类似，套路是一样的。

## 416. Partition Equal Subset Sum

动态规划题目，题目要求是确定是否可以将一个序列划分为两个和相等的子序列。

本质上是求是否可以在一个序列中，寻求一个子集，使得和可以等于一个数字 target.

设计一个数组 dp, dp[i]代表是否可能组成 i. 当遍历到 nums[i]和目标 target = j 的时候，dp[j]是否是 true，取决于 dp[ j-nums[i] ]是否为 true, 同时，如果 dp[j] 已经等于 true，当然还要保持 true, 因此，递推关系式是： dp[j] = dp[j - nums[i] ] || dp[j]

这里需要特别注意的是，第二个 for 循环一定要从 target 遍历到 nums[i]，而不能反过来，想想为什么呢？因为如果从 nums[i] 遍历到 target 的话，假如 nums[i]=1 的话，那么 [1, target] 中所有的 dp 值都是 true，因为 dp[0] 是 true，dp[1] 会或上 dp[0]，为 true，dp[2] 会或上 dp[1]，为 true，依此类推，完全使的 dp 数组失效了。

## 417. pacific atlantic water flow

可以使用 BFS 或者 DFS 来进行遍历，遍历就是先从左上边缘进行，对于遍历到的点将 P 相应位置赋值为 TRUE，对于右下角的边缘进行遍历，遍历到的点 A 相应位置赋值为 TRUE，然后再从头遍历一变，如果 P 和 A 都是 true，那么就是均可以流入太平洋和大西洋的点。

## 435. non overlapping intervals

先对待排序的区间进行排序，然后比较两个区间的是否有重叠。根据每个区间的 start 来做升序排序，然后开始要查找重叠区间，判断方法是看如果前一个区间的 end 大于后一个区间的 start，那么一定是重复区间，此时结果 res 自增 1，我们需要删除一个，那么此时究竟该删哪一个呢，为了保证总体去掉的区间数最小，我们去掉那个 end 值较大的区间。具体并不是删掉，而是使用索引指针的形式。

## 437. path sum 3

这道题让我们求二叉树的路径的和等于一个给定值，说明了这条路径不必要从根节点开始，可以是中间的任意一段，而且二叉树的节点值也是有正有负。那么我们可以用递归来做，相当于先序遍历二叉树，对于每一个节点都有记录了一条从根节点到当前节点到路径，同时用一个变量 curSum 记录路径节点总和，然后我们看 curSum 和 sum 是否相等，相等的话结果 res 加 1，不等的话我们来继续查看子路径和有没有满足题意的，做法就是每次去掉一个节点，看路径和是否等于给定值，注意最后必须留一个节点，不能全去掉了，因为如果全去掉了，路径之和为 0，而如果给定值刚好为 0 的话就会有问题

## 445. Add Two Numbers II

这道题是之前那道 Add Two Numbers 的拓展，我们可以看到这道题的最高位在链表首位置，如果我们给链表翻转一下的话就跟之前的题目一样了，这里我们来看一些不修改链表顺序的方法。由于加法需要从最低位开始运算，而最低位在链表末尾，链表只能从前往后遍历，没法取到前面的元素，那怎么办呢？

我们可以利用栈来保存所有的元素，然后利用栈的后进先出的特点就可以从后往前取数字了，我们首先遍历两个链表，将所有数字分别压入两个栈 s1 和 s2 中。

然后遍历栈不为空，直到两个栈都为空，设计一个指针 pre，不断插入新的节点到 pre 指针后面。

## 451.sort character by frequency

hashmap 可以得到计数与元素的映射，然后可以使用桶排序或者堆排序来进行计算，看具体的题目要求来决定选择哪一种方法

## 452. minimum number of arrows to burst balloons

类似于计算重叠区间个数，注意在计算重叠区间的时候，要计算公共重叠区间来进行比较，这个区间是逐渐缩小的。

## 455. assign cookies

贪心算法，将两个数组首先进行排序，然后在逐个安排

## 462. Minimum Moves to Equal Array Elements II

这道题是之前那道 Minimum Moves to Equal Array Elements 的拓展，现在我们可以每次对任意一个数字加 1 或者减 1，让我们用最少的次数让数组所有值相等。一般来说这种题目是不能用暴力方法算出所有情况，因为 OJ 一般是不会答应的。那么这道题是否像上面一道题一样，有巧妙的方法呢？答案是肯定的。下面这种解法实际上利用了之前一道题 Best Meeting Point 的思想，是不感觉很 amazing，看似完全不相干的两道题，居然有着某种内部联系。我们首先给数组排序，那么我们最终需要变成的相等的数字就是中间的数，如果数组有奇数个，那么就是最中间的那个数字；如果是偶数个，那么就是中间两个数的区间中的任意一个数字。而两端的数字变成中间的一个数字需要的步数实际上就是两端数字的距离，讲到这里发现是不是就和这道题 Best Meeting Point 的思路是一样了。那么我们就两对两对的累加它们的差值就可以了

## 474. ones-and-zeros

这道题是一道典型的应用 DP 来解的题，如果我们看到这种求总数，而不是列出所有情况的题，十有八九都是用 DP 来解，重中之重就是在于找出递推式。如果你第一反应没有想到用 DP 来做，想得是用贪心算法来做，比如先给字符串数组排个序，让长度小的字符串在前面，然后遍历每个字符串，遇到 0 或者 1 就将对应的 m 和 n 的值减小，这种方法在有的时候是不对的，比如对于{"11", "01", "10"}，m=2，n=2 这个例子，我们将遍历完“11”的时候，把 1 用完了，那么对于后面两个字符串就没法处理了，而其实正确的答案是应该组成后面两个字符串才对。所以我们需要建立一个二维的 DP 数组，其中 dp[i][j]表示有 i 个 0 和 j 个 1 时能组成的最多字符串的个数，而对于当前遍历到的字符串，我们统计出其中 0 和 1 的个数为 zeros 和 ones，然后 dp[i - zeros][j - ones]表示当前的 i 和 j 减去 zeros 和 ones 之前能拼成字符串的个数，那么加上当前的 zeros 和 ones 就是当前 dp[i][j]可以达到的个数，我们跟其原有数值对比取较大值即可，所以递推式如下：

dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);

有了递推式，我们就可以很容易的写出代码

## 494. target-sum

可以将这组数看成两部分，P 和 N，其中 P 使用正号，N 使用负号，有以下推导：

```
sum(P) - sum(N) = target

sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)

2 \* sum(P) = target + sum(nums)
```

因此只要找到一个子集，令它们都取正号，并且和等于 (target + sum(nums))/2，就证明存在解。

这道题目本质上还是求一个序列里面子集等于 target，不过这里不是求是否存在，而是求有几个，和题目 416 很像。

主要就是 dp[i] = dp[i] + dp[ i-nums[j] ], 解释就是 dp[i]代表 target = i 的有几种组合法。

当前 dp[i]的个数，依赖于历史可以组成 dp[i]的个数，以及 dp[i-nums[j]]个数之和。

然后注意第二层遍历要倒序遍历。

## 504. base-7

这道题目是将一个数字转化为 7 进制。

核心的递推公式是：

```c++
    while (item) {
        ans = to_string(item % 7) + ans;
        item = item / 7;
    }
```

注意负数的处理和 0 的处理。

## 518. coin-change-2

这道题目是计算可以凑出目标钱数目的所有硬币组合，这是一个完全背包问题，本质和题目 322 是一样的。

就是递推公式不一样,该题目的递推公式为：

```
    dp[i] = dp[i] + dp[i - coin];

```

需要注意的是，这是完全背包，需要正序遍历。

同时 dp[0] = 1

## 524. Longest Word in Dictionary through Deleting

这个类似于比较一个字符串是不是另一个字符串的子字符串。遍历字典中的字符串，如果当前遍历的字符串是 s 的子字符串，那么就赋值给 ans，然后继续遍历，如果当前遍历的字符串大小小于 ans 或者等于 ans 大小，但是字典排序在 ans 后面，那么就跳过，继续便利。

## 540. single element in a sorted array

属于能够找到准确值的二分查找

## 543. Diameter of Binary Tree

这道题让我们求二叉树的直径，并告诉了我们直径就是两点之间的最远距离，根据题目中的例子也不难理解题意。我们再来仔细观察例子中的那两个最长路径[4,2,1,3] 和 [5,2,1,3]，我们转换一种角度来看，是不是其实就是根结点 1 的左右两个子树的深度之和呢。那么我们只要对每一个结点求出其左右子树深度之和，这个值作为一个候选值，然后再对左右子结点分别调用求直径对递归函数，这三个值相互比较，取最大的值更新结果 res，因为直径不一定会经过根结点，所以才要对左右子结点再分别算一次。为了减少重复计算，我们用哈希表建立每个结点和其深度之间的映射，这样某个结点的深度之前计算过了，就不用再次计算了

## 547. friend Circles

这道题目是查找联通区域的个数，可以使用 BFS 或者 DFS 来进行遍历，然后统计联通区域的个数即可。这道题目还有一种解法比较巧妙，就是 union find. 核心思想是设置一个数组 root,root 里面存储的是索引链接关系，开始给每一个对象的 root 索引都是自己，各个对象都是独立的，然后如果判断一个对象和另一个对象属于同一类，就把后者的 root 索引链接到前者。这样二者就变为了同一类，最后在总的类别数目上减一。

## 572. subtree-of-another-tree

这道题让我们求一个数是否是另一个树的子树，从题目中的第二个例子中可以看出，子树必须是从叶结点开始的，中间某个部分的不能算是子树，那么我们转换一下思路，是不是从 s 的某个结点开始，跟 t 的所有结构都一样，那么问题就转换成了判断两棵树是否相同，也就是 Same Tree 的问题了，这点想通了其实代码就很好写了，用递归来写十分的简洁，我们先从 s 的根结点开始，跟 t 比较，如果两棵树完全相同，那么返回 true，否则就分别对 s 的左子结点和右子结点调用递归再次来判断是否相同，只要有一个返回 true 了，就表示可以找得到

## 583. Delete Operation for Two Strings

这道题目是计算多少次删除，可以让两个字符串相等。

本质上这道题目是求最长公共子序列，和题目 1143 是一样的。

## 605. can place flowers

这里类似于确定连续 0 的个数 n，然后计算(n-1)/2 即为可以种花的个数，但是要注意，这个是假设两边均种花，如果是位于边界的花，需要单独进行处理。左边界的条件可以事先设置起始 count=1,右边界的话，因为最后遍历完成之后，如果右边界是连续的 0,那么右面连续的 0 还没有统计进去，再统计进去的可以使用 n/2

## 617. merge two binary Trees

这道题目是将两个树进行合并。可以使用递归的思路进行合并。

## 628. maximun-product-of-three-numbers

这道题博主刚开始看的时候，心想直接排序，然后最后三个数字相乘不就完了，心想不会这么 Easy 吧，果然被 OJ 无情打脸，没有考虑到负数和 0 的情况。这道题给了数组的范围，至少三个，那么如果是三个的话，就无所谓了，直接相乘返回即可，但是如果超过了 3 个，而且有负数存在的话，情况就可能不一样，我们来考虑几种情况，如果全是负数，三个负数相乘还是负数，为了让负数最大，那么其绝对值就该最小，而负数排序后绝对值小的都在末尾，所以是末尾三个数字相乘，这个跟全是正数的情况一样。那么重点在于前半段是负数，后半段是正数，那么最好的情况肯定是两个最小的负数相乘得到一个正数，然后跟一个最大的正数相乘，这样得到的肯定是最大的数，所以我们让前两个数相乘，再和数组的最后一个数字相乘，就可以得到这种情况下的最大的乘积。实际上我们并不用分情况讨论数组的正负，只要把这两种情况的乘积都算出来，比较二者取较大值，就能涵盖所有的情况，从而得到正确的结果，

## 633. sum of aqure numbers

这道题目和 two sum 2 很类似，都是在排序好的数组内寻找两个数字，只不过一个是和，一个是平方和，可以使用双指针来实现，但是要注意的是右指针的初始化可以直接初始化为 target 的根号值

## 650. 2 Keys Keyboard

这道题目关键是找出规律，

递推公式是 dp[i] = min(dp[i], dp[j] + i / j)

其中 i 是准备求的目标数字，j 是 i 的所有可以整除的因子。

## 665. non decreasing array

判断 i 是否小于 i-1，如果小于，那么就需要修改，但是具体要修改哪个呢，需要看情况而定，如果 i-2 不存在，那么直接修改 i-1,如果 i-2 小于 i，那么修改 i-1,如果 i-2 大于 i，那么修改 i

## 680. validPalindrome 2

双指针，首先正常判断是不是回文字符串，在出现两个字符不一致的情况下，继续判断里面的字符串是不是会问字符串，注意有交叉两种情况

## 687. Longest Univalue Path

这道题让我们求最长的相同值路径，跟之前那道 Count Univalue Subtrees 十分的类似，解法也很类似。对于这种树的路径问题，递归是不二之选。在递归函数中，我们首先对其左右子结点调用递归函数，得到其左右子树的最大相同值路径长度，下面就要来看当前结点和其左右子结点之间的关系了，如果其左子结点存在且和当前节点值相同，则 left 自增 1，否则 left 重置 0；同理，如果其右子结点存在且和当前节点值相同，则 right 自增 1，否则 right 重置 0。然后用 left+right 来更新结果 res。而调用当前节点值的函数只能返回 left 和 right 中的较大值，因为如果还要跟父节点组 path，就只能在左右子节点中选一条 path，当然选值大的那个了，什么意思呢，举个例子来说吧，比如下面的这棵二叉树：

```
      1
     / \
    4   5
   / \   \
  4   4   5
 /
4
```

若此时的 node 是只有两个结点的第二层的那个结点 4，那么分别对其左右子结点调用递归，会得到 left = 1, right = 0，因为此时要跟结点 4 组成 path，所以肯定挑左子结点（有两个 4 的那条边），那你会问为啥不能连上右子结点的那个 4，这整条长度为 3 的 path（left+right，此时的 left 和 right 已经分别自增 1 了，left=2，right=1）其实我们已经用来更新过结果 res 了。需要注意的是我们的递归函数 helper 返回值的意义，并不是经过某个结点的最长路径的长度，最长路径长度保存在了结果 res 中，不是返回值，返回的是以该结点为终点的最长路径长度，这样回溯的时候，我们还可以继续连上其父结点，比如若根结点也是 4 的话，那么回溯到根结点的时候，路径长度又可以增加了

## 695. max-area-of-island

这道题目类似于 1091 这道题目，不同之处在于这道题目仅有四个方向可以拓展。至于每一个子区域遍历一遍，可以使用 BFS 也可以使用 DFS。BFS 可以求出最短路径，而 DFS 对于求出可达性会更快一些。

## 714. Best Time to Buy and Sell Stock with Transaction Fee

这道题目和 309 带冷却期的股票交易很像，只是没有冷却期了，添加了每次的手续费。

还是设计两个数组 have[i]与 nothave[i].代表第 i 天手里有或没有股票的最大收益。

递推公式就是在每次卖出的时候加上手续费就可以了

```c++
have[i] = max(have[i-1], nothave[i-1] - prices[i]);
nothave[i] = max(nothave[i-1], have[i-1] + prices[i] - fee);
```

## 725. Split Linked List in Parts

这道题给我们一个链表和一个正数 k，让我们分割链表成 k 部分，尽可能的平均分割，如果结点不够了，就用空结点，比如例子 1 中的。如果无法平均分，那么多余的结点就按顺序放在子链表中，如例子 2 中所示。我们要知道每个部分结点的个数，才能将整个链表断开成子链表，所以我们首先要统计链表中结点的总个数，然后除以 k，得到的商 avg 就是能分成的部分个数，余数 ext 就是包含有多余的结点的子链表的个数。我们开始 for 循环，循环的结束条件是 i 小于 k 且 root 存在，要生成 k 个子链表，在循环中，先把头结点加入结果 res 中对应的位置，然后就要遍历该子链表的结点个数了，首先每个子链表都一定包含有 avg 个结点，这是之前除法得到的商，然后还要有没有多余结点，如果 i 小于 ext，就说明当前子链表还得有一个多余结点，然后我们将指针向后移动一个，

## 744. find smallest letter greater than target

二分查找法

## 763. partition label

构建一个 hash 表，记录每一个字母最后出现的位置，然后再遍历一边字符串，定义一个变量表示当前出现的字符的最右边的边界，如果当前索引等于当前出现字符的最右边边界，那么就认为可以切割了

## 1091. shortest path in binary matrix

BFS。注意要对八个可能方向都要添加进队列，可能会访问回以前遍历过的地方，那么就如果是更短的路径，就要更新，如果不是更短的路径，就不要更新。

## 1143. longest-common-subsequence

对于两个子序列 S1 和 S2，找出它们最长的公共子序列。

定义一个二维数组 dp 用来存储最长公共子序列的长度，其中 dp[i][j] 表示 S1 的前 i 个字符与 S2 的前 j 个字符最长公共子序列的长度。考虑 S1i 与 S2j 值是否相等，分为两种情况：

当 S1i==S2j 时，那么就能在 S1 的前 i-1 个字符与 S2 的前 j-1 个字符最长公共子序列的基础上再加上 S1i 这个值，最长公共子序列长度加 1，即 dp[i][j] = dp[i-1][j-1] + 1。
当 S1i != S2j 时，此时最长公共子序列为 S1 的前 i-1 个字符和 S2 的前 j 个字符最长公共子序列，或者 S1 的前 i 个字符和 S2 的前 j-1 个字符最长公共子序列，取它们的最大者，即 dp[i][j] = max{ dp[i-1][j], dp[i][j-1] }。
