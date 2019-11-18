# leetcode

---

- [二分搜索法总结](./binary_search.md)

---

[TOC]

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

## 34. find first ans last position of element in sorted array

二分查找，可以使用两次二分，也可以使用一次二分之后，将 target 加 1,继续进行二分。本质是一道二分查找第一个大于等于 target 的位置的题目。

## 53. maximum subarray

有两种方法，一种是迭代的方法，就是分而治之。那么最大值就是左侧数组的最大值，右侧数组的最大值，以及从中间值向两边进行遍历，记录遍历过程中经过的最大值。那么最大值就是这三个最大值中的较大那个。另一种方法是比较巧妙，设置两个变量，分别是总的最大值，一个是当前遍历的临时最大值。然后用临时最大值加上当前遍历的数值，如果和小于当前数值，那么说明前面的累计是负面效应的，还不如只用当前遍历的数字，那么就更新临时最大值为当前便利的数值。如果和大于当前数值，那么说明前面的累计是有正面作用的，将临时最大值更新为新的和。同时，在每次更新临时最大值的时候都更新总的最大值，用 max 函数，记录这些更新历史过程中的总的最大值，即为最后结果。

## 69. sqrt-x

可以使用数学解法进行球见，就是找到等式，转化为牛顿法，牛顿法的递推公式就是 Xn+1 = Xn - fx / fx'。 还有一种通用的解法，就是使用二分法

## 75. sort colors

荷兰国旗问题，可以设置三个索引指针来进行解决，分别是左侧，当前，右侧

## 78. subsets

递归，回溯法。要设置的变量 paths , path， index, nums(输入变量)

## 84. Maximal Rectangle

使用类似于 84 的解法，将原来的矩阵从上到下，具有连续 1 的累加起来，不连续的变为 0，这样没一个新产生的行使用 84 的解法计算，找到最大值。

## 87. scramble-string

可以使用递归或者动态规划的解法。（1）递归解法就是遍历不同的切割方法，但是每种情况不仅要左右对称比较，还要左右交叉比较。需要注意的是，要预先比较两个字符串字符是不是字母都一样，如果不一样肯定返回 false，这样可以加快速度，否则递归会超时。（2）DP 解法是设计三维的 dp 矩阵，三个维度分别是左串起始，右串起始，长度。递推方案是先解决所有长度为 1 的情况，遍历即可。然后对于长度高一层级的情况，都有低一层级的所有子情况推出来，具体递推公式就是左右对称比较和交叉比较，然后逐渐升高长度大小，最终得到最终结果。

动态规划的过程可以看作就情况的逆过程，递推是从最高维度向下分解，但是分解的子情况可能有很多是重复的，这时候会增加计算量，动态情况是找到里面的构建规律，然后逐渐推倒到我们想要的结果，是从最简单情况到复杂情况的过程，而递推是复杂情况渐分解到最简单情况的过程。

## 88. merge-sorted-array

双指针。从尾部开始遍历，逐渐把较大的数字往后放。注意结束的条件是两种：2 数组先到头，那么直接结束，因为 1 数组前面的数字还在原来的位置上。另一种情况是 1 数组先到头，那么就不用比较了，直接将剩下的 2 数组内容依次填好。

## 90. subsets 2

和 78 类似，修改的地方在于如果 nums 当前变量和前一个变量相等，则 paths 不添加这个 path

## 91. Decode Ways

动态规划解法，使用一个数组 dp 表示记录的数据，列写出动态规划的递推方程，dp[i]=dp[i-1]+dp[i-2],不过这里的递推公式因为边界条件不一样而有所不同。

## 95. unique binary search trees 2

分而治之思想，这里也可以使用记忆 hash 表或者记忆数组进行记录，本质上，使用记忆数组的递归是动态规划的一种。

## 121. Best Time to Buy and Sell Stock

