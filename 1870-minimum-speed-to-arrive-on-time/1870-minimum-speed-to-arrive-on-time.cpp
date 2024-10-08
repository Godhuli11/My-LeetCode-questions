class Solution {
public:
//     bool isPossible(int speed , vector<int>& dist , int hour ){
        
//         double actualTime = 0.0;
        
//         int n = dist.size();
        
//         for(int i=0 ; i<dist.size()-1 ; i++){
            
//             double val = (double)dist[i]/(double)speed;
            
//             actualTime += ceil(val);
//         }
        
//         actualTime += (double)dist[n-1]/(double)speed;
        
//         if(actualTime <= hour) return true;
        
//         return false;
        
//     }
//     int minSpeedOnTime(vector<int>& dist, double hour) {
        
//         int l = 1;
        
//         int r = 1e7;
        
//         int res = -1;
        
//         while(l <= r){
//             int mid = l + (r-l)/2;
            
//             if(isPossible(mid , dist , hour)){
//                 res = mid;
//                 r = mid - 1;
//             }else{
//                 l = mid + 1;
//             }
//         }
        
        
//         return res;
//     }
// };
 double possible(vector<int>& dist, int speed) {
        
        double time = 0.0;
        int n = dist.size();
        
        for(int i = 0; i < n - 1; i++) {
            
            double t = (double)dist[i]/(double)speed;
            
            time += ceil(t);
            
        }
        
        time += (double)dist[n-1]/(double)speed;
        
        return time;
        
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1;
        int r = 1e7;
        
        int minSpeed = -1;
        
        while(l <= r) {
            
            int mid = l + (r-l)/2;
            
            if(possible(dist, mid) <= hour) {
                minSpeed = mid;
                r = mid-1;
            } else {
                l = mid+1; //need to speed up
            }
            
        }
        
        return minSpeed;
    }
};