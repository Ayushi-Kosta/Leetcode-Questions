class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        if(haystack.size()<needle.size()) return -1;
        for(int j=0; j<=haystack.size()-needle.size(); j++){
            int k=j;
            if(haystack[k]==needle[i]){
                while(haystack[k]==needle[i] and i<needle.size()){
                    k++; i++;
                }
                if(i==needle.size()){
                    return j;
                }
                
            }
            i=0;
        }
        return -1;
    }
};