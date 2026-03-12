#include <bits/stdc++.h>
using namespace std;

int sol(vector<int> &nums, int k){
    const long long mod = 1e9+7;
    vector<int> cnt(31, 0);
    for(int x:nums){
        for(int b=0;b<31;b++){
            if(x&(1<<b)){
                cnt[b]++;
            }
        }
    }
    long long ans = 0;
    for(int i=0;i<k;i++){
        long long x = 0;
        for(int b=0;b<31;b++){
            if(cnt[b]>0){
                x |= (1LL<<b);
                cnt[b]--;
            }
        }
        ans += (x*x)%mod;
    }
    return ans;
}

int main()
{
    vector<int> nums = {2,6,5,8};
    int k = 2;
    cout << sol(nums, k) << endl;
    return 0;
}