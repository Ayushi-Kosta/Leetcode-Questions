class Solution {
public:
//     string dp[31];
//     void rec(int n){
//         if(n==0){
            
//             return;
//         }
//         if(n==1){
//             dp[1]="1";
//             return ;
//         }
//         if(n==2){
//             dp[2]="11";
//             return;
//         }
//         else{
//             rec(n-1);
            
//             string s="";
//         int a=dp[n-1].size(), count=1, i=1;
//         while(i<a){
//             while(dp[n-1][i-1]==dp[n-1][i]){
//                 count++;
//                 i++;
//             }
//             s+=(count+'0');
//             s+=(dp[n-1][i-1]);
//             count=0;
//         }
//         dp[n]=s;    
            
//         }
        
        
//     }
    string countAndSay(int n) {
        string ans="1";
        
            while(--n){
                string s="";
                int z=ans.size();
                for(int i=0; i<z; i++){
                    int count=1;
                    while(i+1<z and ans[i]==ans[i+1]){
                        count++;
                        i++;
                    }
                    s+=(count+'0');
                    s+=(ans[i]);
                }
                ans=s;
            }
        
        return ans;
    }
};