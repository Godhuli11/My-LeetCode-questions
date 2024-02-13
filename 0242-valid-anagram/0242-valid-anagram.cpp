class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        map<char,int>mpp;
        
        for(int i=0 ; i<s.size();i++){
           mpp[s[i]]++;
        }
        for(int i=0 ; i<t.size();i++){
           mpp[t[i]]--;
        }
        for(int i=0 ; i<t.size();i++){
            if(mpp[t[i]]) return false;
        }
        return true;
    }
};