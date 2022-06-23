class Solution {
public:
    static bool mysort(vector<int> &A, vector<int> &B){
        if(A[1]==B[1]){
            return A[0]<B[0];
        }
        return A[1]<B[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int day = 0, c=0, n = courses.size(), i=0;
        sort(courses.begin(), courses.end(), mysort);
        priority_queue<int> pq;
        while(i<n){
            day+=courses[i][0];
            pq.push(courses[i][0]);
            if(day>courses[i][1]){
                day-=pq.top();
                pq.pop();
            }
            i++;
        }
        return pq.size();
        
    }
};