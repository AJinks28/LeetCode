/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            // Move slow one step
            slow = slow->next;
            // Move fast two steps
            fast = fast->next->next;

            // Check if slow and fast pointers meet
            if (slow == fast) {
                break;  // Loop detected
            }
        }
        if(!fast || !fast->next) return NULL;
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        // If fast reaches the end of the list,
        // there is no loop
        return head;
    }
};