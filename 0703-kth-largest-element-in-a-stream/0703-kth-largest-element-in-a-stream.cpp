class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minH;
    
    int K = 0;
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        K = k;
        for(int i=0 ; i<n ; i++){
            minH.push(nums[i]);
            if(minH.size() > k){
                minH.pop();
            }
        }
        
    }
    
    int add(int val) {
        minH.push(val);
        
        while(minH.size() > K){
            minH.pop();
        }
        
        return minH.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */