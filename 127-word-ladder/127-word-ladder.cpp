class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), depth=0;
        unordered_set<string> s;
        for(auto &x : wordList){
            s.insert(x);
        }
        queue<string> q;
        q.push(beginWord);
        if(s.find(endWord)==s.end()){
            return 0;
        }
        while(!q.empty()){
            depth++;
            int size = q.size();
            
            while(size--){
                string curr = q.front(); q.pop();
                int n_curr = curr.size();
            for(int i=0; i<n_curr; i++){
                char ori = curr[i];
                for(char j='a'; j<='z'; j++){
                    curr[i]=j;
                    if(curr == endWord){
                        return depth+1;
                    }
                    if(s.find(curr)!=s.end()){
                        s.erase(curr);
                        q.push(curr);
                        
                    }
                }
                curr[i]=ori;
            }
            }
        }
        return 0;
    }
};