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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1,
                     inorder, 0, inorder.size()-1);
    }
    
private:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd) return NULL;
        
        //find root from the first item of preorder
        TreeNode* newNode = new TreeNode(preorder[preStart]);
        
        //find the index of root in inorder
        int index = 0;
        for(int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == preorder[preStart]) {
                index = i;
                break;
            }
        }
        
        int leftSize = index - inStart;
        newNode->left = build(preorder, preStart + 1 , preStart + leftSize, inorder, inStart, index-1);
        newNode->right = build(preorder,  preStart + leftSize + 1, preEnd ,inorder , index+1, inEnd);
        
        return newNode;
    }
};