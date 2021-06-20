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
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        if (head->next == NULL) {
            return false;
        }
        ListNode* twoStep = head->next;
        ListNode* oneStep = head;
        while(twoStep != NULL && twoStep->next != NULL) {
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
            
            if (oneStep == twoStep) {
                return true;
            }
        }
        return false;
    }
};  