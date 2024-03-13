class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == INT_MIN && divisor==-1){
            return INT_MAX;
        }
        
        if(dividend == divisor){
            return 1;
        }
        
        bool flag = ((dividend >= 0) == (divisor >=0)) ? true : false ;
        
        
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        
        unsigned int res = 0;
        
        while( a >= b){
            int count = 0;
            
            while( a > (b << count + 1)){
                count++;
            }
            
            res += 1 << count;
            a -= b << count;
        }
        
        return flag ? res : -res;
    }
};