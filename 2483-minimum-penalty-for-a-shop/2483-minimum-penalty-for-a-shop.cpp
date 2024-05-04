class Solution {
public:
    int bestClosingTime(string c) {
        
        int n = c.size();
        
        int penalty = 0;
        
        for(int i=0 ; i<n ; i++){
            if(c[i] == 'Y'){
                penalty++;
            }
        }
        
        int minP = penalty;
        int minH = 0;
        
        for(int i=0 ; i<n ; i++){
            
            if(c[i]=='Y'){
                penalty--;
            }else{
                 penalty++;
            }
             if(penalty < minP){
                    minP = penalty;
                    minH = i+1;
                }
        }
        
        return minH;
    }
};