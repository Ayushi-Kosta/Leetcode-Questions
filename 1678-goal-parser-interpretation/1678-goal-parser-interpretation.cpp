class Solution {
public:
    string interpret(string c) {
        string s ;
        int n = c.size(), i=0;
        while(i<n){
            if(c[i]=='(' and c[i+1]==')'){
                s+="o";
                i++;
            }
            else if(c[i]=='(' or c[i]==')'){
                i++;
            }
            else{
                s+=c[i++];
            }
        }
        return s;
    }
};