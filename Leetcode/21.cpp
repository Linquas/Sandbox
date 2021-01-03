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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 != NULL && l2 != NULL) {
            if (l1->val >= l2->val) {
                solve(l2, l1, l2->next);
                return l2;
            } else {
                solve(l1, l1->next, l2);
                return l1;
            }
        } else if (l1 != NULL) {
            return l1;
        } else if (l2 != NULL) {
            return l2;
        }
        
        return NULL;
    }
    
    void solve(ListNode* result, ListNode* l1, ListNode* l2) {
        if (l1 != NULL && l2 != NULL) {
            if (l1->val >= l2->val) {
                result->next = l2;
                return solve(result->next, l1, l2->next);
            } else {
                result->next = l1;
                return solve(result->next, l1->next, l2);
            }
        } else if (l1 != NULL) {
            result->next = l1;
            return;
        } else if (l2 != NULL) {
            result->next = l2;
        }
        return;
    } 
};