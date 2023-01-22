class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return 0;
            }
            start++; end--;
        }
        return 1;
    }
    void helper(int index, string s, vector<vector<string>> &v, vector<string> &a){
        if(index==s.size()){
            v.push_back(a);
            return ;
        }
        for(int i=index; i<s.size(); ++i){
            if(isPalindrome(s, index, i)){
                a.push_back(s.substr(index, i-index+1));
                helper(i+1, s, v, a);
                a.pop_back();
            }            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> v;
        vector<string> a;
        helper(0, s, v, a);
        return v;
    }
};