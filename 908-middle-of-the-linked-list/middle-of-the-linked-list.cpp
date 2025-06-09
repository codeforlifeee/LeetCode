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
public://O(N) // O(1)
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> nodes;

        ListNode* curr = head;
        while (curr != nullptr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int midIndex = nodes.size() / 2;
        return nodes[midIndex];
    }
};