设置两个变量一个是最大利润，一个是到当前之间为止，前面的最小买入价格，然后遍历，再每次遍历的时候，计算当前卖出价格和前面最小买入价格的差价

## 122. Best Time to Buy and Sell Stock 2

使用贪心的思想，只要后一天比前一天价格高，就会有利润，因此可以计算后一天比前一天收益大于 0 并累积

## 125. Valid Palindrome

双指针，两边开始便利，但是要注意边界条件：如果一个字母也没有

## 136. single number

使用异或进行处理，异或满足交换率和结合率，可以将两个相同大小的数字消掉。

## 137. single number 2

使用标记的 ones twos 变量进行每一个位的 1 的个数的记录，也可以推广到其他的问题， 比如三个四个重复的数字

## 141. linked list cycle

使用双指针，一个指针每次移动一个节点，一个指针每次移动两个节点，如果存在环，那么这两个指针一定会相遇。如果快指针到达末尾，则说明没有环。

## 153. find minimum in rotated sorted array

二分查找，关键是找到二分查找的分割条件。

## 167. two sum 2

这里是用双指针，不断判断当前两个数字的和与 target 的大小，然后移动相应的指针，指导两个指针相遇或者找到了两个匹配的数字

## 168. excel-sheet-column-title

这里就是注意将输入的数字减一进行处理，可以用递归也可以不用递归

## 169. majority-element

寻找数组中最大 majority，即数目超过 n/2 的个数的数字，这里可以使用很多种方法：（1）排序，返回中间值。（2）摩尔计数。即确定一个摩尔基数器，开始赋值为 0,当预选数字和当前遍历的数字相等的时候，计数器加一，当不相等的时候，计数器减一。如果计数器等于 0 了，那么赋值当前预选数字为当前遍历的数字。所有数字全部遍历完成后，预选数字即为 majority。（3）位操作。如果一个数字是 majority，那么每一个位上面的最大个数的位（0 或 1），组成的二进制数字就是 majority，可以遍历每一个位来寻找。（4）递归+分而治之。可以分左右两个子数组进行递归，返回的左右结果如果相同，那么就是 majority，如果不同，需要比较两个数字的个数谁大。（5）hash 表。可以按顺序遍历，存放到 hash 表中，如果相同就加一，直到个数超过 n/2 就返回。

## 171. excel-sheet-column-number

和 168 本质是一样的，就是注意字母的对应关系是：数字减一与相应字母对应

## 190. reverse bits

可以按照单独一个位一个位进行处理，也可以按照四个位或更多的位一起进行处理，但是要提前计算好对应的映射表

## 191. numbers of 1 bits

可以使用 n&(n-1)， 它的作用是可以把 n 的二进制表示中的最低位为 1 的改为 0，每更改一次计数器+1，直到 n=0 停止

## 198. house-robber

动态规划经典题目，递推公式是 dp[i] = max(dp[i-1], dp[i-2]+ nums[i]) 也可以修改为长量的额外空间算法，使用 pre 和 pre_pre 两个变量代表 dp[i-1]和 dp[i-2],并不断更新这两个变量

## 215. kth largest element in an array

可以使用很多种方法：（1）使用 std 的函数 nth_element() 或者 partial_sort() (2) 使用小顶堆，维护一个 K 大小的大顶對，遍历数组，如果当前数字小于小顶堆的最小值，就添加进去，并删除堆顶元素。（3）使用大顶堆，将数组所有元素添加进去，然后不断弹出 K 次堆顶元素。（4）使用快速排序的思想，对数组进行分区。 对于使用堆的方法，可以使用 std 的 priority_queue 来构建，也可以使用 multiset()来构建，也可以使用自己构建的数组来自行构建堆结构。

## 241. different ways to add parentheses

可以使用分而治之进行解决，改进一点是可以使用 hash 表记录一些映射，以时间换空间提高计算效率。本题就是按照计算符号将原来的子符串分为两边，两边分别调用原来函数递归得到结果。对于左右的结果，分别遍历交叉计算得到最终的结果。

