<!-- TOC START min:1 max:3 link:true asterisk:false update:true -->
- [Linked List](#linked-list)
  - [23. Merge k Sorted Lists (hard)](#23-merge-k-sorted-lists-hard)
    - [Solution](#solution)
  - [24. Swap Nodes in Pairs (medium)](#24-swap-nodes-in-pairs-medium)
    - [Solution](#solution-1)
<!-- TOC END -->

# Linked List

## 23. Merge k Sorted Lists (hard)

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

**Example:**
```
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
```

### Solution

- find min every time. This is too slow.

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int listIndex;
        ListNode rst = new ListNode(0);
        ListNode p = rst;
        while ((listIndex = FindMinIndex(lists)) >= 0) {
            // System.out.println(listIndex);
            // System.out.println(p.val);
            p.next = lists[listIndex];
            p = p.next;
            lists[listIndex] = p.next;
        }
        return rst.next;
    }

    private int FindMinIndex(ListNode[] lists) {
        int rst = -1;
        int val = Integer.MAX_VALUE;
        for (int i = 0; i < lists.length; i ++ ) {
            // System.out.println(lists[i].val);
            if (lists[i] == null) {
                continue;
            }

            if (lists[i].val < val) {
                rst = i;
                val = lists[i].val;
            }
        }
        // System.out.println();
        return rst;
    }
}
// Runtime: 153 ms, faster than 14.74% of Java online submissions for Merge k Sorted Lists.
// Memory Usage: 56.6 MB, less than 5.01% of Java online submissions for Merge k Sorted Lists.
```


## 24. Swap Nodes in Pairs (medium)

Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.


**Example:**
```
Given 1->2->3->4, you should return the list as 2->1->4->3.
```
### Solution

- add a head node to linked list for easy way to **iteration.**

```Java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode rst = new ListNode(0);
        rst.next = head;
        if (rst.next == null || rst.next.next == null) {
            return head;
        }

        ListNode p1, p2, p3;
        p1 = rst;
        while((p2 = p1.next) != null && (p3 = p2.next) != null) {
            p1.next = p3;
            p2.next = p3.next;
            p3.next = p2;
            p1 = p2;
            // System.out.println(p1.val);
        }

        return rst.next;
    }
}
```
