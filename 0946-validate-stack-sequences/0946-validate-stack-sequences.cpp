class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i=0, j=0;
        stack<int> st;
        while(i<n and j<n){
            
            if(!st.empty() and st.top()==popped[j]){
                st.pop();
                // cout<<"pop "<<popped[j]<<" ";
                j++;
                
            }
            else if(i<n){
                st.push(pushed[i++]);
                // cout<<"push "<< pushed[i-1]<<" ";
            }
        }
        if(i!=n) return 0;
        while(j<n){
            if(!st.empty() and st.top()==popped[j]){
                st.pop();
                j++;
            }
            else if(!st.empty()) return 0;
        }
        return st.empty();
        
    }
};