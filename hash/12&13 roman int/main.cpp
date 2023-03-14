#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
private:
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    // map<int, string, std::greater<int>> valueSymbols = {
    //     {1000, "M"},
    //     {900, "CM"},
    //     {500, "D"},
    //     {400, "CD"},
    //     {100, "C"},
    //     {90, "XC"},
    //     {50, "L"},
    //     {40, "XL"},
    //     {10, "X"},
    //     {9, "IX"},
    //     {5, "V"},
    //     {4, "IV"},
    //     {1, "I"},
    // };

    pair<int, string> valueSymbols[13] = {
        {1000, "M"},
        {900,  "CM"},
        {500,  "D"},
        {400,  "CD"},
        {100,  "C"},
        {90,   "XC"},
        {50,   "L"},
        {40,   "XL"},
        {10,   "X"},
        {9,    "IX"},
        {5,    "V"},
        {4,    "IV"},
        {1,    "I"},
    };

public:
    int romanToInt(string s) {
        int ans = 0;
        int len = s.length();
        for (int i = 0; i < len; ++i){
            int val = symbolValues[s[i]];
            if (i + 1 < len && val < symbolValues[s[i+1]]){
                ans -= val;
            }
            else{
                ans += val;
            }
        }
        return ans;
    }

     string intToRoman(int num) {
        string roman;
        for (auto &[value, symbol] : valueSymbols) {
            while (num >= value) {
                num -= value;
                roman += symbol;
            }
            if (num == 0) {
                break;
            }
        }
        return roman;
    }
};
