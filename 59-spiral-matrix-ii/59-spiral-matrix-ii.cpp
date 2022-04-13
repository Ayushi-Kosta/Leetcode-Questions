class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i1=0, i2=n-1, j1=0, j2=n-1;
        vector<vector<int>> v(n, vector<int> (n));
        int a = 1;
        while(a<=n*n){
            //left to right
            for(int w=j1; w<=j2; w++){
                v[i1][w]=a;
                a++;
            }
            i1++;
            //top to bottom
            for(int w=i1; w<=i2; w++){
                v[w][j2]=a;
                a++;
            }
            j2--;
            //right to left
            for(int w=j2; w>=j1; w--){
                v[i2][w]=a;
                a++;
            }
            i2--;
            //bottom to top
            for(int w=i2; w>=i1; w--){
                v[w][j1]=a;
                a++;
            }
            j1++;
        }
        return v;
    }
};