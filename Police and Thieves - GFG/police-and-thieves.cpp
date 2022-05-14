// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
        vector<int> police, thief;
        for(int i=0; i<n; i++){
            if(arr[i]=='P') police.push_back(i);
            else thief.push_back(i);
        }
        int i=0, j=0, c=0;
        while(i<police.size() and j<thief.size()){
            if(abs(thief[j]-police[i])<=k){
                j++; c++; i++;
            }
            else if(police[i]>thief[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return c;
    }

};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 

  // } Driver Code Ends