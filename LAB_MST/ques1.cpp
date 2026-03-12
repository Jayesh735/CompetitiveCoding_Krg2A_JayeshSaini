#include<bits/stdc++.h>
using namespace std;

int sol(vector<int> &nums, int maxOperations){
    int l=1;
    int r = *max_element(nums.begin(), nums.end());
    int ans = r;
    while(l<=r){
        int mid = l + (r-l)/2;
        int cnt = 0;
        for(int i: nums){
            cnt += (i-1)/mid;
        }
        if(cnt > maxOperations){
            l = mid+1;
        }else{
            ans = mid;
            r = mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {2,4,8,2};
    int maxOperations = 4;
    cout<<sol(nums, maxOperations)<<endl;
    return 0;
}