class Solution {
public:
    int find_parent(int a, vector<int> parent){
        if(parent[a]==a) return parent[a];
        parent[a]= find_parent(parent[a], parent);
        return parent[a];
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for(int i=0; i<26; i++){
            parent[i]=i;
        }
        int n=s1.size();
        for(int i=0; i<n; i++){
            int first = find_parent(s1[i]-'a', parent), second= find_parent(s2[i]-'a',parent);
            parent[max(first, second)]=min(first, second);
        }
        
        for(int i=0; i<baseStr.size(); i++){
            int parents = find_parent(baseStr[i]-'a', parent);
            baseStr[i] = parents+'a';
        }
        return baseStr;
        
    }
};