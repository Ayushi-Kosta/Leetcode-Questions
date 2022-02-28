class Solution {
public:
    int countOdds(int low, int high) {
        int c=0;
        if(low%2 and high%2){
            c=(high-low+2)/2;
        }
        else{
            c=(high-low+1)/2;
        }
        return c;
    }
};