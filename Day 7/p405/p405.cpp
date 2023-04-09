#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        string res;
        int n = num;
        for (int i = 0; i <= 7 && n != 0; ++i) {
            int val = n & 0xf;
            // cout << val << endl;
            n = n >> 4;
            // cout << n << endl;
            char digit = (val < 10)? (char) (val + '0') : (char) ('a' + val - 10);
            res.push_back(digit);
        }
        reverse(res.begin(), res.end());
        return  res;
    }
};


int main(){
    Solution sol;
    cout << sol.toHex(-1) << endl;
}