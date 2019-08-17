<!-- TOC START min:1 max:3 link:true asterisk:false update:true -->
- [Java](#java)
  - [31.medium.next.permutation](#31mediumnextpermutation)
    - [Solution](#solution)
  - [33. Search in Rotated Sorted Array](#33-search-in-rotated-sorted-array)
    - [Solution](#solution-1)
  - [34. Find First and Last Position of Element in Sorted Array (medium)](#34-find-first-and-last-position-of-element-in-sorted-array-medium)
    - [Solution](#solution-2)
  - [11. Container With Most Water (medium)](#11-container-with-most-water-medium)
    - [Solution](#solution-3)
  - [42. Trapping Rain Water (hard)](#42-trapping-rain-water-hard)
    - [Solution](#solution-4)
  - [78. Subsets (medium)](#78-subsets-medium)
    - [Solution](#solution-5)
  - [79. Word Search (medium)](#79-word-search-medium)
    - [Solution ??](#solution-)
  - [152. Maximum Product Subarray (medium)](#152-maximum-product-subarray-medium)
    - [Solution ??](#solution--1)
  - [209. Minimum Size Subarray Sum (medium)](#209-minimum-size-subarray-sum-medium)
    - [Solution ??](#solution--2)
  - [937. Reorder Log Files](#937-reorder-log-files)
  - [Solution](#solution-6)
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

### Solution

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
### Solution
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

## 34. Find First and Last Position of Element in Sorted Array (medium)

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

**Example 1:**
```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```
**Example 2:**
```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```
### Solution

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int middle = 0;
        int[] rst = {-1, -1};

        while (left <= right) {
            middle = Math.round((left + right) / 2);
            if (target > nums[middle]) {
                left = middle + 1;
            } else if (target < nums[middle]) {
                right = middle - 1;
            } else {
                while (middle > 0 && nums[middle-1] == nums[middle]) {
                    middle -= 1;
                }
                rst[0] = middle;
                while (middle < nums.length - 1 && nums[middle+1] == nums[middle]) {
                    middle += 1;
                }
                rst[1] = middle;
                return rst;
            }
        }
        return rst;
    }
}
```


## 11. Container With Most Water (medium)

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

**example**

```
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
```

### Solution
- 为什么从两边向中间走可以遍历所有情况？

```Java
class Solution {
    public int maxArea(int[] height) {
        int waterLevel = 0;
        int rst = 0;

        for (int i = 0, j = height.length - 1; i < j;) {
            waterLevel = Math.min(height[i], height[j]);
            rst = Math.max((j-i) * waterLevel, rst);
            // System.out.println(rst);
            if (height[i] > height[j]) {
                j --;
            } else {
                i ++;
            }
        }

        return rst;
    }
}
```

## 42. Trapping Rain Water (hard)

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

**Example:**

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

### Solution

```Java
class Solution {
    public int trap(int[] height) {
        int waterLevel = 0;
        int rst = 0;

        for (int i = 0, j = height.length - 1; i < j;) {
            waterLevel = Math.max(waterLevel, Math.min(height[i], height[j]));
            // System.out.println(rst);
            if (height[i] > height[j]) {
                rst += Math.max(waterLevel - height[j], 0);
                j --;
            } else {
                rst += Math.max(waterLevel - height[i], 0);
                i ++;
            }
        }

        return rst;
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

### Solution ??

We could solve this by DFS.

## 152. Maximum Product Subarray (medium)

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

**Example 1:**
```
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```
**Example 2:**
```
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```

### Solution ??



## 209. Minimum Size Subarray Sum (medium)

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

**Example:**
```
Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
```
**Follow up:**

If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

### Solution ??

## 937. Reorder Log Files

You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

- Each word after the identifier will consist only of lowercase letters, or;
- Each word after the identifier will consist only of digits.

We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

**Example 1:**
```
Input: ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
```

## Solution

```Java

```
