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
    int goodNodes(TreeNode* root) { return search(root, root->val); }
    int search(TreeNode* node, int maximum) {
        if (!node) {
            return 0;
        }

        maximum = max(maximum, node->val);
        if (maximum <= node->val) {
            return 1 + search(node->left, maximum) + search(node->right, maximum);
        }
        return search(node->left, maximum) + search(node->right, maximum);
    }
};
