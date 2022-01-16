class Solution {
public:
    int maxDistToClosest(vector<int>& arr) {
        
//     int res = INT_MIN , ans = 0, n=arr.size();

//     if(arr[0] == 1){

//     for(int i=1; i < n; i++){

//             if(arr[i] == 1){
//                 ans = i + 1 - ans;
//                 res = max(res,ans);
//             }
        
//     }

//     }

    bool f =0;
    int ans=0, n=arr.size();
    int ind_1=0, ind_2=0, first_1=INT_MAX, last_1=INT_MIN;
    for(int i=0; i<n; i++){
        if(f==0 and arr[i]==1){
            ind_1=i;
            f=1;
        }
        if(f==1 and arr[i]==1){
            ind_2=ind_1;
            ind_1=i;
            ans=max(ans, abs(ind_2-ind_1)/2);
        }
        
        if(arr[i]==1){
            first_1=min(first_1, i);
            last_1=max(last_1, i);
        }
    }
    ans=max(ans, (first_1));
    ans=max(ans, (n-1-last_1));
    return ans;
        
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
    }
};