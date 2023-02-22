class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0;
        int r = 25000000;
        for (int w: weights)
            l = max(l, w);
        while (l < r) {
            int mid = (l + r) / 2, need = 1, cur = 0;
            for (int i = 0; i < weights.size() && need <= days; cur += weights[i++])
                if (cur + weights[i] > mid) cur = 0, need++;
            if (need > days) 
                l = mid + 1;
            else 
                r = mid;
        }
        return l;
    }
};