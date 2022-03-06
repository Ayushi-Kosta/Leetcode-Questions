class Solution {
public:
    string reverseWords(string s) {
        int i=0, j=0, n=s.size();
        stack<char> st;
        while(i<n){
            j=i;
            while(j<n and s[j]!=' '){
                st.push(s[j]); j++;
            }
            int z=i;
            while(!st.empty()){
                s[z]=st.top();
                st.pop();
                z++;
            }
            i=j+1;
        }
        return s;
    }
};