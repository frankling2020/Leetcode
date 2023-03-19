#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int sz = ranks.size();
        vector<float> ratio(sz, 0.0);
        float sum = 0.0;
        for (int i = 0; i < sz; ++i) {
            ratio[i] = 1 / pow(ranks[i], 0.5);
            sum += ratio[i];
        }
        vector<int> status(sz, 0);
        int res_car = cars;
        for (int i = 0; i < sz; ++i) {
            status[i] = (int) ratio[i] * cars;
            res_car -= status[i];
        }
        int minimum = 0, ptr = 0;
        for (int i = 0; i < res_car; ++i) {
            ranks[0] * pow(status[0] + 1, 2);
            for (int j = 0; j < sz; ++j) {
                if (minimum > ranks[j] * pow(status[j] + 1, 2)) {
                    minimum = ranks[j] * pow(status[j] + 1, 2);
                    ptr = j;
                }
            }
            ++status[ptr];
        }
        return minimum;
    }
};