#include <string>
#include <algorithm>
#include <climits>
using namespace std;

enum state {Start, Signed, Number, End};

state state_transfer(state s, char c) {
    if (isspace(c)) {
        if (s == Start) return Start;
        else return End;
    }
    else if (isdigit(c)) {
        if (s == End) return End;
        else return Number; 
    }
    else if (c == '+' || c == '-') {
        if (s == Start) return Signed;
        else return End;
    }
    else return End;
}



class Solution {
public:
    int myAtoi(string s) {
        long number = 0L;
        int sign = 1;
        state ptr = Start;
        for (int i = 0; i < s.length(); ++i) {
            ptr = state_transfer(ptr, s[i]);
            if (ptr == End) return number;
            else if (ptr == Signed && s[i] == '-') sign = -1; 
            else if (ptr == Number) number = number * 10 + sign * (s[i] - '0');
            number = sign == 1 ? min(number, (long) INT_MAX) : max(number, (long) INT_MIN);
            if (number == ((sign == 1)? INT_MAX:INT_MIN)) return number;
        }
        return (int) number;
    }
};