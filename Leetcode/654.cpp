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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
private:
    TreeNode* build(vector<int>& nums, int lo, int hi) {
        if (lo >　hi) return NULL;
        
        //Find index of max value
        int index = 0;
        int max = INT_MIN;
        for (int i = lo; i <= hi; ++i) {
            if (nums[i] > max) {
                index = i;
                max = nums[i];
            }
        }
        
        TreeNode* node = new TreeNode(max);
        node->left = build(nums, lo, index-1);
        node->right = build(nums, index+1, hi);
        return node;
    }
};