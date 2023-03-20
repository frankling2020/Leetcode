#include <vector>
#include <iostream>
using namespace std;

// int lengthOfLIS(vector<int>& nums) {
//     int sz = nums.size(), maximum = 0;
//     int* arr = new int[sz];
//     for (int i=0; i < sz; ++i) arr[i] = 0;
//     for (int num = 0; num < sz; ++num){
//         for (int prev = num-1; prev >=0; --prev){
//             if (nums[num] > nums[prev]) arr[num] = std::max(arr[num], arr[prev]);
//         }
//         ++arr[num];
//         if (maximum < arr[num]) maximum = arr[num];
//     }
//     for (int i = 0; i < sz; i++) cout << arr[i] << " ";
//     cout << "\n";
//     delete [] arr;
//     return maximum;
// }

int lengthOfLIS(vector<int> nums){
    int sz = nums.size();
    if (sz < 2) return sz;
    int left, mid, right;
    vector<int> arr;
    arr.reserve(sz);
    arr.emplace_back(nums[0]);
    for (int ptr = 1; ptr < sz; ++ptr){
        if (nums[ptr] > arr.back()) arr.emplace_back(nums[ptr]);
        else {
            left = 0;
            right = arr.size() - 1;
            while (left <= right){
                mid = left + (right - left)/2;
                if (arr[mid] == nums[ptr]) break;
                else if (nums[ptr] < arr[mid]) right = mid - 1;
                else left = mid + 1;
            }
            if (arr[mid] != nums[ptr]) arr[left] = nums[ptr];
        }
        for (int i = 0; i < sz; i++) cout << arr[i] << " ";
        cout << "\n";   
    }
    return arr.size();
}


int main(){
    vector<int> nums = {3,5,6,2,5,4,19,5,6,7,12};
    cout << lengthOfLIS(nums) << endl; 
}
