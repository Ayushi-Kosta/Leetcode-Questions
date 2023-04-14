class Solution {
public:
    int lpss(string s, int i, int j, vector<vector<int>> &lps){
        // if(i>j) return 0;
        // if(i==j) return 1;
        // if(lps[i][j]) return lps[i][j];
        // if(s[i]==s[j]){
        //     lps[i][j]=2+lpss(s, i+1, j-1, lps);
        // }
        // else{
        //     lps[i][j]=max(lpss(s, i+1, j, lps), lpss(s, i, j-1, lps));
        // }
        // return lps[i][j];
        int n = s.size();
        for(int i=n-1; i>=0; i--){
            lps[i][i]=1;
            for(int j=i+1; j<n; j++){
                if(s[i]==s[j]){
                    lps[i][j]=lps[i+1][j-1]+2;
                }
                else{
                    lps[i][j]=max(lps[i+1][j], lps[i][j-1]);
                }
            }    
        }
        return lps[0][n-1];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> v(n, vector<int> (n, 0));
        int i=0, j=n-1;
        return lpss(s, i, j, v);
    }
};