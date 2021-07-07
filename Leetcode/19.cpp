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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = new ListNode();
        temp->next = head;
        
        int length = 0;
        auto node = head;
        while(node) {
            length++;
            node = node->next;
        }
        
        length -= n;
        node = temp;
        while(length > 0) {
            length--;
            node = node->next;
        }
        
        node->next = node->next->next;
        return temp->next;
    }
};