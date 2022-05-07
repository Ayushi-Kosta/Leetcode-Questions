class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int n=nums.size();
        int var2=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(var2>nums[i]) return true;
            while(!s.empty() && nums[i]>s.top()){
                var2=s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};