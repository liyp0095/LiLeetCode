<!-- TOC START min:1 max:3 link:true asterisk:false update:true -->
- [Linked List](#linked-list)
  - [23. Merge k Sorted Lists (hard)](#23-merge-k-sorted-lists-hard)
    - [Solution](#solution)
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
