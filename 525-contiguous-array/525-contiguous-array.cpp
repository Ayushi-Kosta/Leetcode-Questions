class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int n=nums.size(), count=0, len=0;  
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                count++;
            }
            else{
                count--;
            }
            
            if(m.find(count)!=m.end()){
                len=max(len, (i-m[count])); 
            }
            else{
                m[count]=i;
               
            }
            
            if(count==0){
                len=max(i+1, len);
            }
            
        }
        
        return len;
    }
};