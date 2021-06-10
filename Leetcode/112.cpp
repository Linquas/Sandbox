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
    int result = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        traverse(root, sum, targetSum);
        return result;
    }
    
    void traverse(TreeNode* node, int sum, int targetSum) {
        if (node == NULL) {
            return;
        }
        sum = sum + node->val;
        if (node->left == NULL && node->right == NULL) {
            if (targetSum == sum) {
                result = true;
            }
            return;
        }
        traverse(node->left, sum, targetSum);
        traverse(node->right, sum, targetSum);
    }
};