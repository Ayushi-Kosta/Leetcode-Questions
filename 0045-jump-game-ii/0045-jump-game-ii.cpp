class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int steps_count = 0, start = 0, end = 0;
        while (end < n - 1) {
            steps_count++; 
			int max_end = end + 1;
			for (int i = start; i <= end; i++) {
                if (i + nums[i] >= n - 1) 
                    return steps_count;
				max_end = max(max_end, i + nums[i]);
			}
            start = end + 1;
            end = max_end;
        }
		return steps_count;
    }
};