#include "p242.hpp"


class Solution {
public:
    bool isAnagram(string s, string t) {
        return isAnagram_hash(s, t);
    }
};


int main(int argc, char* argv[]) {
    string s = "anagram";
    string t = "nagaram";
    Solution sol = Solution();
    cout << sol.isAnagram(s, t) << endl;
    return 0;
}