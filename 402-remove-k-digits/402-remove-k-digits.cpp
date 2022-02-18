class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> v;
        int n = num.size(), curr = k;
        if(num.size()<=k){
            return "0";
        }
        for(int i=0; i<n; i++){
            while(v.size() and curr and v.back()>(num[i]-'0')){
                v.pop_back();
                curr--;
            }
            v.push_back(num[i]-'0');
        }
        string s;
        
        while(curr) {
            curr--;
            v.pop_back();
        }
        bool t=1;
        if(v.size()==0){
            return "0";
        }
        for(int i=0; i<v.size(); i++){
            if(t and v[i]==0){
                t=1;
            }
            else{
                t=0;
            }
            if(!t) s+=(v[i]+'0');
        }
        if(t==1){
            return "0";
        }
        return s;
    }
};