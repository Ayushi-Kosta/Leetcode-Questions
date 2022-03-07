class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int n1 = w1.size(), n2 = w2.size();
        int i=0, j=0;
        string s;
            while(i<n1 and j<n2){
                s+=(w1[i++]);
                s+=w2[j++];
            }
            while(i<n1){
                s+=w1[i++];
            }
            while(j<n2){
                s+=w2[j++];
            }
            
        
        return s;
    }
};