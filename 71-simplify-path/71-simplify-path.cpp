class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int n = path.size();
        int i = 0;
        while(i<n){
            if(path[i]=='/'){
                i++;
                continue;
            }
            else{
                // int j = i;
                string temp;
                while(i<n and path[i]!='/'){
                    temp+=path[i];
                    i++;
                }
                //cout<<temp<<" ";
                if(temp=="."){
                    continue;
                }
                else if(temp==".."){
                    if(!s.empty()){
                        s.pop();
                    }
                }
                else{
                    s.push(temp);
                }
                i++;
            }
        }
        
            string res;
            while(!s.empty()){
                res="/"+s.top()+res;
                cout<<s.top()<<" ";
                s.pop();
            }
        if(res.size()==0){
            return "/";
        }
            return res;
        
    }
};