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
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        
        for(auto list: lists){
            if(list){
                minHeap.push(list);
            }
        }
        ListNode* dummy= new ListNode(0);
        ListNode* tail = dummy;
        
        while(!minHeap.empty()){
            ListNode* curr = minHeap.top();
            minHeap.pop();
            tail->next = curr;
            tail = curr;
            if(curr->next){
                minHeap.push(curr->next);
            }
            
        }
        return dummy->next;
        
        
    }
};