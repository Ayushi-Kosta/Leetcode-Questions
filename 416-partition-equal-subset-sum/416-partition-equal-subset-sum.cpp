class Solution {
public:
    bool subsetsum(vector<int>& nums, int n, int sum){
        int dp[n+1][sum+1];  //dp[i][j] is combining i elements of array and making sum as j
        for(int i=0; i<=sum; i++){  
            dp[0][i]=0;
        }
        for(int i=0; i<=n; i++){  
            dp[i][0]=1;
        }        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j] or dp[i-1][j-nums[i-1]];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2) return 0;
        return subsetsum(nums, nums.size(), sum/2);
    }
};