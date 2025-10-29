#include <iostream>
#include <vector>
using namespace std;

void rearrange(vector<int>& nums){
    int i=0,j=1,n=nums.size();
    while(i<n && j<n){
        while(i<n && nums[i]%2==0) i+=2;
        while(j<n && nums[j]%2==1) j+=2;
        if(i<n && j<n) swap(nums[i], nums[j]);
    }
}

int main(){
    vector<int> nums={3,1,2,4};
    rearrange(nums);
    for(int x:nums) cout<<x<<" "; cout<<endl;
}
