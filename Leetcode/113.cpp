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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> current;
        vector<vector<int>> result;
        traverse(root, result, current, 0, targetSum);
        return result;
    }
    
private:
    void traverse(TreeNode* node, vector<vector<int>>& result, vector<int>& current, int sum, int targetSum) {
        if (node == NULL) return;
        sum = sum + node->val;
        current.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            if (sum == targetSum) {
                auto ans = current;
                result.push_back(ans);
            }
            current.pop_back();
            return;
        }
        
        traverse(node->left, result, current, sum, targetSum);
        traverse(node->right, result, current, sum, targetSum);
        current.pop_back();
    }
};