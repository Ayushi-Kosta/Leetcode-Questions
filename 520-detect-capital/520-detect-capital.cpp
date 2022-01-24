class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        bool t=0, s=1, u=1, v=1;
        if(isupper(word[0])){
            t=1;
        }
        if(t){
            for(int i=1; i<n; i++){
               if(!isupper(word[i])){
                   s = 0;
                   break;
               }
            }
            for(int i=1; i<n; i++){
               if(isupper(word[i])){
                   u = 0;
                   break;
               }
            }
            if(u or s){
                return 1;
            }
        }
        else{
            for(int i=0; i<n; i++){
                if(isupper(word[i])){
                    v=0;
                    break;
                }
            }
            return v;
        }
        return 0;
        
    }
};