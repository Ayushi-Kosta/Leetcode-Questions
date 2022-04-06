class Solution {
public:
    int mod = 1000000007;
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), count=0;
        for(int i=0; i<n-2; i++){
            int k=i+1, j=n-1;
            while(k<j){
                if(arr[k]+arr[j]==target-arr[i]){
                    int a = arr[k], b=arr[j], n1=1, n2=1;
                    if(a==b){
                        n1=(j-k+1);
                        count+=((n1)*(n1-1)/2)%mod;
                        count%=mod;
                        break;
                    }
                    else{
                        while(k+1<j and a==arr[k+1]){
                            k++;
                            n1++;
                        }
                        while(k+1<j and b==arr[j-1]){
                            j--;
                            n2++;
                        }
                        count+=(n1*n2)%mod;
                        count%=mod;
                    }
                    
                    k++;
                    j--;    
                }
                else if(target-arr[i] < arr[k]+arr[j]){
                    j--;
                }
                else{
                    k++;
                }  
                // cout<<"arr[i] "<<arr[i]<<" "<<count<<" ";
            }
            // cout<<"\n";
        }
        return count;       
    }
};  