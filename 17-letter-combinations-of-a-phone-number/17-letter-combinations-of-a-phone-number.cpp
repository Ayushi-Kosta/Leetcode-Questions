class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        vector<string> seq {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        deque<string> d;
        d.push_back("");
        int n = digits.size();
        vector<string> v;
        if(n==0){
            return v;
        }
        for(char x : digits){
            int z = x-'0';
            int b =d.size();
            for(int i =0; i<b; i++){
                string a = d.front(); d.pop_front();
                for(char y: seq[z]){
                    d.push_back(a+y);
                } 
            }
        }
        
        return vector<string>(d.begin(), d.end());
    }
};