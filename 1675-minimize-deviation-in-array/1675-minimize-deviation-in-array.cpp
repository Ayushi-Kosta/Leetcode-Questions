class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        int n = nums.size(), res=INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i]%2){
                s.insert(nums[i]*2);
            }
            else s.insert(nums[i]);
        }
        res = min(res, (*(s.rbegin()) - *s.begin()));
        while(*(s.rbegin())%2==0){
            int a = *(s.rbegin())/2;
            s.erase(*(s.rbegin()));
            s.insert(a);
            res = min(res, (*(s.rbegin()) - *s.begin()));
        }
        res = min(res, (*(s.rbegin()) - *s.begin()));
        return res;
    }
};