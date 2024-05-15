class Solution {
public:
     int beauty(vector<int>& alpha){
         int maf = -1;
         int minf = 1e9;
         
         for(int i=0 ; i<alpha.size() ; i++){
             
             maf = max(maf,alpha[i]);
             
             if(alpha[i]>0){
                 minf = min(minf , alpha[i]);
             }
         }
         
         return maf - minf;
         
     }
    int beautySum(string s) {
        
        
        int res = 0;
        
        for(int i=0 ; i<s.size()  ; i++){
            vector<int> alpha(26,0);
            for(int j=i ; j<s.size() ; j++){
                alpha[s[j]-'a']++;
                res += beauty(alpha);
            }
        }
        
        return res;
    }
};