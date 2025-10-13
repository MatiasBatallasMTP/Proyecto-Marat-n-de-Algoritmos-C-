#include <iostream>
#include <vector>
using namespace std;

bool subsetSumHelper(vector<int>& nums, int target, int idx) {
    if (target == 0) return true;
    if (target < 0 || idx == nums.size()) return false;
    
    // Incluir el número en el subconjunto
    if (subsetSumHelper(nums, target - nums[idx], idx + 1)) return true;
    
    // No incluir el número en el subconjunto
    return subsetSumHelper(nums, target, idx + 1);
}

bool subsetSum(vector<int>& nums, int target) {
    return subsetSumHelper(nums, target, 0);
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int target = 9;
    
    if (subsetSum(nums, target)) {
        cout << "Existe un subconjunto con suma objetivo." << endl;
    } else {
        cout << "No existe un subconjunto con suma objetivo." << endl;
    }
    return 0;
}
