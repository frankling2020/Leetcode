#include <iostream>
using namespace std;

struct TreeNode {
int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    int maxSum;
public:
    int maxPath(TreeNode* root){
        if (root == nullptr) return 0;
        int l = maxPath(root->left);
        int r = maxPath(root->right);
        if (maxSum < l + r + root->val){
            maxSum = l + r + root->val;
        }
        return std::max(0, std::max(r, l) + root->val);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = root->val;
        maxPath(root);
        return maxSum;
    }
};