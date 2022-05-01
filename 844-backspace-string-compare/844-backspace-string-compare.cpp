class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> a, b;
        int n_s=s.size(), nt=t.size();
        for(int i=0; i<n_s; i++){
            if(s[i]!='#'){
                a.push_back(s[i]);
            }
            else if(a.size()>=1 and s[i]=='#'){
                a.pop_back();
            }
            
        }
         for(int i=0; i<nt; i++){
            if(t[i]!='#'){
                b.push_back(t[i]);
            }
            else if(b.size()>=1 and t[i]=='#'){
                b.pop_back();
            }
            
        }
        return a==b;
    }
};