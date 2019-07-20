## 112. Path Sum

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

**Example:**
```
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
```

### Solution

```Java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) {
            return false;
        }
        if (root.left == null && root.right != null) {
            return hasPathSum(root.right, sum-root.val);
        }
        if (root.left != null && root.right == null) {
            return hasPathSum(root.left, sum-root.val);
        }
        if (root.left != null && root.right != null) {
            return hasPathSum(root.left, sum-root.val) || hasPathSum(root.right, sum-root.val);
        }
        if (root.left == null && root.right == null) {
            if (root.val == sum)
                return true;
            else
                return false;
        }
        return false;
    }
}
```

## 113. Path Sum II (medium)

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

**Example:**
```
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
```

### Solution

- ArrayList 作为参数不是深拷贝。

```Java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> rst = new ArrayList<>();
        findPath(rst, root, sum, new ArrayList<Integer>());
        return rst;
    }

    private void findPath(List<List<Integer>> rst, TreeNode root, int sum, List<Integer> path) {
        if (root == null) {
            return;
        } else if (root.left == null && root.right == null) {
            if (root.val == sum) {
                path.add(root.val);
                rst.add(new ArrayList<>(path));
                path.remove(path.size()-1);
            }
        } else if (root.left == null) {
            path.add(root.val);
            findPath(rst, root.right, sum-root.val, path);
            path.remove(path.size()-1);
        } else if (root.right == null) {
            path.add(root.val);
            findPath(rst, root.left, sum-root.val, path);
            path.remove(path.size()-1);
        } else {
            path.add(root.val);
            findPath(rst, root.left, sum-root.val, path);
            findPath(rst, root.right, sum-root.val, path);
            path.remove(path.size()-1);
        }
    }
}
```
