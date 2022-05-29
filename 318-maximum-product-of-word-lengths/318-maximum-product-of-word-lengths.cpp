class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> s(n);
        for(int i=0; i<n; i++){
            vector<int> v(26);
            for(int j=0; j<words[i].size(); j++){
                v[words[i][j]-'a']=1;
            }
            s[i]=v;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                bool t=0;
                for(int k=0; k<26; k++){
                    if(s[i][k] and s[j][k]){
                        t=1;
                    }
                }
                if(!t){
                    int a=words[i].size(),b=words[j].size();
                    ans=max(ans, a*b);
                }
            }
        }
        return ans;
        
    }
};