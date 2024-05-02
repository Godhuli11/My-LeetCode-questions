class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        // if(( event2[0] <= event1[0] && event2[0] <= event1[1] ) || event1[1] >= event2[0] ){
        //     return true;
        // }
        // return false;
         string startTime1 = event1[0];
        string endTime1 = event1[1];
        string startTime2 = event2[0];
        string endTime2 = event2[1];
        
        // Check for conflict
        if (startTime1 <= endTime2 && startTime2 <= endTime1) {
            return true; // Conflict exists
        }
        return false; // No conflict
    }
};