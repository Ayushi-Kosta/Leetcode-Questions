class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> a;
        int n = s.size();
        for(int i=0; i<n; i++){
            a[s[i]]++;
            a[t[i]]--;
        }
        a[t[n]]--;
        for(auto &x : a){
            if(x.second!=0){
                return x.first;
            }
            
        }
        return 'a';
    }
};