class Solution {
public:
    bool ispalindrome(string s, int i, int j, int n){
        while(i<j){
            if(s[i]!=s[j]){
                return 0;
            }
            else{
                i++;
                j--;
            }
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int n=s.size(), i=0, j=n-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return ispalindrome(s, i+1, j, n) || ispalindrome(s, i, j-1, n);
            }
        }
        return 1;
    }
};