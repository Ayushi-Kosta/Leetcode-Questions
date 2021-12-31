class Solution {
public:
    int mySqrt(int x) 
    {    long long low = 1, high = x;
        long long ans = 0;
        while(low <= high) {
            long long mid = low + (high-low)/2;
            if(mid*mid == x) 
                return mid;
            else if(mid*mid<x) {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
        
        
        
//         long int beg = 1;
//         long int end = x;
        
//         long int res = 0;
        
//         while(beg <= end)
//         {
//             long long int mid = (beg+end)/2;
            
//             if(mid * mid == x)
//             {
//                 return mid;
//             }
            
//             if(mid * mid < x)
//             { 
//                 beg = mid+1;
//                 res = mid;
//             }
            
//             else
//                 end = mid-1;
//         }
        
//         return res;
    }
};