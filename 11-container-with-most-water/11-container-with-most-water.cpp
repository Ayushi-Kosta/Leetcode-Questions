class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(), i=0, j=n-1, ans=0;
        while(i<=j){
            ans=max(ans, (j-i)*min(height[i], height[j]));
            if(height[i]<height[j]){
                i++;
            }
            else if(height[j]<height[i]){
                j--;
            }
            else{
                i++;
                j--;
            }            
        }
        return ans;
        
    }
};