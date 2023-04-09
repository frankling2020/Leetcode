struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int helper(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        if (root->left) sum += (root->left)->val;
        if (root->right) sum += (root->right)->val;
        return sum;
    }

public:
    int sumEvenGrandparent(TreeNode* root) {
        if (root == nullptr) return 0; 
        int left = sumEvenGrandparent(root->left);
        int right = sumEvenGrandparent(root->right);
        int sum = left + right;
        if (root->val % 2 == 0) {
            sum += helper(root->left) + helper(root->right);
        }
        return sum;
    }
};