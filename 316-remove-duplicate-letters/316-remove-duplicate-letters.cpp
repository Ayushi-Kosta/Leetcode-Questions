class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        bool present[26]={};
        int last_pos[26]={};
        for(int i=0; i<n; i++){
            last_pos[s[i]-'a'] = i;
        }
        string ans;
        for(int i=0; i<n; i++){
            if(present[s[i]-'a']){
                continue;
            }
            while(ans!="" and ans.back()>s[i] and last_pos[ans.back()-'a']>i){
                present[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            present[s[i]-'a']=1;
        }
        return ans;
    }
};