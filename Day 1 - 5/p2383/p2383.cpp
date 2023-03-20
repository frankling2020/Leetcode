#include <vector>
using namespace std;


class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int sz = energy.size();
        int hours = 0;
        for (int i = 0; i < sz; ++i){
            initialEnergy -= energy[i];
            if (initialEnergy <= 0){
                hours += -initialEnergy + 1;
                initialEnergy = 1;
            }
            if (initialExperience <= experience[i]) {
                hours += experience[i] - initialExperience + 1;
                initialExperience = experience[i] + 1;
            }
            initialExperience += experience[i];
        }
        return hours;
    }
};