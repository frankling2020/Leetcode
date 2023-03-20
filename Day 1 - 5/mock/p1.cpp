#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    bool isFull;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), isFull(true), left(nullptr), right(nullptr) {};
};

int dfs_height(TreeNode* root) {
    if (!root) return 0;
    int left_height = dfs_height(root->left);
    int right_height = dfs_height(root->right);
    root->isFull = left_height == right_height; 
    return max(left_height, right_height) + 1;
}



int main(int argc, char* argv[]) {
    int n;
    cin >> n;

    vector<TreeNode*> tree;
    for (int i = 0; i < n; ++i) {
        tree.push_back(new TreeNode(i));
    }

    int left, right;
    for (int i = 0; i < n; ++i) {
        cin >> left >> right;
        if (left >= 1) tree[i]->left = tree[left-1];
        if (right >= 1) tree[i]->right = tree[right-1];
    }

    int ans = 0;
    dfs_height(tree[0]);
    for (int i = 0; i < n; ++i) if (tree[i]->isFull) {++ans; cout << i << " ";}
    for (auto node: tree) delete node;
    cout << ans << endl;
}





// int main(int argc, char* argv[]) {
//     int n;
//     cin >> n;
//     vector<int> tree(n, -1);
//     int left, right;
//     for (int i = 0; i < n; ++i) {
//         cin >> left >> right;
//         if (left >= 1) tree[left-1] = i;
//         if (right >= 1) tree[right-1] = i;
//     }

//     for (auto x : tree)
//         cout << x << " ";
//     cout << endl;

//     int ans = 0;
//     vector<int> res(n, 1);
//     for (int i = n - 1;  i > 0; --i) {
//         if (res[i] == 1) ++ans;
//         else res[tree[i]] = 0;    
//     }
//     cout << ans << endl;
// }