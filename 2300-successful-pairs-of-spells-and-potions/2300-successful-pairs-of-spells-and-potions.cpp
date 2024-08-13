class Solution {
public:
    int findLowerBound(long long minPotion , vector<int>& potions , int m){
        int l = 0;
        int r = m-1;
        
        int possibleVal = -1;
        
        while(l <= r){
            
            int mid = l + (r-l)/2;
            
            if(potions[mid] >= minPotion){
                possibleVal = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        
        return possibleVal;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int n = spells.size();
        int m = potions.size();
        
        sort(potions.begin(),potions.end());
        
        vector<int> ans;
        
        int maxPotion = potions[m-1];
        
        for(int i=0 ; i<n ; i++){
            
            long long minPotion = ceil((1.0 * success)/spells[i]);
            
            if(minPotion > maxPotion){
                ans.push_back(0);
                continue;
            }
            
            int index = findLowerBound(minPotion , potions,m );
            
            ans.push_back(m-index);
            
        }
        
        return ans;
    }
};