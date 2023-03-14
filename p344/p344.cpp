#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int sz = s.size();
        char temp;
        for (int i = 0; i < sz / 2; ++i) {
            temp = s[i];
            s[i] = s[sz - 1 - i];
            s[sz - 1 - i] = temp;
        }
    }
};