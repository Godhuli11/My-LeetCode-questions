// class Solution {
// public:
//     void solve(int ind , string num , int target ,vector<string>&ans , string curr ,int prev , int res){
//         if(ind==num.size()){
//             if(res == target){
//                 ans.push_back(curr);
//             }
            
//             return;
//         }
        
//         string st = "";
//         int currRes = 0;
//         for(int i=ind ; i<num.size() ; i++){
//             if(i>ind && num[i]=='0') break;
//             st+=num[i];
//             currRes = currRes * 10 + (num[i]-'0');
//             if(ind == 0){
//                 solve(i+1,num,target,ans,curr,prev,res);
//             }else{
//                 solve(i+1,num,target,ans,curr+"+"+st,currRes,res+currRes);
//                 solve(i+1,num,target,ans,curr+"-"+st,-currRes,res-currRes);
//                 solve(i+1,num,target,ans,curr+"*"+st,prev*currRes,res-prev+(prev*currRes));
//             }
//         }
//     }
//     vector<string> addOperators(string num, int target) {
//         vector<string> ans;
//         solve(0,num,target,ans,"",0,0);
//         return ans;
        
//     }
// };
class Solution {
public:
    void solve(int ind, string num, int target, vector<string>& ans, string curr, long prev, long res) {
        if (ind == num.size()) {
            if (res == target) {
                ans.push_back(curr);
            }
            return;
        }
        
        string st = "";
        long currRes = 0;
        for (int i = ind; i < num.size(); ++i) {
            if (i > ind && num[ind] == '0') break; // To avoid numbers with leading zeros
            
            st += num[i];
            currRes = currRes * 10 + (num[i] - '0');
            
            if (ind == 0) {
                // If it's the first number, we don't add any operator
                solve(i + 1, num, target, ans, st, currRes, currRes);
            } else {
                solve(i + 1, num, target, ans, curr + "+" + st, currRes, res + currRes);
                solve(i + 1, num, target, ans, curr + "-" + st, -currRes, res - currRes);
                solve(i + 1, num, target, ans, curr + "*" + st, prev * currRes, res - prev + (prev * currRes));
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(0, num, target, ans, "", 0, 0);
        return ans;
    }
};
