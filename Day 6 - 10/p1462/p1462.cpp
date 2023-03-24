#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj;
        for (int i = 0; i < numCourses; ++i) adj.push_back(vector<int>(numCourses, 0));
        for (auto p: prerequisites) adj[p[0]][p[1]] = 1;

        for (int mid = 0; mid < numCourses; ++mid) {
            for (int begin = 0; begin < numCourses; ++begin) {
                if (mid != begin && adj[begin][mid]) {
                    for (int end = 0; end < numCourses; ++end) {
                        if (end != begin && end != mid && !adj[begin][end] && adj[mid][end]) {
                            adj[begin][end] = 1;
                        }
                    }   
                }
            }
        }

        vector<bool> res;
        for (auto q: queries) {
            res.push_back(adj[q[0]][q[1]] == 1);
        }
        return res;
    }
};