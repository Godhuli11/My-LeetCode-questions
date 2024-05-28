class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
            
        vector<int> res;
        
        queue<pair<int,int>> que;
        
        que.push({0,0});
        
        while(!que.empty()){
            
            
            auto [row , col] = que.front();
            
            que.pop();
            
            res.push_back(nums[row][col]);
            
            if(col == 0 && row + 1 < nums.size()){
                que.push({row + 1 , col});
            }
            
            if(col + 1 < nums[row].size()){
                que.push({row , col + 1});
            }
        }
        
        return res;
    }
};  