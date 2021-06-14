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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
private:
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
              vector<int>& postorder, int posStart, int posEnd) {
        
        if (inStart > inEnd) {
            return NULL;
        }
        
        auto node = new TreeNode(postorder[posEnd]);
        
        int nodeIndexOfInorder = 0;
        for(int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == postorder[posEnd]) {
                nodeIndexOfInorder = i;
                break;
            }
        }
    
        int leftSize = nodeIndexOfInorder - inStart;
                                        
        node->left = build(inorder, inStart, nodeIndexOfInorder-1, postorder, posStart, posStart + leftSize - 1);
        node->right = build(inorder, nodeIndexOfInorder+1, inEnd, postorder, posStart + leftSize, posEnd - 1);
        return node;
    }
};