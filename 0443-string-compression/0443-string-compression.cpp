class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> v;
        int i=0, n=chars.size();
        if(n==1) return 1;
        while(i<n){
            int j=i;
            int c=0;
            while(j<n and chars[i]==chars[j]){
                c++;
                j++;
            }
            cout<<c<<" ";
            if(c==1){
                v.push_back(chars[i]);
            }
            else{
                v.push_back(chars[i]);
                vector<char> s;
                while(c){
                    char a = (c%10)+'0';
                    s.push_back(a);
                    c=c/10;
                    // cout<<a<<" ";
                }
                reverse(s.begin(), s.end());
                v.insert( v.end(), s.begin(), s.end());
            }
            
            i=j;            
        }
        chars=v;
        return v.size();
                
    }
};