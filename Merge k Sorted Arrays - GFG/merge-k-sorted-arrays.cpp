//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++




typedef pair<int, pair<int, int>> pi;

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
    
        priority_queue< pi, vector<pi>, greater<pi> >pq;
    
        //Step 1
        // Pushing all first element of all SubArrays in Min Heap.
        int size = arr.size();
        for(int i=0; i<size; i++)
        {
            pq.push({arr[i][0], {i, 0}});
        }
    
        //Step2 
       // Iterate in Min Heap
        while(!pq.empty())
        {
            int value = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
    
            ans.push_back(value);
    
            if(j+1 <  arr[i].size())  // Checking ki next Element present hai vector mein?
            {
                pq.push({arr[i][j+1], {i, j+1}});
            }
    
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends