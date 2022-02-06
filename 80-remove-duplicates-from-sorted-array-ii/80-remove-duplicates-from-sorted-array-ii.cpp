class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, c=0, curr=nums[0];
        while(i<nums.size()){
            if(curr==nums[i] and c<1){
                c++;
                i++;
            }
            else if(curr==nums[i] and c>=1){
                
                nums.erase(nums.begin()+i);
                //i--;
            }
            else{
                curr=nums[i];
                i++;
                c=0;
                    
            }
        }
        return nums.size();
    }
};