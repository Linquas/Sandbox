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
private:
    int count = 0;
    void traverse(TreeNode* node, int k, int& ans) {
        if (node == NULL) return;
        traverse(node->left, k, ans);
        
        count++;
        if (count == k) {   
            ans = node->val;
            return;
        }
        
        traverse(node->right, k, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        traverse(root, k, ans);
        return ans;
    }
};