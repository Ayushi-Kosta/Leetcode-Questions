class Solution {
public:
    vector<string> a;
    void st(string s, int i){
        if(i==s.size()){
            // a.insert(s);
            a.push_back(s);
            return;
        }  
        st(s, i+1);
        if(s[i]>='a' and s[i]<='z'){
            s[i]=toupper(s[i]);
            st(s, i+1);    
        }
        
        
    }
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        for(int i=0; i<n; i++){
            s[i] = tolower(s[i]);
        }
        // a.insert(s);
        // a.push_back(s);
        st(s, 0);
        // vector<string> v;
        // for(auto &c: a){
        //     v.push_back(c);
        // }
       
        return a;
    }
};