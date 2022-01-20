class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=pow(10, 9), ans=INT_MAX;
        while(low<=high){
            int k=(low+high)/2 , hour=0;
            for(int i=0; i<piles.size(); i++){
                hour+=(ceil(1.0 * piles[i]/k));
            }
            if(hour>h){
                low=k+1;
            }
            else{
                high=k-1;
            }
        }
        return low;
    }
};