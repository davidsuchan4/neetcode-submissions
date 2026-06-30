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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            return new TreeNode(val);

        }
        TreeNode* next = root;
        while(next->left != nullptr || next->right != nullptr){
            if(val < next->val){
                if(next->left ==  nullptr){
                    next->left = new TreeNode(val);
                    return root;
                }
                next = next->left;
            }
            else{
                if(next->right == nullptr){
                    next->right = new TreeNode(val);
                    return root;  
                }
                next = next->right;
            }
        }
        if(val < next->val){
            next->left = new TreeNode(val);
        }
        else{
            next->right = new TreeNode(val);
        }
        return root;
    }
};