class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size(), c=0;
        unordered_map <int, int> b;
        vector<vector<int>> a(60);
        for(int i=0; i<n; i++){
            if(b.find((60-(time[i]%60))%60) != b.end()){
                c+=b[(60-(time[i]%60))%60];
            }
            b[time[i]%60]++;
        }
        
        return c;
    }
};