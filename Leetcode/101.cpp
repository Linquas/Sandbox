/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        bool result = true;
        check(root->left, root->right, &result);
        return result;
    }
    
private:
    void check(TreeNode* left, TreeNode* right, bool* result) {
        if (left == NULL && right == NULL) {
            return;
        }
        
        if (left == NULL || right == NULL) {
            *result = false;
            return;
        }
        
        if (left->val != right->val) {
            *result = false;
            return;
        }
        
        if (left->left != NULL && right->right != NULL) {
            if (left->left->val != right->right->val) {
                *result = false;
            }
        }
        
        if (left->right != NULL && right->left != NULL) {
            if (left->right->val != right->left->val) {
                *result = false;
            }
        }
        
        check(left->left, right->right, result);
        check(left->right, right->left, result);
        return;
    }
};