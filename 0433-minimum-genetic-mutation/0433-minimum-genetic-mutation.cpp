class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> banks, visited;
        for(int i=0; i<bank.size(); i++){
            banks.insert(bank[i]);
        }
        if(banks.find(endGene)==banks.end()){
            return -1;
        }
        queue<string> q;
        int ans=0;
        q.push(startGene);
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                string cur = q.front();
                q.pop();
                visited.insert(cur);
                if(cur==endGene){
                    return ans;
                }
                for(int i=0; i<8; i++){
                    
                    string c = cur;
                    
                    c[i]='A';
                    if(visited.find(c)==visited.end() and banks.find(c)!=banks.end()){
                        q.push(c);
                    }
                    c[i]='C';
                    if(visited.find(c)==visited.end() and banks.find(c)!=banks.end()){
                        q.push(c);
                    }
                    c[i]='G';
                    if(visited.find(c)==visited.end() and banks.find(c)!=banks.end()){
                        q.push(c);
                    }
                    c[i]='T';
                    if(visited.find(c)==visited.end() and banks.find(c)!=banks.end()){
                        q.push(c);
                    }
                    
                }   
            }
            ans++; 
                        
        }
        return -1;
    }
};