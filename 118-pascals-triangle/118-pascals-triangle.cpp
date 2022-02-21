class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);
        v[0].push_back(1);
        if(numRows==1){
            return v;
        }
        v[1].push_back(1);
        v[1].push_back(1);
        if(numRows==2){
            return v;
        }
        for(int i=2; i<numRows; i++){
            v[i].resize(i+1);
            v[i][0]=1;
            v[i][i]=1;
            for(int j=1; j<i; j++){
                v[i][j] = v[i-1][j]+v[i-1][j-1];
            }
        }
        return v;
    }
};