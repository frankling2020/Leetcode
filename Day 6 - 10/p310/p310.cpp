#include <vector>
using namespace std;


class Solution {
public:
    void dfs()

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_lst, dp;
        for (int i= 0; i < n; ++i) {
            adj_lst.push_back({});
            dp.push_back(vector<int>(n, -1));
        }
        for (auto edge: edges) {
            adj_lst[edge[0]].push_back(edge[1]);
            adj_lst[edge[1]].push_back(edge[0]);
        }

    }
};