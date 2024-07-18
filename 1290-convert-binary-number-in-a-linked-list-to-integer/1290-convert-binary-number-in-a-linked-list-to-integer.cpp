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
    int getDecimalValue(ListNode* head) {
        string binNum;
        while(head){
            binNum+=(head->val+'0');
            head=head->next;
        }
        int n=binNum.size(),cnt=1,ans=0;
        for(int i=n-1;i>=0;i--){
            ans+=(cnt*(binNum[i]-'0'));
            cnt*=2;
        }
        return ans;
    }
};