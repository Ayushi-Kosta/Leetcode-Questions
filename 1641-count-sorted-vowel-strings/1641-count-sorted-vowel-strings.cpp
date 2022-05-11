class Solution {
public:
    void s(vector<string> &v, string &a, int n, int i, string &vowels){
        if(a.size()==n){
            v.push_back(a);
            // cout<<a<<" ";
            return;
        }
        for(int j=i; j<5; j++){
            a.push_back(vowels[j]);
            s(v, a, n, j, vowels);
            a.pop_back();
        }
        return;
    }
    int countVowelStrings(int n) {
        string vowels = "aeiou", a="";
        vector<string> v;
        int i=0;
        s(v, a, n, i, vowels);
        return v.size();
    }
};