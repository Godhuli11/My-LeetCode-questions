class Solution {
public:
    typedef pair<char,int> p;
    string frequencySort(string s) {
        
        vector<p> vec(123);
        
        for(char &c : s){
            int freq = vec[c].second;
            vec[c] = {c , freq+1};
        }
        
        auto lambda = [&](p &p1 , p &p2){
            return p1.second > p2.second;
        };
        
        sort(vec.begin() , vec.end() , lambda);
        
        string res = "";
        
        for(int i=0 ; i<=122 ; i++){
            
            res += string(vec[i].second,vec[i].first);
        }
        
        return res;
    }
};