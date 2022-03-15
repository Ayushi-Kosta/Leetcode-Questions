class Solution {
public:
    string minRemoveToMakeValid(string s) {
//         vector<int> to_rem;
//         int n = s.size(), i=0, j=n-1
//         while(i<j){
//             if(s[i]=='(' and s[j]==')'){
//                 i++; j--;
//             }
//             else if(s[i]==''){
                
//             }
//         }      
        vector<int> to_rem;
        int n = s.size(), i=0, j=n-1;
        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(st.empty() or st.top()!='('){
                    to_rem.push_back(i);
                }
                else{
                    st.pop();
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            if(s[i]==')'){
                st.push(s[i]);
            }
            else if(s[i]=='('){
                if(st.empty() or st.top()!=')'){
                    to_rem.push_back(i);
                }
                else{
                    st.pop();
                }
            }
        }
        sort(to_rem.begin(), to_rem.end());
        string ans;
        j=0;
        // for(int i=0; i<to_rem.size(); i++){
        //     cout<<to_rem[i]<<" ";
        // }
        // cout<<"\n";
        if(to_rem.size()==0){
            return s;
        }
        for(int i=0; i<n; i++){
            if(j<to_rem.size() and i==to_rem[j]){
                j++;
                continue;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;        
    }
};