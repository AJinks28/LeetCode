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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        int cnt=0;
        
        ListNode* temp=head,*head2=head->next,*prev;
        while(temp && temp->next){
            cnt++;
            ListNode* nxt=temp->next;
            ListNode* nnxt=nxt->next;
            temp->next=nnxt;
            prev=temp;
            temp=nxt;
        }
        // cout<<temp->val;
        if(cnt%2==0) temp->next=head2;
        else prev->next=head2;
        return head;
    }
};