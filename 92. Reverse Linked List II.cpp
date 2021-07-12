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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // corner case
        if(head == NULL || head -> next == NULL)
            return head;
        
        // main logic
        ListNode* lh = head;
        ListNode* lhbf; 
        ListNode* rh = head;
        
        for(int i = 1; i < left; ++i){
            if(i == left - 1)
                lhbf = lh;            
            lh = lh -> next;
        }
        
        for(int i = 1; i < right; ++i){
            rh = rh -> next;
        }
        
        ntail = dfs(lh, rh);
        
        if(left > 1)
            lhbf -> next = nhead; // key: connect on left side
        ntail -> next = tmptail; // key: connect on right side
        
        if (left > 1) // key
            return head;
        else
            return nhead;
    }

private:
    
    ListNode* nhead;
    ListNode* ntail;
    ListNode* tmptail;
    
    ListNode* dfs(ListNode* head, ListNode* rh){
        if(head -> next == rh -> next){
            nhead = head;
            tmptail = rh -> next;
            return head;
        }

        ListNode* rhead = dfs(head -> next, rh);
        rhead -> next = head;
        head -> next = NULL;
        return head;
    }    
};