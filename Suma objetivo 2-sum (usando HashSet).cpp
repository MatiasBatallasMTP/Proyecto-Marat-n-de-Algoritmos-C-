#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool twoSum(vector<int>& nums, int target) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(target - num)) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    if (twoSum(nums, target)) {
        cout << "Se encuentra un par con suma objetivo." << endl;
    } else {
        cout << "No se encuentra un par con suma objetivo." << endl;
    }
    return 0;
}
