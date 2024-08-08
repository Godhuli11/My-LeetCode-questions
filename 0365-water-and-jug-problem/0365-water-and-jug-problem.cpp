class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        
        if(x + y < target) return false;
        
        vector<int> operations = { x , y , -x , -y};
        
        queue<int>q;
        
        q.push(0);
        
        unordered_map<int,int> vis; //use a map instead of a vector cuz the constraints might be large and we are not required to store all the values from  0 to n , just the states which might come
        
        vis[0]=1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            if(node == target) return true;
            
            for(int i=0 ; i<4 ; i++){
                int new_node = node + operations[i];
                
                if(new_node == target) return true;
                
                if(new_node < 0 || new_node > x + y) continue;
                
                if(!vis[new_node]){
                    q.push(new_node);
                    vis[new_node]=1;
                }
                
            }
        }
        
        return false;
    }
};