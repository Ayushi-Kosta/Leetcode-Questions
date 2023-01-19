class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int K) {
        vector<int> count(K);
        count[0] = 1;
        int p = 0, res = 0;
        for (int &a : nums) {
            p = (p + a % K + K) % K;
            res += count[p]++;
        }
        return res;
    }
};