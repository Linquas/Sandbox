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
    int maxDepth(TreeNode* root) {
        int ans = 0;
        traverseTree(root, &ans, 1);
        return ans;
    }
    
    void traverseTree(TreeNode* node, int* currentMaxHeight, int currentHeight) {
        if (node == NULL) {
            return;
        }
        
        if (node->left == NULL && node-> right == NULL) {
            if (currentHeight > *currentMaxHeight) {
                *currentMaxHeight = currentHeight;
            }
            return;
        }
        
        if (node->left != NULL) {
            traverseTree(node->left, currentMaxHeight, currentHeight + 1);
        }
        
        if (node->right != NULL) {
            traverseTree(node->right, currentMaxHeight, currentHeight + 1);
        }
        return;
    }
    
};