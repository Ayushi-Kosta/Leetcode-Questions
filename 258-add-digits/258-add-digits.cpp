class Solution {
public:
    int s(int num){
        int sum=0;
        while(num){
            sum+=(num%10);
            num/=10;
        }
        if(sum<10){
            return sum;
        }
        else{
            return s(sum);
        }
        
        
    }
    int addDigits(int num) {
        return s(num);
    }
};