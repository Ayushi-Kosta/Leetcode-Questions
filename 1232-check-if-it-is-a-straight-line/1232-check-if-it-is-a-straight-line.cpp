class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int n = c.size();
        int y = (c[n-1][1]-c[0][1]), x = (c[n-1][0]-c[0][0]);
        int slope;
        bool t =0;
        if(x==0){
            t=1;
        }
        else slope = y/x;
        
        // cout<<slope;
        for(int i=1; i<n; i++){
            int xt = (c[i][0]-c[i-1][0]), yt = (c[i][1]-c[i-1][1]);
            if(t){
                if(xt!=0){
                    return 0;
                }
            }
            int slope_temp;
            
            if(!t){
                if(xt==0) return 0;
                slope_temp = yt/xt;
                if(slope_temp!=slope) return 0;
            }
        }      
        
        return 1;
    }
};