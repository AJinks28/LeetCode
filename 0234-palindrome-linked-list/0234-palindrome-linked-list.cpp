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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head,*fast=head;
        
        //finding middle
        while(fast->next && fast->next->next){
            
            slow=slow->next;
            fast=fast->next->next;
        }
        
        
        //Reversing right half;
        ListNode* prev=slow,*curr=slow->next,*nxt;
        prev->next=NULL;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        
        //Comparing
        ListNode* left=head, *right=prev;
        
        while(left){
            // cout<<left->val<<" ";
            // cout<<right->val<<" ";
            
            if(left->val != right->val) return false;
            left=left->next;
            right=right->next;
        }
        
        return true;
    }
};