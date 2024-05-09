class Solution {
public:
    bool rotateString(string s, string goal) {
        
        string newStr = s;
        int i=0;
        
        while(newStr != s || i==0){
            char a = newStr[0];
            i++;
             newStr = newStr.substr(1);
            newStr += a;
            
            if(newStr == goal){
                return true;
            }
        }
        
        return false;
    }
};