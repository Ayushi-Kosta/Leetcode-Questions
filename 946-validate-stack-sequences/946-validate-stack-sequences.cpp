class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n = pushed.size();
        if(pushed.size()!=popped.size()){
            return 0;
        }
        int j = 0, i=0;
        while(j<n){
            if(!s.empty()){
                if(popped[j]==s.top()){
                    s.pop();
                    j++;
                }
                else if(j<n and i>=n){
                    return 0;
                }
                else if(i<n){
                    s.push(pushed[i]);
                    i++;
                }                
            }
            else if(i<n){
                s.push(pushed[i]);
                    i++;
            }
//             else if(i<n){
                
//             }
            
        }
        // while(!s.empty()){
        //     cout<<s.top()<<" ";
        //     s.pop();
        // }
        return s.empty();
    }
};