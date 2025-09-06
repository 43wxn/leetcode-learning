# leetcode-learning
leetcode学习算法的代码
# 滑动窗口
##  定长
##  不定长
1.对于从两边取数的操作，问最少/最多次操作才能达到要求，可以考虑正难则反，则反过来去求连续的子序列的最多/最少次数。

# 二分查找
    不管情况都有开区间，半开半闭，闭区间三种写法

    1. 开区间
        初始化：left=-1,right=nums.size()
        循环条件：left+1<right
        二分：left=mid，right=mid
    2. 半开半闭
        初始化：left=0，right=nums.size().....左闭右开....
        循环条件：left<right
        二分：left=mid+1，right=mid
    3.闭区间
        初始化：left=0，right=nums.size()-1
        循环条件：left<=right
        二分：left=mid+1，right=mid-1
    对于最后return的变量 需要根据循环不变式来决定，比如开区间时，
    若 if(nums[left]<target) else......那么维护left及其左边全是小于target，right及其右边可能大于等于target，则返回right。

    例题：查找左边界;精准查找


    python 中二分查找的模块是bisect
    Python的 bisect 函数对比：
        bisect_left(arr, x): 第一个 >= x 的元素位置
        bisect_right(arr, x): 第一个 > x 的元素位置
        bisect(arr, x): 同 bisect_right

    C++中二分查找的函数 包含在algorithm头文件中 
    C++的二分查找函数：
        lower_bound(first, last, value): 第一个 >= value 的元素迭代器
        upper_bound(first, last, value): 第一个 > value 的元素迭代器
        binary_search(first, last, value): 检查value是否存在
    