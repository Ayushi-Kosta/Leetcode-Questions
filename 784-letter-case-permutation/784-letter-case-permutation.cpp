class Solution {
public:
    set<string> a;
    void st(string s, int i){
        if(i==s.size()){
            a.insert(s);
            return;
        }  
        st(s, i+1);
        s[i]=toupper(s[i]);
        st(s, i+1);
        
    }
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        for(int i=0; i<n; i++){
            s[i] = tolower(s[i]);
        }
        a.insert(s);
        st(s, 0);
        vector<string> v;
        for(auto &c: a){
            v.push_back(c);
        }
       
        return v;
    }
};