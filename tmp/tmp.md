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
