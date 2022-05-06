class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        int n = s.size();
        for(auto &x: s){
            if(!st.empty() and st.top().first==x){
                st.top().second++;
            }
            else{
                st.push({x, 1});
            }
            if(st.top().second==k){
                // cout<<st.top().first<<" ";
                st.pop();
            }
            
        }
        s="";
        while(!st.empty()){
            while(st.top().second--) s+=(st.top().first);
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};