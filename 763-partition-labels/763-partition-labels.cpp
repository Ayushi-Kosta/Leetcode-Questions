class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26), ans;
        int n = s.size();
        for(int i=0; i<n; i++){
            last[s[i]-'a']=i;
        }
        int end=0, start=0;
        for(int i=0; i<n; i++){
            end=max(end, last[s[i]-'a']);
            if(end==i){
                ans.push_back(end-start+1);
                start=end+1;
                end++;
            }
        }
        return ans;
    }
};