#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum_twoPoints(vector<int>& nums, int target);
vector<int> twoSum_hashMap(vector<int>& nums, int target);



vector<int> twoSum_twoPoints(vector<int>& nums, int target)
{
    int sz = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> ans = {};
    int left = 0;
    int right = sz - 1;

    while (left < right){
        if (nums[left] + nums[right] == target) {
            ans.push_back(left);
            ans.push_back(right);
            break;
        }
        else if (nums[left] + nums[right] < target) {
            left += 1;
        }
        else {
            right -= 1;
        }
        
    }
    return ans;
}


vector<int> twoSum_hashMap(vector<int>& nums, int target)
{
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); ++i) {
        auto it = hashtable.find(target - nums[i]);
        if (it != hashtable.end()) {
            return {it->second, i};
        }
        hashtable[nums[i]] = i; 
    }
    return {};
}

