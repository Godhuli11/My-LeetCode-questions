class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int n = customers.size();
        
        int currTime = customers[0][0];
        
        double totalTime = 0;
        
        for(int i=0 ; i<n ; i++){
            
            if(currTime <= customers[i][0]){
                totalTime += customers[i][1];
                currTime = customers[i][1] + customers[i][0];
                continue;
            }
            int timeTaken = customers[i][1] + currTime;
            int waitingTime = timeTaken - customers[i][0];
            totalTime += waitingTime;
            currTime = timeTaken;
            
        }
        
        return (totalTime/n) ;
    }
};