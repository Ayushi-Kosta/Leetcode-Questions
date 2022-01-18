class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int nf = f.size(), i=0, pos=0;
        while(i<nf){
            if(f[i]==0 and (i==nf-1 or f[i+1]==0) and (i==0 or f[i-1]==0)){       
                pos++;
                i+=2;
            }
            else i++;
        }
        //cout<<pos;
        if(pos>=n){
            return 1;
        }
        return 0;
    }
};