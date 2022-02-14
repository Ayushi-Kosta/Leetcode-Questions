class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int i=0, j=0, ans=0, n=s.size();
        while(i<n){
            if(m.find(s[i])==m.end()){
                m[s[i]]++;
                i++;
            }
            else{
                while(m.find(s[i])!=m.end()){
                    m[s[j]]--;
                    if(m[s[j]]==0){
                        m.erase(s[j]);
                    }
                    j++;
                }
            }
            ans=max(ans, (i-j));
        }
        return ans;
    }
};