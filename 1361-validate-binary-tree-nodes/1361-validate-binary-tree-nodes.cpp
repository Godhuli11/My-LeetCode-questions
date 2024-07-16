class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        unordered_map<int,int> child_to_parent ; //  1->1
        
        unordered_map<int , vector<int>> mpp;
        
        for(int i=0 ; i<n ; i++){
            
            int node = i;
            int leftC = leftChild[i];
            int rightC = rightChild[i];
            
            if(leftC != -1){
                 mpp[node].push_back(leftC);
                
                if(child_to_parent.find(leftC) != child_to_parent.end()){
                       return false;
                }else{
                    child_to_parent[leftC] = node;
                }
            }
             if(rightC != -1){
                 mpp[node].push_back(rightC);
                
                if(child_to_parent.find(rightC) != child_to_parent.end()){
                       return false;
                }else{
                    child_to_parent[rightC] = node;
                }
            }
        }
        
        
        int root = -1;
        
        for(int i=0 ; i<n ; i++){
            if(child_to_parent.find(i) == child_to_parent.end()){
                if(root != -1) return false;
                root = i;
            }
        }
        
        if(root == -1) return false;
        
        int cnt = 0;
        
        queue<int> q;
        
        vector<int> vis(n,0);
        
        q.push(root);
        
        while(!q.empty()){
            
            int node  = q.front();
            q.pop();
            cnt++;
            
            for(auto child : mpp[node]){
                if(vis[child] == 0){
                      q.push(child);
                       vis[child]=1;
                }
                    
            }
            
        }
        
        return cnt==n;
    }
};