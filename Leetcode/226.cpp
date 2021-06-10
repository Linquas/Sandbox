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
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
        return root;
    }
    
    void traverse(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        
        TreeNode* temp = node->right;
        node->right = node->left;
        node->left = temp;
        
        traverse(node->left);
        traverse(node->right);
    }
};