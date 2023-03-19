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
    int helper_func(TreeNode* root, int& maximum) {
        if (root == nullptr) return 0;
        int left = max(0, helper_func(root->left, maximum));
        int right = max(0, helper_func(root->right, maximum));
        maximum = max(maximum, root->val + left + right);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maximum = INT_MIN;
        int a = helper_func(root, maximum);
        return maximum;
    }
};