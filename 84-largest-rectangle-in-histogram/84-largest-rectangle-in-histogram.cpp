class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int maximum_area = 0;
        for(int i=0; i<=n; i++){
            while(!s.empty() and (i==n or heights[s.top()] >= heights[i])){
                int height = heights[s.top()];
                s.pop();
                int width;
                if(s.empty()){
                    width = i;
                }
                else{
                    width = i-s.top()-1;
                }
                maximum_area = max(maximum_area, width*height);
            }
                  s.push(i);
        }
        return maximum_area;
                
    }
};