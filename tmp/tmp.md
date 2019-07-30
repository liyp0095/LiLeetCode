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
