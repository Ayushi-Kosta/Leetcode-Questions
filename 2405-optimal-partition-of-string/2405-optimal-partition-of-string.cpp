class Solution {
public:
    int partitionString(string s) {
        int i=0, n = s.size(), c=0;
        while(i<n){
            unordered_set<char> st;
            while(i<n and (st.empty() or st.find(s[i])==st.end())){
                st.insert(s[i]);
                i++;                
            }
            c++;
        }
        return c;
    }
};