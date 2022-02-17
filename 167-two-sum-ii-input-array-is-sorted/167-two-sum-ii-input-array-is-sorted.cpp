class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> m;
        int n = numbers.size();
        vector<int> v;
        for(int i=0; i<n; i++){
            m[numbers[i]]=i+1;
        }
        for(int i=0; i<n; i++){
            if(m[target-numbers[i]]!=0){
                v.push_back(i+1);
                v.push_back(m[target-numbers[i]]);
                break;
            }
        }
        return v;
    }
};