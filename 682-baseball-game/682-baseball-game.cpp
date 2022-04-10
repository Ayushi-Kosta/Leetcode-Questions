class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        int n = ops.size();
        for(int i=0; i<n; i++){
            if(ops[i]=="C"){
                v.pop_back();
            }
            else if(ops[i]=="D"){
                int i=v.size();
                int a = v[i-1];
                v.push_back(a*2);
            }
            else if(ops[i]=="+"){
                int i=v.size();
                int a = v[i-1], b=v[i-2];
                v.push_back(a+b);
            }
            else{
                v.push_back(stoi(ops[i]));
            }
        }
        int ans=0;
        for(int i=0; i<v.size(); i++){
            ans+=v[i];
        }
               return ans;
    }
};