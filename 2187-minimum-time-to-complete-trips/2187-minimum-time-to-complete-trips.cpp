class Solution {
public:
    bool helper(vector<int>& time, int totalTrips, long long totaltime){
        long long tt=0;
        for(int i=0; i<time.size(); i++){
            long long xx = time[i];
            tt+=(totaltime/(xx));
        }
        if(tt>=totalTrips) return 1;
        return 0;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=0, r=(long long)totalTrips*time[0], timeee=r;
        while(l<=r){
            long long mid = l+(r-l)/2;
            bool t = helper(time, totalTrips, mid);
            if(t){
                timeee=min(timeee, mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return timeee;
    }
};