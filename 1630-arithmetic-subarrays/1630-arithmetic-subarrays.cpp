class Solution {
public:
    bool check(vector<int> arr){
        
        int n = arr.size();
        
        int minE = INT_MAX;
        int maxE = INT_MIN;
        
        unordered_set<int> st;
        
        for(auto &c : arr){
            
            minE = min(minE,c);
            maxE = max(maxE,c);
            
            st.insert(c);
        }
        
        if((maxE-minE) % (n-1) != 0){
            return false;
        }
        
        int diff = (maxE - minE) / (n-1);
        
        int curr = minE;
        
        while(curr < maxE){
            
            if(st.find(curr) == st.end()){
                return false;
            }
            
            curr += diff;
        }
        
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int n = l.size();
        
        vector<bool> res;
        
        for(int i=0 ; i<n ; i++){
            
            vector<int> arr(nums.begin() + l[i] , nums.begin() + r[i] + 1); 
            
            res.push_back(check(arr));
            
        }
        
        return res;
    }
};