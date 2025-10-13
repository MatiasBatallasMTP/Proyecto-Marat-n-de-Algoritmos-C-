#include <iostream>
#include <vector>
using namespace std;

int kadane(vector<int>& nums) {
    int maxSoFar = nums[0], maxEndingHere = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "La suma máxima del subarray es: " << kadane(nums) << endl;
    return 0;
}
