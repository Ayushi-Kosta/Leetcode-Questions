class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size(), first_1=INT_MAX, last_1=INT_MIN, curr_1=0, curr_1_next=0, ans=0;
        bool found_1=0, found_1_next=0;
        for(int i=0; i<n; i++){
            if(seats[i]==1){
                first_1=min(i, first_1);
                last_1=max(i, last_1);
                if(found_1){
                    if(curr_1_next!=0) curr_1=curr_1_next;
                    curr_1_next=i;  
                    found_1_next=1;
                } 
                else{
                    found_1=1;
                    curr_1=i;
                }
            }
            //cout<<curr_1<<" "<<curr_1_next<<" -- ";
            if(found_1 and found_1_next){
                ans=max(ans, (abs(curr_1_next - curr_1))/2);
                //cout<<"ans-"<<ans<<"//";
            } 
            
        }
        ans=max(ans, first_1);
        ans=max(ans, n-1-last_1);
        return ans;
    }
};