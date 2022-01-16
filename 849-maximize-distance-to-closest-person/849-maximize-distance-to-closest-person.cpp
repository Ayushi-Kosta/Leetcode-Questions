class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
//         int n=seats.size(), first_1=INT_MAX, last_1=INT_MIN, curr_1=0, curr_1_next=0, ans=0;
//         bool found_1=0, found_1_next=0;
//         for(int i=0; i<n; i++){
//             if(seats[i]==1){
//                 first_1=min(i, first_1);
//                 last_1=max(i, last_1);
//                 if(found_1){
//                     if(curr_1_next!=0) curr_1=curr_1_next;
//                     curr_1_next=i;  
//                     found_1_next=1;
//                 } 
//                 else{
//                     found_1=1;
//                     curr_1=i;
//                 }
//             }
//             if(found_1 and found_1_next){
//                 ans=max(ans, (abs(curr_1_next - curr_1))/2);
//             } 
            
//         }
//         ans=max(ans, first_1);
//         ans=max(ans, n-1-last_1);
//         return ans;
        int n = seats.size(), longestEmpty = 1;
        int len = 0;
        int first_1=INT_MAX, last_1=INT_MIN;
        bool found_1=0;
        for(int i = 0; i<n; i++) {
            //cout<<len<<" ";
            if(seats[i] == 0) {
                len++;
            }
            if(seats[i] and len) {
                longestEmpty = max(longestEmpty, (len+1)/2);
                len = 0;
            }
            if(seats[i]==1 and !found_1){
                first_1=i;
                found_1=1;
            }
            if(seats[i]==1){
                last_1=max(last_1, i);
               
            }
        }
        //cout<<len<<" --- ";
        longestEmpty = max(longestEmpty, (len+1)/2);
        //cout<<longestEmpty<<" ";
        longestEmpty = max(longestEmpty, first_1);
        //cout<<longestEmpty<<" ";
        longestEmpty = max(longestEmpty, n-1-last_1);
        //cout<<longestEmpty<<" ";
        return (longestEmpty);
    }
};