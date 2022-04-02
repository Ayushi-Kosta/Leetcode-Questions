class Solution {
public:
    // bool validPalindrome(string s) {
    //     int i=0, j = s.size()-1;
    //     bool t=1;
    //     while(i<j){
    //         if(t and s[i]!=s[j]){
    //             if(s[i+1]==s[j]){
    //                 i++;
    //                 t=0;
    //             }
    //             else if(s[j-1]==s[i]){
    //                 j--;
    //                 t=0;
    //             }
    //             else{
    //                 return 0;
    //             }
    //         }
    //         else if(s[i]==s[j]){
    //             i++;
    //             j--;
    //         }
    //         else if(!t){
    //             return 0;
    //         }
    //     }
    //     return 1;
    // }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while(i <= j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
        }
        return true;
    }
    bool isPalindrome(string s, int i, int j){
        while(i <= j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};