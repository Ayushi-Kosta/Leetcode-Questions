class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        int words=0, n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]==' '){
                words++;
            }
        }
        words+=1;
        vector<string> v;
        string t="";
        for(int i=0; i<n; i++){
            if(s[i]!=' '){
                t+=s[i];
            }
            else {
                v.push_back(t);
                t="";
            }
        }
        v.push_back(t);
        if(words!=pattern.size()){
            return 0;
        }
        for(int i=0; i<words; i++){
            //cout<<v[i]<<" ";
            if(m1.find(pattern[i]) == m1.end() and m2.find(v[i]) == m2.end()){
                m1[pattern[i]]=v[i];
                m2[v[i]]=pattern[i];
            }
            else if(m1.find(pattern[i]) != m1.end() and m2.find(v[i]) != m2.end()){
                if(m1[pattern[i]]!=v[i]){
                    //cout<<" 1";
                    return 0;
                }
                if(m2[v[i]]!=pattern[i]){
                    //cout<<" 2";
                    return 0;
                }
                
            }
            else{
                return 0;
            }
        }
        //cout<<words<<" ";
        //cout<<" 3";
        return 1;
    }
};