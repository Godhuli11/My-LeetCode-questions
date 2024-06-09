class Solution {
public:
    int mod = 1e9 + 7;
    long long power(long long x , long long n){
        
        if(n==0) return 1;
        if(n==1) return x;
        
        if(n%2 == 0){
            long long res = (x*x)%mod;
            return power(res,n/2);
        }else{
            long long res = (x*x)%mod;
            return (x*power(res,n/2))%mod;
        }
    } 
    int countGoodNumbers(long long n) {
        long long oddPlaces = n/2;
        long long evenPlaces = n/2 + n%2;
        
        int res = power(5,evenPlaces)*power(4,oddPlaces)%mod;
        
        return res;
    }
};