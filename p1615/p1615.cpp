#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj_lst;
        vector<int> deg;

        for (int i = 0; i < n; ++i) {
            adj_lst.push_back(vector<int>(n, 0));
            deg.push_back(0);
        }


        for (auto road = roads.begin(); road < roads.end(); ++road) {
            int first = (*road)[0];
            int second = (*road)[1];

            adj_lst[first][second] = 1;
            adj_lst[second][first] = 1;

            deg[first] += 1;
            deg[second] += 1;
        }

        int maxval = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j  < n; ++j) {
                if (maxval < deg[i] + deg[j] - adj_lst[i][j]) {
                    maxval = deg[i] + deg[j] - adj_lst[i][j];
                }
            }
        }
        return maxval;
    }
};