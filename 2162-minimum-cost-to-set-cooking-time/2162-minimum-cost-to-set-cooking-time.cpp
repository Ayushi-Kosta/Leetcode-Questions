class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetsecond) {
        int minutes = targetsecond/60, secs=targetsecond%60;
        string t1="" , t2="";
        //type 1: normal conversion
        if(minutes==0){
            t1+=to_string(secs);
        }
        else if(minutes==100){
            t1+="99";
            t1+=to_string(secs+60);
        }
        else{
            
            t1+=to_string(minutes);
            if(secs<=9) t1+="0";
            t1+=to_string(secs);
        }
        
        
        //type2: reducinf mnutes by 1 and addong 60 sec to secs
        if(minutes>=1 and minutes<100 and secs<=39){
            if(minutes-1==0){
                t2+=to_string(secs+60);
            }
            else{
                t2+=to_string(minutes-1);
                t2+=to_string(secs+60);
            }
            
        }
        int i=1;
        vector<string> v;
        v.push_back(t1);
        if(t2.size()>0){
            v.push_back(t2);
            i++;
        }
        int ans=INT_MAX;
        while(i--){
            int s=0;
            int n_t1=v[i].size();
            int a = v[i][0]-'0';
            s=pushCost;
            if(startAt != a) s+=moveCost;
            for(int j=1; j<n_t1; j++){
                if(v[i][j]!=v[i][j-1]) s+=moveCost;
                s+=pushCost;
            }
            ans=min(s, ans);
        }
        return ans;
    }
};