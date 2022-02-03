class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int i=0, j=0, k=0, l=0, count=0;
        unordered_map<int, int> m;
        for(int z=0; z<n; z++){
            for(int x=0; x<n; x++){
                m[nums1[z]+nums2[x]]++;
            }
        }
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