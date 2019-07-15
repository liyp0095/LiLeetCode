<!-- TOC START min:1 max:3 link:true asterisk:false update:true -->
- [Java](#java)
  - [31.medium.next.permutation](#31mediumnextpermutation)
  - [33. Search in Rotated Sorted Array](#33-search-in-rotated-sorted-array)
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
