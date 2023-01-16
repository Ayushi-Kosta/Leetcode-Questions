class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int i=0;
        vector<vector<int>> v(numRows);
        v[0].push_back(1);
        if(numRows==1) return v;
        for(int i=1; i<numRows; i++){
            int prev_i = i-1, j=0;
            v[i].push_back(1);
            while(j<v[prev_i].size()-1){
                int sum=v[prev_i][j]+v[prev_i][j+1];
                v[i].push_back(sum);
                j++;
            }
            v[i].push_back(1);
        }
        return v;
    }
};