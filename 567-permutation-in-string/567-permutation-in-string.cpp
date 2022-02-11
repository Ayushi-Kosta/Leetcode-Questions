class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m1, m2;
        int n1 = s1.size(), n2 = s2.size();
        if(n1>n2){
            return 0;
        }
        for(int i=0; i<n1; i++){
            m1[s1[i]]++;
        }
        for(int i=0; i<n1; i++){
            m2[s2[i]]++;
        }
        int i=0, j=n1;
        while(j<n2){
            if(m1==m2){
                return 1;
            }
            else{
                m2[s2[i]]--;
                if(m2[s2[i]] == 0){
                    m2.erase(s2[i]);
                }
                i++;
                m2[s2[j++]]++;
            }            
        }
        if(m1==m2){
            return 1;
        }
        return 0;
    }
};