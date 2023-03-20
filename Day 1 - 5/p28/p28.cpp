#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        int sz = needle.size();
        if (haystack.size() < sz) return -1;
        vector<int> go_back(sz, -1);

        // a sequence with length go_back[right] ended with right 
        int cycle = 0;
        int explore = 1;
        for (; explore < sz; ++explore) {
            while (cycle > 0 && needle[explore] != needle[cycle]) cycle = go_back[cycle - 1] + 1;
            if (needle[explore] == needle[cycle]) go_back[explore] = cycle;
            else {go_back[explore] = -1; cycle = -1;}
            ++cycle;
        }

        // for (auto x: go_back)
        //     cout << x << " ";
        // cout << endl;

        int n = 0, h = 0;
        for (; h < haystack.size(); ++h) {
            // cout << n << " " << h << " " << needle[n] << " " << haystack[h] << endl;
            while (n > 0 && haystack[h] != needle[n]) n = go_back[n - 1] + 1;
            if (haystack[h] != needle[n]) n = -1;
            // else cout << "Solve: " << n << " " << h << " " << needle[n] << " " << haystack[h] << endl; 
            ++n;
            if (n == sz) break;
        }
        return (n == sz)? h - n + 1:-1;
    }
};


int main(int argc, char* argv[]) {
    string a = "baabbbbababbbabab";
    string b = "abbab";
    cout << Solution().strStr(a, b) << endl; 
}