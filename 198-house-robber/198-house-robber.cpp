class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        if(n==0){
            return 0;
        }
        else if(n==1){
            return nums[0];
        }
        else if(n==2){
            return max(nums[0], nums[1]);
        }
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[2]=nums[2]+dp[0];
        int ans = 0;
        ans=max(dp[0], max(dp[1], dp[2]));
        for(int i=3; i<n; i++){
            dp[i] = max(dp[i-2], dp[i-3])+nums[i];
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};