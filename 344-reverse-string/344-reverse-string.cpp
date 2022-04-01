class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size(), i=0, j=n-1;
        while(i<j){
            swap(s[i++], s[j--]);
        }
    }
};