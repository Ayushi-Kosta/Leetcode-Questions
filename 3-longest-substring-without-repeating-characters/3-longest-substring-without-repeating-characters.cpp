class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int n = s.size();
        int start=0, end=0, ans=0;
        while(end<n){
            if(m.find(s[end])==m.end()){
                m[s[end]]++;
                end++;
            }
            else{while(m.find(s[end])!=m.end()){
                    m[s[start]]--;
                    if(m[s[start]]==0){
                        m.erase(s[start]);
                    }
                    start++;
                }
            }
            ans=max(ans, end-start);
        }
        return ans;
    }
};