## 46. Permutations (medium)

Given a collection of distinct integers, return all possible permutations.

**Example:**
```
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

### Solution

- Arrays.fill(int[] a, 1);
- ArrayList.size(), int[] a.length.

```Java
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> permutations = new ArrayList<>();
        List<Integer> permutation = new ArrayList<>();
        int[] count = new int[nums.length];
        Arrays.fill(count, 1);
        permute(nums, count, permutation, 0, permutations);
        return permutations;
    }

    private void permute(int[] nums, int[] count, List<Integer> permutation, int length, List<List<Integer>> permutations) {
        if (length == nums.length) {
            permutations.add(new ArrayList<Integer>(permutation));
            return;
        }

        for (int i = 0; i < count.length; i++) {
            if (count[i] != 0) {
                count[i] --;
                permutation.add(nums[i]);
                permute(nums, count, permutation, length+1, permutations);
                permutation.remove(permutation.size() - 1);
                count[i] ++;
            }
        }
    }
}
```


## 47. Permutations II (medium)

Given a collection of distinct integers, return all unique possible permutations.

### Solution ???

```Java
```

## 48. Rotate Image (medium)

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

**Example 1:**
```
Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
```

### Solution

```Java
class Solution {
    public void rotate(int[][] matrix) {
        int start = 0;
        int end = matrix.length - 1;
        int tmp;
        while (start < end) {
            for (int i = start; i < end; i ++ ) {
                tmp = matrix[end - i + start][start];
                matrix[end - i + start][start] = matrix[end][end - i + start];
                matrix[end][end - i + start] = matrix[i][end];
                matrix[i][end] = matrix[start][i];
                matrix[start][i] = tmp;
            }
            start ++ ;
            end -- ;
        }
    }
}
```

## 364. Nested List Weight Sum II (medium)

Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

**Example 1:**
```
Input: [[1,1],2,[1,1]]
Output: 8
Explanation: Four 1's at depth 1, one 2 at depth 2.
```
**Example 2:**
```
Input: [1,[4,[6]]]
Output: 17
Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17.
```

```java
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    public int depthSumInverse(List<NestedInteger> nestedList) {
        int res = 0;
        int cum = 0;
        List<NestedInteger> list = new ArrayList<>();
        while (true) {
            for (NestedInteger i : nestedList) {
                if (i.isInteger()) {
                    cum+=i.getInteger();
                } else {
                    list.addAll(i.getList());
                }
            }
            res += cum;
            if (list.size() == 0) {
                return res;
            } else {
                nestedList = list;
                list = new ArrayList<>();
            }
        }

    }
}
```

##
