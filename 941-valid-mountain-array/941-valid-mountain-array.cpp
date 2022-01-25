class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool top=0, bot=1;
        int n = arr.size();
        //cout<<"\n";
        if(n<3){
            return 0;
        }
        
//         int i=0;
//         while(i<n-1 and arr[i+1]>arr[i]){
//             i++;
//         }
//         // if(arr[i+1]==arr[i]){
//         //     return 0;
//         // }
//         while(i<n-1 and arr[i+1]<arr[i]){
//             i++;
//         }
//         cout<<i<<" ";
//         if(i<n){
//             return 0;
//         }
//         return 1;
        
        
        
        for(int i=0; i<n-1; i++){
            if(arr[1]<=arr[0]){
                return 0;
            }
            if(arr[i+1]==arr[i]){
                //cout<<"equal";
                return 0;
            }
            if(bot and !top and arr[i+1]<arr[i]){
                top=1;
                bot=0;
                //cout<<"2 ";
            }
            if(bot and !top and arr[i+1]<=arr[i]){
                //cout<<"1 ";
                return 0;
            }
            if(!bot and top and arr[i+1]>=arr[i]){
                //cout<<"3 ";
                return 0;    
            }
            
        }
        if(top and !bot){
            //cout<<"last1 ";
            return 1;
        }
        else{
            //cout<<"last2 ";
            return 0;
        }
    }
};