class Solution {
public:
    // int minCostConnectPoints(vector<vector<int>>& points) {
    //     int v = points.size(), key[v], res=0;
    //     for(int i=0; i<v; i++){
    //         key[i]=INT_MAX;
    //     }
    //     key[0]=0;
    //     bool MST[v];
    //     for(int i=0; i<v; i++){
    //         MST[i]=0;
    //     }
    //     for(int c = 0; c<v; c++){
    //         int w = -1;
    //         for(int e = 0; e<v; e++){
    //             if(MST[e]==0 and (w==-1 || key[e]<key[w])){
    //                 w=e;
    //             }
    //         }
    //         MST[w]=1;
    //         res=res+key[w];
    //         for(int i=0; i<v; i++){
    //             if(points[w][i]!=0 and MST[i]==0){
    //                 key[i] = min(key[i], (points[w][i]-));
    //             }
    //         }
    //     }
    //     return res;
    // }
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
//         vector<bool> mst(n, false);
//         heap.push({0, 0});
        
//         int remaining = 0, minCost = 0;
//         while(remaining<n) {
//             pair<int, int> topElement = heap.top();
//             heap.pop();
            
//             int weight = topElement.first;
//             int currNode = topElement.second;
//             if(mst[currNode]) continue;
            
//             mst[currNode] = true;
//             minCost += weight;
//             remaining++;
            
//             for(int nextNode = 0; nextNode < n; nextNode++) {
//                 if(mst[nextNode]) continue;
//                 int weight = abs(points[currNode][0] - points[nextNode][0]) +
//                                 abs(points[currNode][1] - points[nextNode][1]);
//                 heap.push({weight, nextNode});
//             }
//         }
//         return minCost;
//     }
    
    
    // int minCostConnectPoints(vector<vector<int>>& points) {
    //     int n = points.size();
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //weight, vertex  - min heap
    //     pq.push({0,0});
    //     //we maintain MST set so that no vertex is counted twice and frms a cycle
    //     vector<bool> visited(n, false);
    //     int mst_vertex=0, weight=0;
    //     while(mst_vertex<n){
    //         pair<int, int> w = pq.top(); pq.pop();
    //         int curr = w.second;
    //         if(!visited[curr]){
    //             weight+=(w.first);
    //             visited[w.second]=true;
    //             mst_vertex++;
    //         }
    //         for(int s=0; s<n; s++){
    //             int w = abs(points[curr][0]-points[s][0]) + abs(points[curr][1]-points[s][1]);
    //             if(visited[s]==false) pq.push({w, s});
    //         }
    //     }
    //     return weight;
    // }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> pq(n, INT_MAX); //weight, vertex  - min heap
        //we maintain MST set so that no vertex is counted twice and frms a cycle
        pq[0]=0;
        vector<bool> visited(n, false);
        int mst_vertex=0, weight=0;
        while(mst_vertex<n){
            int curr_node=-1, curr_w=INT_MAX;
            for(int i=0; i<n; i++){
                if(visited[i]==false and curr_w>pq[i]){
                    curr_w=pq[i];
                    curr_node=i;
                }
            }
            int curr = curr_node;
            if(!visited[curr]){
                weight+=(curr_w);
                visited[curr_node]=true;
                mst_vertex++;
            }
            for(int s=0; s<n; s++){
                int w = abs(points[curr][0]-points[s][0]) + abs(points[curr][1]-points[s][1]);
                if(visited[s]==false) {
                    pq[s]=min(pq[s], w);
                }
            }
        }
        return weight;
    }
};