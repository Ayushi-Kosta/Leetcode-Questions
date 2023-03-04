class Solution {
public:
    int help(string word1, string word2, int i, int j, vector<vector<int>> &v){
        
        if(j>=word2.size()){
            return (word1.size()-i);
        }
        if(i>=word1.size()) return (word2.size()-j);
        if(v[i][j]!=-1) return v[i][j];
        if(word1[i]==word2[j]){
            v[i][j] = help(word1, word2, i+1, j+1, v);
            return v[i][j];
            // return help(word1, word2, i+1, j+1);
        }
        else{    
            return v[i][j]=1+min(min(help(word1, word2, i+1, j+1, v), help(word1, word2, i+1, j, v)), help(word1, word2, i, j+1, v));
        }
        
    }
    int minDistance(string word1, string word2) {
        // i++ for delete
        // j++ for insert
        // i++ j++ replace
        int m = word1.size(), n = word2.size();
        vector<vector<int>> v(m+1, vector<int> (n+1,-1));
        
        
        return help(word1, word2, 0, 0, v);
        
    }
};