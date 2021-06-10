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
    int res = 0;
    int deepestLevel = 0;
    int deepestLeavesSum(TreeNode* root) {
        traverse(root, 1);
        return res;
    }
    
    void traverse(TreeNode* node, int level) {
        if (!node) {
            return;
        }
        
        if (level > deepestLevel) {
            deepestLevel = level;
            res = 0;
        }
        if (level == deepestLevel) {
            res = res + node->val;
        }
        
        if (node->left) {
            traverse(node->left, level+1);   
        }
        
        if (node->right) {
            traverse(node->right, level+1);
        }
    }
};