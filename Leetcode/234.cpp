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
        if (head == NULL) 
            return false;
        
        vector<int> record;
        ListNode* node;
        while(node != NULL) {
            record.push_back(node->val);
            node = node->next;
        }
        
        auto reverse = record;
        std::reverse(reverse.begin(), reverse.end());
        
        bool result = true;
        for (int i = 0; i < record.size(); ++i) {
            if (record[i] != reverse[i]) {
                return false;
            }
        }
        return result;
    }

    bool isPalindrome2(ListNode* head) {
        if (head == NULL) 
            return false;
        
        vector<int> record;
        ListNode* node = head;
        while(node != NULL) {
            record.push_back(node->val);
            node = node->next;
       }
        
        int front = 0;
        int end = record.size() - 1;
        
        while(front < end) {
            if (record[front] != record[end]) {
               return false;
            }
            front++;
            end--;
        }
        
        return true;
    }
};