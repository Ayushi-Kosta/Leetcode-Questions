class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n_s=s.size(), n_p=p.size();
        string a ;
        vector<int> v;
        if(n_p > n_s){
            return v;
        }
        unordered_map<char, int> m1, m2;
        for(int i=0; i<n_p; i++){
            a+=s[i];
            m1[s[i]]++;
            m2[p[i]]++;
        }
        bool t=1;
        for(int j=0; j<n_p; j++){
            if(m1[p[j]]!=m2[p[j]]){
                t=0;
                break;
            }
        }
        if(t){
            v.push_back(0);
        }
        int i=n_p;
        for(i=n_p; i<n_s; i++){
            if(m1[s[i-n_p]] == 1){
                m1.erase(s[i-n_p]);
            }
            else{
                m1[s[i-n_p]]--;
            }
            m1[s[i]]++;
            if(m1 == m2){
                v.push_back(i-n_p+1);
            }
            // bool t=1;
            // for(int j=0; j<n_p; j++){
            //     if(m1[p[j]]!=m2[p[j]]){
            //         t=0;
            //         break;
            //     }
            // }
            // if(t){
            //     v.push_back(i-n_p+1);
            // }
        }
        return v;
    }
};