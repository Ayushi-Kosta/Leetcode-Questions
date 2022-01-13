class Solution {
public:
    int minSwaps(vector<int>& a) {
        int end=0, ans=INT_MAX, total=0;
        for(int i=0; i<a.size(); i++){
            if(a[i]==1){
                total++;
            }
        }
        vector<int>b=a;
        for(int i=0; i<a.size(); i++){
            b.push_back(a[i]);
        }
        int i=0, n=b.size(), c=0;
        //cout<<total<<" ";
        for(int j=i; j<i+total; j++){
            if(b[j]==0){
               c++;
            }
        }
        ans=min(ans, c);
        i+=(total);
        while(i<n){
            if(b[i]==0){
                c++;
            }
            if(b[i-total]==0){
                c--;
            }
            //cout<<c<<" ";
            ans=min(c, ans);
            i++;
        }
        return ans;
    }
};