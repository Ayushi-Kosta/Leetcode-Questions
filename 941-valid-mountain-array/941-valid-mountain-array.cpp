class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool top=0, bot=1;
        int n = arr.size();
        if(n<3){
            return 0;
        }
        for(int i=0; i<n-1; i++){
            if(arr[1]<=arr[0]){
                return 0;
            }
            if(arr[i+1]==arr[i]){
                return 0;
            }
            if(bot and !top and arr[i+1]<arr[i]){
                top=1;
                bot=0;
            }
            if(bot and !top and arr[i+1]<=arr[i]){
                return 0;
            }
            if(!bot and top and arr[i+1]>=arr[i]){
                return 0;    
            }
            
        }
        if(top and !bot){
            return 1;
        }
        else{
            return 0;
        }
    }
};