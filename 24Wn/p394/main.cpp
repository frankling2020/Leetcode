
#include <string>
#include <vector>
using namespace std;

class Solution {
    string getDigits(string& s, int& ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    string getString(vector<string>& v) {
        string ret = "";
        for (const string& s: v) {
            ret += s;
        }
        return ret;
    }

public:
    string decodeString(string s) {
        vector<string> stk;
        int ptr = 0;
        int sz = s.length();
        while (ptr < sz) {
            char c = s[ptr];
            if (isdigit(c)) {
                string digit = getDigits(s, ptr);
                stk.push_back(digit);
            }
            else if (isalpha(c) || c == '[') {
                stk.push_back(string(1, c));
                ++ptr;
            }
            else {
                string x = "";
                ++ptr;
                while (stk.back() != "[") {
                    x = stk.back() + x;
                    stk.pop_back();
                }

                stk.pop_back();
                int repeats = stoi(stk.back());
                stk.pop_back();

                string sub = "";
                while (repeats--) {
                    sub += x;
                }
                stk.push_back(sub);
            }
        }
        return getString(stk);
    }
};