class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<int, int> m1, m2;
        int n1 = s1.size(), n2 = s2.size();
        if(n1>n2) return 0;
        for(int i=0; i<n1; i++){
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        int j = 0;
        if(m1==m2) return true;
        for(int i=n1; i<n2; i++){
            m2[s2[j]]--;
            m2[s2[i]]++;
            if(m2[s2[j]]==0){
                m2.erase(s2[j]);
            }
            j++;
            if(m1==m2){
                return 1;
            }
        }
        return 0;
    }
};