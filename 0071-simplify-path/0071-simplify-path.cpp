class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string ans;
        int n=path.size();
        for(int i=0;i<n;i++){
            if(path[i]=='/') continue;
            string tmp;
            while(i<n && path[i]!='/') 
			  tmp+=path[i++];            
            if(tmp==".") continue;
            else if(tmp==".."){
                  if(!st.empty()) 
                      st.pop();
            }
            else
               st.push(tmp);
            }
        while(!st.empty()){
            ans="/"+ st.top()+ans;
            st.pop();
        }
        
         if(ans.size()==0)return "/";
        
      return ans;
    }
};