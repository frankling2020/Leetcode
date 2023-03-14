#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans;

        int rows = rowSum.size();
        int cols = colSum.size();
        int col_begin = 0;

        for (int target: rowSum) {
            vector<int> arr(cols, 0);
            int col =  col_begin;
            while (col < cols and target > 0) {
                if (target > colSum[col]) {
                    arr[col] = colSum[col];
                    ++col_begin;
                }
                else arr[col] = target;
                target -= arr[col];
                colSum[col] -= arr[col];
                ++col;
            }
            ans.push_back(arr);
        }
        return ans;
    }
};