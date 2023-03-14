#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;


// use r first find the matched one, and then use r to minimize the length 
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> req;
        const int sz = static_cast<int> (s.size());
        int cnt = t.size();
        for (const auto &chr : t) ++req[chr];
        int l = 0, r = 0;
        int ansL = 0, ansR = sz;
        while (r < sz){
            if (req.find(s[r]) != req.end()) {
                if (--req[s[r]] >= 0) --cnt;
            }
            while (cnt == 0){
                if (req.find(s[l]) != req.end()) {
                    if (++req[s[l]] > 0) ++cnt;
                    if (cnt > 0) {
                        if (ansR - ansL > r - l) {
                            ansL = l;
                            ansR = r;
                        }
                    }
                }
                ++l;
            }
            ++r;
        }
        return (ansR - ansL == sz)? "":s.substr(ansL, ansR - ansL + 1);
    }
};