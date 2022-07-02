class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int hi=0, wi=0, hh=horizontalCuts.size(), ww=verticalCuts.size();
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for(int i=0; i<hh; i++){
            if(i==0){
                hi=max(hi, horizontalCuts[i]-0);
            }
            else{
                hi=max(hi, horizontalCuts[i]-horizontalCuts[i-1]);
            }
            if(i==hh-1){
                hi=max(hi, h-horizontalCuts[i]);
            }
            // cout<<hi<<" ";
        }
        // cout<<"\n";
        for(int i=0; i<ww; i++){
            if(i==0){
                wi=max(wi, verticalCuts[i]-0);
            }
            else{
                wi=max(wi, verticalCuts[i]-verticalCuts[i-1]);
            }
            if(i==ww-1){
                wi=max(wi, w-verticalCuts[i]);
            }
            // cout<<wi<<" ";
        }
        // cout<<hi<<" "<<wi<<" | ";
        int m = 1e9+7;
        hi=hi%(m);
        wi=wi%(m);
        // return 0;
        return (1LL * hi*wi)%m;
        
    }
};