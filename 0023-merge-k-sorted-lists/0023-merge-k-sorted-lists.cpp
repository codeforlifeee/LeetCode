/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
       // Function to merge two sorted lists
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val <= l2->val) {
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
    }

    // Recursive function to partition and merge lists using divide and conquer
    ListNode* PartitionAndMerge(int start, int end, vector<ListNode*>& lists) {
        if (start > end) return NULL;  // Base case: invalid range
        if (start == end) return lists[start];  // Base case: single list

        int mid = start + (end - start) / 2;
        ListNode* leftList = PartitionAndMerge(start, mid, lists);
        ListNode* rightList = PartitionAndMerge(mid + 1, end, lists);

        // Merge the two halves
        return mergeTwoSortedLists(leftList, rightList);
    }

    // Function to merge k sorted lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return NULL;  // Edge case: no lists to merge

        return PartitionAndMerge(0, k - 1, lists);
    }

};