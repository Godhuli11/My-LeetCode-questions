class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> maxHeap;
        map<int,int> mpp;
        for(int i=0 ; i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto ele : mpp){
            maxHeap.push({ele.second,ele.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return ans;
    }
};