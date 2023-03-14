#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool isAnagram_sort(string s, string t);
bool isAnagram_hash(string s, string t);


bool isAnagram_sort(string s, string t)
{
    if (s.size() != t.size()){
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}


bool isAnagram_hash(string s, string t)
{
    if (s.size() != t.size()){
        return false;
    }
    unordered_map<char, int> hashtable;
    for (auto c: s) {
        auto it = hashtable.find(c);
        int val = 1;
        if (it != hashtable.end()){
            val = it->second + 1;
            hashtable.erase(c);
        }
        // std=c++17
        // hashtable.insert_or_assign(c, val);
        hashtable.insert({c, val});
    }

    // for (auto it: hashtable) {
    //     cout << it.first << " " << it.second << endl;
    // }

    for (auto c: t){
        auto it = hashtable.find(c);
        if (it != hashtable.end()) {
            it->second -= 1;
            if (it->second < 0){
                return false;
            }
        }
        else return false;
    }
    return true;
}