## 278. first bad version

二分查找

## 345. reverse vowels of a string

可以使用 hash 表存储元音字母，然后使用双指针从两边遍历，如果是元音，则交换。另一种方法是 find_last_of 与 find_first_of 函数，不使用 hash 表

## 347. top k frequent elements

使用 hashmap 储存每个数据出现的次数，然后可以使用大顶堆来选出 top k,也可以使用桶排序来计算，桶排序就是将相同出现次数的数字放在一个桶中，然后全部放进去之后，从后向前遍历桶

## 392. is subsequence

遍历母数组，设置子数组遍历 index，如果可以匹配上，那么 index++，如果子数组可以遍历完全，那么代表是子串。

## 406. queue reconstruction height

首先要确定好如何进行排序，要先安排个子高的同学，然后再去插入个子低的同学。所以排序方式就是先按照个子排序，对于个子相同的，按照第二个数字小的放在前面

## 435. non overlapping intervals

先对待排序的区间进行排序，然后比较两个区间的是否有重叠。根据每个区间的 start 来做升序排序，然后开始要查找重叠区间，判断方法是看如果前一个区间的 end 大于后一个区间的 start，那么一定是重复区间，此时结果 res 自增 1，我们需要删除一个，那么此时究竟该删哪一个呢，为了保证总体去掉的区间数最小，我们去掉那个 end 值较大的区间。具体并不是删掉，而是使用索引指针的形式。

## 451.sort character by frequency

hashmap 可以得到计数与元素的映射，然后可以使用桶排序或者堆排序来进行计算，看具体的题目要求来决定选择哪一种方法

## 452. minimum number of arrows to burst balloons

类似于计算重叠区间个数，注意在计算重叠区间的时候，要计算公共重叠区间来进行比较，这个区间是逐渐缩小的。

## 455. assign cookies

贪心算法，将两个数组首先进行排序，然后在逐个安排

## 524. Longest Word in Dictionary through Deleting

这个类似于比较一个字符串是不是另一个字符串的子字符串。遍历字典中的字符串，如果当前遍历的字符串是 s 的子字符串，那么就赋值给 ans，然后继续遍历，如果当前遍历的字符串大小小于 ans 或者等于 ans 大小，但是字典排序在 ans 后面，那么就跳过，继续便利。

## 540. single element in a sorted array

属于能够找到准确值的二分查找

## 605. can place flowers

这里类似于确定连续 0 的个数 n，然后计算(n-1)/2 即为可以种花的个数，但是要注意，这个是假设两边均种花，如果是位于边界的花，需要单独进行处理。左边界的条件可以事先设置起始 count=1,右边界的话，因为最后遍历完成之后，如果右边界是连续的 0,那么右面连续的 0 还没有统计进去，再统计进去的可以使用 n/2

## 633. sum of aqure numbers

这道题目和 two sum 2 很类似，都是在排序好的数组内寻找两个数字，只不过一个是和，一个是平方和，可以使用双指针来实现，但是要注意的是右指针的初始化可以直接初始化为 target 的根号值

## 665. non decreasing array

判断 i 是否小于 i-1，如果小于，那么就需要修改，但是具体要修改哪个呢，需要看情况而定，如果 i-2 不存在，那么直接修改 i-1,如果 i-2 小于 i，那么修改 i-1,如果 i-2 大于 i，那么修改 i

## 680. validPalindrome 2

双指针，首先正常判断是不是回文字符串，在出现两个字符不一致的情况下，继续判断里面的字符串是不是会问字符串，注意有交叉两种情况

## 744. find smallest letter greater than target

二分查找法

## 763. partition label

构建一个 hash 表，记录每一个字母最后出现的位置，然后再遍历一边字符串，定义一个变量表示当前出现的字符的最右边的边界，如果当前索引等于当前出现字符的最右边边界，那么就认为可以切割了
