class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return 0;
        for(int i=2; i<n; i++){
            if(arr[i-2]%2 and arr[i-1]%2 and arr[i]%2){
                return 1;
            }
        }
        return 0;
    }
};