class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int count=0;
        unordered_map<int, int> m;
        
        //storing every possible value of sum of elements of nums1 and nums2 and its occurence
        for(int z=0; z<n; z++){
            for(int x=0; x<n; x++){
                m[nums1[z]+nums2[x]]++;
            }
        }
        
        //checking for every possible value of sum of elements of nums3 and nums4 and adding its occurence in count                 variable
        for(int z=0; z<n; z++){
            for(int x=0; x<n; x++){
                if(m.find(-(nums3[z]+nums4[x])) != m.end()){
                    count+=m[-(nums3[z]+nums4[x])];       
                }
            }
        }
        
        return count;
    }
};