class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(), a=1, i=0;
        vector<int> missing;
        while(i<n){
            if(a==arr[i]){
                a++;
                i++;
            }
            else{
                while(i<n and a<arr[i]){
                    missing.push_back(a);
                    cout<<a<<" ";
                    a++;
                }
                
            }
        }
        if(a>arr[n-1]){
            missing.push_back(a);
        }
        if(missing.size()>=k){
            return missing[k-1];
        }
        else{
            return missing[missing.size()-1]+k-missing.size();
        }
        
    }
};