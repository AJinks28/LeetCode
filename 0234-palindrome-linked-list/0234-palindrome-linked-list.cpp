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
        vector<int> nums;
        
        ListNode* temp=head;
        while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            if(nums[l]!=nums[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};