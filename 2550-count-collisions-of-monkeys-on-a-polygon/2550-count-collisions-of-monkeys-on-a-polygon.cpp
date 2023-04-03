class Solution {
public:
    int m = 1e9+7;
    int monkeyMove(int n) {
        long long res=1, base = 2;
        while (n > 0) {
            if (n % 2)
                res = res * base % m;
            base = base * base % m;
            n >>= 1;
        }
        return (res-2+m)%m;
    }
};