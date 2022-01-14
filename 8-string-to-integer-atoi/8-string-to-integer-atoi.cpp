class Solution {
public:
    int myAtoi(string s) {
        int i=0, n=s.size();
        char sign='+';
        bool t=1, digitstart=0;
        string a;
        while(i<n){
            if(t and !digitstart and s[i]==' '){
                i++;
                continue;
            }
            if(s[i]>='0' and s[i]<='9'){
                a+=s[i];
                i++;
                digitstart=1;
            }
            else if(!digitstart and t and s[i]=='-'){
                sign='-';
                i++;
                t=0;
            }
            else if(!digitstart and t and s[i]=='+'){
                sign='+';
                i++;
                t=0;
            }
            else{
                break;
            }
        }
        //cout<<a<<" ";
        long long ans=0;
        int na=a.size(), j=0;
        while(j<na){
            
            ans*=10;
            
            ans+=a[j]-'0';
            j++;
            if(sign=='-' and ans>pow(2, 31)){
                ans=pow(2, 31);
                break;
            }
            else if(sign=='+' and ans>pow(2, 31)-1){
                ans=pow(2, 31)-1;
                break;
            }
        }
        if(sign=='-'){
            return -ans;
        }
        return ans;

    }
};