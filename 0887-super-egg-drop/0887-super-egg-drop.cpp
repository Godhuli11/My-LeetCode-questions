class Solution {
public:
    int solve(int e , int f , vector<vector<int>> &dp){
        
        if(e == 1){
            return f;
        }
        
        if(f==1){
            return 1;
        }
        
        if(dp[e][f]!=-1) return dp[e][f];
        
        int minMoves = f;
        
//         for(int k=1 ; k<=f ; k++){
//             long long  temp = 1LL + max(solve(e-1,k-1,dp),solve(e,f-k,dp));
            
//             minMoves = min(minMoves , (int)temp);
//         }
        int l = 1;
        int h = f;
        //int temp = 0;
        
        
        
        while(l<h)
        {
            int mid=(l+h)/2;
            int left=solve(e-1,mid-1,dp);   //egg broken check for down floors of mid
            int right=solve(e,f-mid,dp) ;   // not broken check for up floors of mid
            int temp=1+max(left,right);          //store max of both 
            if(left<right){                  //since right is more than left and we need more in worst case 
              l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
            }
            else                             //left > right so we will go downward 
            {    
                h=mid;
            }
            minMoves=min(minMoves,temp);               //store minimum attempts
        }
        
        return dp[e][f] = minMoves;
    }
    int superEggDrop(int k, int n) {
        
        vector<vector<int>> dp(k+1 , vector<int>(n+1,-1));
        return solve(k,n,dp);
        
        
    }
};