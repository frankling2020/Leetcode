#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, 0));
        dp[1][1] = 1;
        for (int num = 1; num <= k; ++num){
            for (int l = 1; l <= n; ++l){
                dp[num][l] = l;
                if (num > 1){
                    for (int x = 1; x <= l; ++x){
                        dp[num][l] = min(dp[num][l], max(dp[num-1][x-1], dp[num][l-x])+1);
                    }
                }
            }
        }
        return dp[k][n];
    }
};


int main(){
    Solution solver;
    cout << solver.superEggDrop(1, 1) << "\n";
    cout << solver.superEggDrop(1, 2) << "\n";
    cout << solver.superEggDrop(2, 1) << "\n";
    cout << solver.superEggDrop(2, 2) << "\n";
    cout << solver.superEggDrop(1, 3) << "\n";
    cout << solver.superEggDrop(2, 6) << "\n";
    cout << solver.superEggDrop(2, 9) << "\n";
    return 0;
}