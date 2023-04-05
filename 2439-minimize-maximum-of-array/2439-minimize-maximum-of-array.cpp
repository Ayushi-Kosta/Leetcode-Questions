class Solution {
public:

    bool check(long long mid, vector<int>& nums){
        long long sum = 0;
        for(int i = 0, n = nums.size(); i < n; i++){
            sum += nums[i];
            if(sum > mid*(i + 1)) return false;
        }
        return true;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int l = 0, r = 1e9, ans = 0;
        while(l <= r){
            long long mid = (l + r)/2;
            if(check(mid, nums)) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        return ans;
    }
};