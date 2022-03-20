class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> m(6), q(6), same(6);
        for(int i=0; i<6; i++){
            m[i]=0;
            q[i]=0;
            
        }
        int n = tops.size();
        for(int i=0; i<n; i++){
            m[tops[i]-1]++;
            q[bottoms[i]-1]++;
            if(tops[i]==bottoms[i]){
                same[tops[i]-1]++;
            }
            // cout<<tops[i]<<" "<<m[tops[i]][0]<<" - "<<bottoms[i]<<" "<<m[bottoms[i]][1]<<" || ";
        }
        for(int i=0; i<6; i++){
            if(m[i]+q[i]-same[i]==n){
                return n-max(m[i], q[i]);
            }
            // cout<<tops[i]<<" "<<m[tops[i]][0]<<" - "<<bottoms[i]<<" "<<m[bottoms[i]][1]<<" || ";
        }
        return -1;
    }
};