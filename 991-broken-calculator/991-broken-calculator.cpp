class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int n = target, c=0;
        if(startValue>target){
            return (startValue-target);
        }
        while(n>startValue){
            if(n%2==0){
                n/=2;
            }
            else{
                n+=1;
            }
            c++;
            cout<<n<<" ";
        }
        c+=(startValue - n);
        return c;
    }
};