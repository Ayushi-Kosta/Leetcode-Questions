class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stack;
        int cur = 0;
        for (char i : s)
            if (i == '(') {
                stack.push(cur);
                cur = 0;
            }
            else {
                cur += stack.top() + max(cur, 1);
                stack.pop();
            }
        return cur;
    }
        
    // int scoreOfParentheses(string s) {
    //     int i = 1, n = s.size();
    //     stack<char> st;
    //     int a = 0, ans=0;
    //     for(int j=0; j<n; j++){             
    //         if(s[j]=='('){
    //             st.push(s[j]);
    //             if(a==1){
    //                 ans++;
    //             }
    //             a=0;
    //         }
    //         else{
    //             if(st.top()=='('){
    //                 a=1;
    //                 st.pop();
    //             }
    //             else{
    //                 a*=2;
    //                 ans+=a;  
    //             }                
    //         }            
    //     }
    //     ans+=a;
    //     return ans;
    // }
};