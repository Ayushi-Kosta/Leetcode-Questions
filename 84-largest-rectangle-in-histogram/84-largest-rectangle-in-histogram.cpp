class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s, t;
        vector<int> l(n), r(n);
        l[0]=0; r[n-1]=n-1;
        for(int i=0; i<n; i++){
            while(!s.empty() and heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty()) l[i]=s.top();
             else l[i]=-1; 
            s.push(i);
        }
        
        for(int i=n-1; i>=0; i--){
            while(!t.empty() and heights[t.top()]>=heights[i]){
                t.pop();
            }
            if(!t.empty()) r[i]=t.top();
            else r[i]=n;
            t.push(i);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            int curr = heights[i] + ((i-l[i]-1)*heights[i]) + ((r[i]-i-1)*heights[i]);
            
            ans=max(ans, (curr));
        }
       
        return ans;
    }
};