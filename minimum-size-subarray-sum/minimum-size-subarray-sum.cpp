class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int n=a.size(), sum=0, res=INT_MAX;
        int i=0, j=0;
        while(j<n){
            // while(target>=sum and j<n){
                sum+=a[j]; j++;
            // } 
            while(target<=sum and i<j){
                res=min(res, (j-i));
                sum-=a[i]; i++;
                
            } 
        }
        if(res==INT_MAX){
            res=0;
        }
        return res;
    }
};