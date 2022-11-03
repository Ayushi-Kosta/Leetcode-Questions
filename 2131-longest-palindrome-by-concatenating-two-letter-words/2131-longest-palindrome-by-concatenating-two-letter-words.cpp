class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> w;
        int n = words.size(), ans=0;
        for(int i=0; i<n; i++){
            w[words[i]]++;
        }
        bool flag=0;
        for(int i=0; i<n; i++){
            string s;
            s+=words[i][1];
            s+=words[i][0];
            
            if(words[i][0]!=words[i][1] and w.find(s)!=w.end()){
                ans+=(4*min(w[s], w[words[i]]));
                w.erase(s);
                w.erase(words[i]);
            }
            else if(words[i][0]==words[i][1]){
                if(w[words[i]]%2!=0 and !flag ){
                    ans+=2*(w[words[i]]);
                    w.erase(words[i]);
                    flag=1;
                }
                else if(w[words[i]]%2==0){
                    ans+=2*(w[words[i]]);
                    w.erase(words[i]);
                }
                else if(w[words[i]]%2!=0){
                    ans+=2*(w[words[i]]-1);
                    w.erase(words[i]);
                }
                
            }
            
            // cout<<words[i]<<" "<<words[i][0]<<" "<<words[i][1]<<" "<<s<<" "<<ans<<" | ";
        }
        return ans;
    }
};