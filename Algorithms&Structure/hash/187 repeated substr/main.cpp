#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    const int L = 10;
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int sz = static_cast<int> (s.length());
        if (sz < L) return {};
        unordered_map<string, int> req;
        vector<string> ans;
        for (int i = 0; i <= s.length() - 10;++i){
            string cur = s.substr(i, L);
            // avoid repeat strings push_back
            if (++req[cur] == 2) ans.push_back(cur);
        }
        return ans;
    }
};