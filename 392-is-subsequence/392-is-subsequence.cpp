class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = t.size(), n = s.size();
        int i = 0, j = 0;
        while(j<m){
            if(s[i]==t[j]){
                i++;
            }
            j++;
            
        }
        if(i>=n){
            return 1;
        }
        else{
            return 0;
        }
    }
};