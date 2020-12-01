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
        if (root == NULL) {
            return 0;
        }
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        int level = 0;
        
        while(nodes.size() != 0) {
            int count = nodes.size();
            
            for (int i = 0; i < count; i++) {
                TreeNode* node = nodes.front();
                nodes.pop();
                
                if (node->left != NULL) {
                    nodes.push(node->left);
                }
            
                if (node->right != NULL) {
                    nodes.push(node->right);
                }
            }
            level = level + 1;
        }
        return level;
    }
};