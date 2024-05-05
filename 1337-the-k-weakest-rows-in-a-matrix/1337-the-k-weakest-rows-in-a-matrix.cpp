class Solution {
public:
    typedef pair<int,int> P;
    
    int binarySearch(vector<int> row , int l , int h){
        
        int ans = -1;
        
        while(l <= h){
            int mid = l + (h-l)/2;
            
            if(row[mid]==1){
                ans = mid;
                l =  mid + 1;
            }else{
                h = mid - 1;
            }
        }
        
        return ans + 1;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        priority_queue<P> pq;
        
        for(int row = 0; row < m ; row++){
            
            int count_ones = binarySearch(mat[row],0,n-1);
            
            pq.push({count_ones , row});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> res(k);
        
        int j = k-1;
        
        while(!pq.empty()){
            int ind = pq.top().second;
            pq.pop();
            
            
            res[j--] = ind;
        }
        
        return res;
        
    }
};