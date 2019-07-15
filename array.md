<!-- TOC START min:1 max:3 link:true asterisk:false update:true -->
- [Java](#java)
  - [31.medium.next.permutation](#31mediumnextpermutation)
  - [33. Search in Rotated Sorted Array](#33-search-in-rotated-sorted-array)
  - [78. Subsets (medium)](#78-subsets-medium)
    - [Solution](#solution)
  - [79. Word Search (medium)](#79-word-search-medium)
    - [Solution](#solution-1)
<!-- TOC END -->


# Java

## 31.medium.next.permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be **in-place and use only constant extra memory.**

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
```
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
```



```Java
class Solution {
    public void nextPermutation(int[] nums) {
        int right_val = 0;
        int i, j;
        for (i = nums.length - 1; i >= 0; i --) {
            if (right_val > nums[i]) {
                break;
            } else {
                right_val = nums[i];
            }
        }
        if (i == -1) {
            reverse(nums, -1);
            return;
        }
        for (j = nums.length - 1; j >= i; j --) {
            if (nums[i] < nums[j]) {
                break;
            }
        }
        swap(nums, i, j);
        reverse(nums, i);
        return;
    }

    private void reverse(int[] nums, int i) {
        i = i + 1;
        int j = nums.length - 1;
        for (; i < j; i ++, j --) {
            swap(nums, i, j);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        return;
    }
}
```

## 33. Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some **pivot** unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime **complexity must be in the order of O(log n).**

**Example 1:**
```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```
**Example 2:**
```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

```java
class Solution {
    public int search(int[] nums, int target) {
        return binarySearch(nums, target, 0, nums.length - 1);
    }

    private int binarySearch(int[] nums, int target, int start, int end) {
        if (start > end) {
            return -1;
        }
        if (start == end) {
            if (nums[start] == target) {
                return start;
            } else {
                return -1;
            }
        }
        int midIndex = (int)Math.floor((start + end) / 2.0);
        if (nums[midIndex] >= nums[start]) {
            if (target <= nums[midIndex] && target >= nums[start]) {
                return binarySearch(nums, target, start, midIndex);
            } else if (target > nums[midIndex] || target <= nums[end]){
                return binarySearch(nums, target, midIndex+1, end);
            } else {
                return -1;
            }
        } else {
            if (target <= nums[midIndex] || target >= nums[start]) {
                return binarySearch(nums, target, start, midIndex);
            } else if (target > nums[midIndex] && target <= nums[end]){
                return binarySearch(nums, target, midIndex+1, end);
            } else {
                return -1;
            }
        }
    }
}
```

## 78. Subsets (medium)

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

**Example:**
```
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```

### Solution

```Java
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> rst = new ArrayList<>();
        int size = 1 << nums.length;
        for (int i = 0; i < size; i ++ ) {
            List<Integer> subset = new ArrayList<>();
            for (int j = 0; j < nums.length; j ++ ) {
                if (((i >> j) & 1) == 1)
                    subset.add(nums[j]);
            }
            rst.add(subset);
        }
        return rst;
    }
}
```

## 79. Word Search (medium)

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

**Example:**
```
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
```

### Solution

We could solve this by DFS.
