class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int begin1=0, end1=a.size();
        int n1=a.size(), n2=b.size();
        if(n1==0 or n2==0){
            if(n1==0){
                if(n2%2!=0){
                    return b[(n2/2)];
                }
                else{
                    return ((double)b[n2/2]+(double)b[(n2/2)-1])/2;
                }
            }
            else{
                if(n1%2!=0){
                    return a[n1/2];
                }
                else{
                    return ((double)a[n1/2]+(double)a[(n1/2)-1])/2;
                }
            }
        }
        if(n1>n2){
            return findMedianSortedArrays(b, a);
        }
        while(begin1<=end1){
            
            int i1=(begin1+end1)/2;
            int i2=(n1+n2+1)/2 -i1;
            int max1=(i1==0)? INT_MIN: a[i1-1];
            int min1=(i1==n1)?INT_MAX: a[i1];
            int max2=(i2==0)? INT_MIN: b[i2-1];
            int min2=(i2==n2)?INT_MAX: b[i2];
            if((max1<=min2) and (max2<=min1)){
                if((n1+n2)%2==0){
                    return ((double)min(min1, min2)+(double)max(max1, max2))/2;
                }
                else{
                    return ((double)max(max1, max2));
                }
            }
            else if(max1>min2){
                end1=i1-1;
            }
            else{
                begin1=i1+1;
            }
        }
        return (double)(-1);
    }
};