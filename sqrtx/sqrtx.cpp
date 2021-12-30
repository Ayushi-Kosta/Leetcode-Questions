class Solution {
public:
    int mySqrt(int x) 
    {   
        long int beg = 1;
        long int end = x;
        
        long int res = 0;
        
        while(beg <= end)
        {
            long long int mid = (beg+end)/2;
            
            if(mid * mid == x)
            {
                return mid;
            }
            
            if(mid * mid < x)
            { 
                beg = mid+1;
                res = mid;
            }
            
            else
                end = mid-1;
        }
        
        return res;
    }
};