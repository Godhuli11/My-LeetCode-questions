class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        
        if(n<=1) return 0;
        
        sort(intervals.begin(),intervals.end());
        
        int i=0;
        int j=1;
        
        int ans=0;
        
        while(i<n && j<n){
            if(intervals[i][1] <= intervals[j][0]){
                i=j;
                j++;
            }
            else if(intervals[i][1] <= intervals[j][1]){
                ans++;
                j++;
            }
            else{
                ans++;
                i=j;
                j++;
            }
        }
        
        return ans;
}
    
};
// class Solution {
// public:
//     int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
//         int n = intervals.size();

//         if (n <= 1) {
//             return 0;  // No overlaps if there are 0 or 1 intervals
//         }

//         std::sort(intervals.begin(), intervals.end());

//         int i = 0;
//         int j = 1;
//         int ans = 0;

//         while (j < n) {
//             if (intervals[i][1] <= intervals[j][0]) {
//                 i = j;
//                 j++;
//             } else {
//                 ans++;
//                 // Erase the interval with the later end time
//                 if (intervals[i][1] > intervals[j][1]) {
//                     i = j;
//                 }
//                 j++;
//             }
//         }

//         return ans;
//     }
// };