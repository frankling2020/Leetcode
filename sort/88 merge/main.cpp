#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m - 1, ptr2 = n - 1;
        for (int ptr = n + m - 1; ptr >= 0;--ptr){
            if (ptr1 < 0 || (ptr2 >= 0 && nums1[ptr1] < nums2[ptr2])) nums1[ptr] = nums2[ptr2--];
            else nums1[ptr] = nums1[ptr1--];
        } 
    }
};