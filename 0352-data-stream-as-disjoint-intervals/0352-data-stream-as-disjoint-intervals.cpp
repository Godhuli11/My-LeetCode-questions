
  class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<int> nums(begin(st), end(st));
        
        vector<vector<int>> result;
        
        int n = nums.size();
        
        for(int i = 0; i<n; i++) {
            int start = nums[i];
            
            while(i < n-1 && nums[i]+1 == nums[i+1]) {
                i++;
            }
            result.push_back({start, nums[i]});
        }
        
        return result;
    }

};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */