class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        int n = s.size();
        if(n%2==1) return 0;
        for(int i=0; i<n; i++){
            if(s[i]=='(' or s[i]=='[' or s[i]=='{'){
                a.push(s[i]);
            }
            else{
                if(a.empty()==1){
                    return 0;
                }
                char x = a.top();
                if(x=='('){
                    if(s[i]!=')'){
                        return 0;
                    }
                    else{
                        a.pop();
                    }
                }
                else if(x=='['){
                    if(s[i]!=']'){
                        return 0;
                    }
                    else{
                        a.pop();
                    }
                }
                else if(x=='{'){
                    if(s[i]!='}'){
                        return 0;
                    }
                    else{
                        a.pop();
                    }
                }
            }
        }
        if(a.size()==0) return 1;
        return 0;
    }
};