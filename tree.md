<!-- TOC START min:1 max:3 link:true asterisk:false update:true -->
- [Tree with Java](#tree-with-java)
  - [94. Binary Tree Inorder Traversal](#94-binary-tree-inorder-traversal)
  - [95. Unique Binary Search Trees II](#95-unique-binary-search-trees-ii)
  - [96. Unique Binary Search Trees](#96-unique-binary-search-trees)
  - [98. Validate Binary Search Tree](#98-validate-binary-search-tree)
  - [99. Recover Binary Search Tree](#99-recover-binary-search-tree)
    - [Solution](#solution)
  - [100. Same Tree](#100-same-tree)
  - [101. Symmetric Tree](#101-symmetric-tree)
  - [102. Binary Tree level Order Traversal (medium)](#102-binary-tree-level-order-traversal-medium)
  - [116. Populating Next Right Pointers in Each Node](#116-populating-next-right-pointers-in-each-node)
  - [117. Populating Next Right Pointers in Each Node II](#117-populating-next-right-pointers-in-each-node-ii)
<!-- TOC END -->



# Tree with Java

## 94. Binary Tree Inorder Traversal

Given a binary tree, return the **inorder traversal** of its nodes' values.

**Example:**
```
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
```

- ArrayList add element, list and ?
- Stack push pop peek search and empty?

```Java
arraylist1.add("AL1: E1");
arraylist1.add("AL1: E2");
arraylist1.add("AL1: E3");

al.addAll(arraylist1);
```
Recursive solution :

```java
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
    public List<Integer> inorderTraversal(TreeNode root) {
        return inorderTraversalRecursively(root);
    }

    private List<Integer> inorderTraversalRecursively(TreeNode root) {
        if (root == null) {
            return new ArrayList<Integer>();
        }

        List<Integer> rst = new ArrayList<Integer>();
        rst.addAll(inorderTraversalRecursively(root.left));
        rst.add(root.val);
        rst.addAll(inorderTraversalRecursively(root.right));
        return rst;
    }
}
//Runtime: 1 ms, faster than 54.15% of Java online submissions for Binary Tree Inorder Traversal.
//Memory Usage: 34.7 MB, less than 99.99% of Java online submissions for Binary Tree Inorder Traversal.
```

iterative solution :

```java
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
    public List<Integer> inorderTraversal(TreeNode root) {
        Stack<TreeNode> s = new Stack<TreeNode>();
        List<Integer> rst = new ArrayList<Integer>();
        while (!s.empty() || root != null) {
            while (root != null) {
                s.push(root);
                root = root.left;
            }
            root = s.pop();
            rst.add(root.val);
            root = root.right;
        }
        return rst;
    }
}

// Runtime: 1 ms, faster than 54.15% of Java online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 34.9 MB, less than 99.99% of Java online submissions for Binary Tree Inorder Traversal.
```


## 95. Unique Binary Search Trees II

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

**Example:**
```
Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

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
    public List<TreeNode> generateTrees(int n) {
        if (n < 1) {
            return new ArrayList<TreeNode>();
        }
        return generateTreesRecursively(1, n);
    }

    private List<TreeNode> generateTreesRecursively(int a, int b) {
        List<TreeNode> rst = new ArrayList<TreeNode>();
        if (a > b) {
            rst.add(null);
            return rst;
        }

        for (int root = a; root <= b; root ++ ) {
            List<TreeNode> leftTreeList = generateTreesRecursively(a, root - 1);
            List<TreeNode> rightTreeList = generateTreesRecursively(root + 1, b);
            for (TreeNode l : leftTreeList) {
                for (TreeNode r : rightTreeList) {
                    TreeNode treeRoot = new TreeNode(root);
                    treeRoot.left = l;
                    treeRoot.right = r;
                    rst.add(treeRoot);
                }
            }
        }

        return rst;
    }
}
```


## 96. Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

**Example:**
```
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

recursive solution **time limit exceeded**

```java
class Solution {
    public int numTrees(int n) {
        return numTreesRecursively(1, n);
    }

    private int numTreesRecursively(int a, int b) {
        if (a > b) {
            return 1;
        }

        int rst = 0;
        for (int root = a; root <= b; root ++ ) {
            int leftTreeNum = numTreesRecursively(a, root - 1);
            int rightTreeNum = numTreesRecursively(root + 1, b);
            rst += leftTreeNum * rightTreeNum;
        }

        return rst;
    }
}
```

DP ?

```java
class Solution {
    public int numTrees(int n) {
        int[] numBSTs = new int[n + 1];
        numBSTs[0] = 1;
        for (int i = 1; i <= n; i ++ ) {
            int numBSTi = 0;
            for (int root = 1; root <= i; root ++ ) {
                numBSTi += numBSTs[i - root] * numBSTs[root - 1];
            }
            numBSTs[i] = numBSTi;
        }
        return numBSTs[numBSTs.length - 1];
    }
}
```

## 98. Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


**Example 1:**
```
    2
   / \
  1   3

Input: [2,1,3]
Output: true
```
**Example 2:**
```
    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```

- Long.MIN_VALUE, Integer.MIN_VALUE.
- each branch has a value range.

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
    public boolean isValidBST(TreeNode root) {
        return isValid(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    private boolean isValid(TreeNode root, long min, long max) {
        if (root == null) {
            return true;
        }

        if (root.val <= min || root.val >= max) {
            return false;
        }

        return (isValid(root.left, min, root.val)) && (isValid(root.right, root.val, max));
    }
}
```


## 99. Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

**Example 1:**
```
Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
```
**Example 2:**
```
Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
```
***Follow up:***

- A solution using O(n) space is pretty straight forward.
- Could you devise a constant space solution?

### Solution

Inorder Traversal solution.

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
    TreeNode node = new TreeNode(Integer.MIN_VALUE);
    TreeNode mis1, mis2;

    public void recoverTree(TreeNode root) {
        inorderTraversal(root);
        System.out.println(mis2);
        swap(mis1, mis2);
    }

    private void inorderTraversal(TreeNode root) {
        if (root == null) {
            return;
        }

        inorderTraversal(root.left);

        if (node.val > root.val) {
            if (mis1 == null) {
                mis1 = node;
            }
            if (mis1 != null) {
                mis2 = root;
            }
        }
        node = root;

        inorderTraversal(root.right);
    }

    private void swap(TreeNode mis1, TreeNode mis2) {
        int tmp = mis1.val;
        mis1.val = mis2.val;
        mis2.val = tmp;
    }
}
```


## 100. Same Tree

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

**Example 1:**
```
Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
```
**Example 2:**
```
Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
```
**Example 3:**
```
Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
```

```java
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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }

        if (p == null || q == null) {
            return false;
        }

        return (p.val == q.val) && (isSameTree(p.left, q.left)) && (isSameTree(p.right, q.right));
    }
}
```

## 101. Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```

But the following [1,2,2,null,3,null,3] is not:
```
    1
   / \
  2   2
   \   \
   3    3
```

Note:
Bonus points if you could solve it both recursively and iteratively.

```java
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
    public boolean isSymmetric(TreeNode root) {
        if (root == null)
            return true;
        return isSame(root.left, root.right);
    }

    private boolean isSame(TreeNode a, TreeNode b) {
        if (a == null || b == null) {
            return a == b;
        }

        return (a.val == b.val) && isSame(a.left, b.right) && isSame(a.right, b.left);
    }
}
```

## 102. Binary Tree level Order Traversal (medium)

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

**For example:**
```
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
```

## 116. Populating Next Right Pointers in Each Node

https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

BFS in java.
```Java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val,Node _left,Node _right,Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    public Node connect(Node root) {
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        q.add(null);
        while (!q.isEmpty()) {
            // System.out.println(q);
            Node head = q.remove();
            if (head == null) {
                if (q.size() > 1) {
                    q.add(null);
                }
            } else {
                head.next = q.peek();
                if (head.left != null) {
                    q.add(head.left);
                    q.add(head.right);
                }
            }
        }
        return root;
    }
}
```

```python
# Definition for binary tree with next pointer.
# class TreeLinkNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution(object):
    def connect(self, root):
        """
        :type root: TreeLinkNode
        :rtype: nothing
        """
        if root == None:
            return
        pre = root
        while pre.left:
            cur = pre
            while cur:
                cur.left.next = cur.right
                if cur.next:
                    cur.right.next = cur.next.left
                cur = cur.next
            pre = pre.left
```


## 117. Populating Next Right Pointers in Each Node II

https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

```Java
class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return null;
        }
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        q.add(null);
        while (!q.isEmpty()) {
            // System.out.println(q);
            Node head = q.remove();
            if (head == null) {
                if (!q.isEmpty()) {
                    q.add(null);
                }
            } else {
                head.next = q.peek();
                if (head.left != null) {
                    q.add(head.left);
                }
                if (head.right != null) {
                    q.add(head.right);
                }
            }
        }
        return root;
    }
}
```


Another way:

record the previous node in each depth.

```Java
class Solution {
    public Node connect(Node root) {
        List<Node> list = new ArrayList<Node>();
        helper(list,0,root);
        return root;
    }

    public void helper(List<Node> list,int depth,Node root){
        if(root == null) return;
        if(list.size() > depth){
            list.get(depth).next = root;
            list.remove(depth);
        }
        list.add(depth,root);
        helper(list,depth + 1,root.left);
        helper(list,depth + 1,root.right);
    }
}
```
