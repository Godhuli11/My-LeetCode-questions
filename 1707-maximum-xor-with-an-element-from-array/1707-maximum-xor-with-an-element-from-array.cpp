class Solution {
public:
     struct trieNode {
        trieNode* left;
        trieNode* right;
    };
    void insert(trieNode* root , int& num){
        trieNode* pcrawl = root;
        for(int i = 31 ; i>=0 ; i--){
            
            int ith_bit = (num >> i) & 1;
            if(ith_bit == 0){
                if(!pcrawl->left){
                    pcrawl->left = new trieNode();
                }
                
                pcrawl = pcrawl->left;
            }else{
                 if(!pcrawl->right){
                    pcrawl->right = new trieNode();
                }
                
                pcrawl = pcrawl->right;
            }
        }
    }
    int maxXor(trieNode* root , int &num){
        int maxXor = 0;
        trieNode* pcrawl = root;
        for(int i=31; i>=0 ; i--){
            int ith_bit = (num >> i) & 1;
            if(ith_bit == 1){
                if(pcrawl->left){
                    maxXor += pow(2,i);
                    pcrawl = pcrawl->left;
                }else{
                    pcrawl = pcrawl->right;
                }
            }else{
                if(pcrawl->right){
                    maxXor += pow(2,i);
                    pcrawl = pcrawl->right;
                }else{
                    pcrawl = pcrawl->left;
                }
            }
        }
        
        return maxXor;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans(queries.size(),0);
        vector<pair<int,pair<int,int>>> offlineQueries;
        sort(nums.begin(),nums.end());
        int index = 0;
        for(auto &it : queries){
            offlineQueries.push_back({it[1],{it[0],index++}});
        }
        sort(offlineQueries.begin(),offlineQueries.end());
        int i=0;
        int n = nums.size();
        trieNode* root = new trieNode();
        
        for(auto &it : offlineQueries){
            while(i<n && nums[i] <= it.first){
                insert(root,nums[i]);
                i++;
            }
            if(i!=0) ans[it.second.second]=maxXor(root,it.second.first);
            else ans[it.second.second]=-1;
        }
        
        return ans;
    }
};