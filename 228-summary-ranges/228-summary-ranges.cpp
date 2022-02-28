class Solution {
public:
    vector<string> summaryRanges(vector<int>& nu) {
        // set<int> m;
        int n = nu.size();
        // for(int i=0; i<n; i++){
        //     m.insert(nums[i]);
        // }
        vector<long long> nums;
        for(int i=0; i<n; i++){
            nums.push_back((long long)nu[i]);
        }
        vector<string> ans;
        if(n==1){
            string a = "";
            if(nums[0]>=0) a=to_string(nums[0]);
            else {
                a="-";
                a+=to_string(abs(nums[0]));
            }
            ans.push_back(a);
        }
        int i=0;
        
        for(int j=1; j<n;){
            while(j<n and nums[j-1]+1==nums[j]){
                j++;
            }
            // cout<<i<<' '<<j<<" || ";
            string a ="";
            if(nums[i]>=0){
                a+=to_string((nums[i]));
            }
            else{
                a+="-";
                a+=to_string((abs(nums[i])));
            }
            
            if(i!=j-1){
                a+="->";
                if(nums[j-1]>=0){
                    a+=to_string(nums[j-1]);
                }
                else{
                    a+="-";
                    a+=to_string(abs(nums[j-1]));
                }
            
            }
            ans.push_back(a);
            
                i=j;
            //else{
                j++;
            //    i++;
            //}
            
            // j++;
            a="";
            if(j==n and nums[j-2]+1!=nums[j-1]){
                if(nums[j-1]>=0){
                    a+=to_string(nums[j-1]);
                }
                else{
                    a+="-";
                    a+=to_string(abs(nums[j-1]));
                }
                ans.push_back(a);  
                break;
            }
        }
        return ans;        
    }
};