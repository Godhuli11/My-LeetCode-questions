// class Solution {
// public:
//     bool areSentencesSimilar(string s1, string s2) {
//         int n = s1.size();
//         int m = s2.size();
        
//         if(n == m){
//             if(s1 == s2){
//                 return true;
//             }else{
//                 return false;
//             }
//         }
        
//         deque<string> a , b;
//         string temp = "";
//         s1.push_back(' ');
//         s2.push_back(' ');
        
//         for(int i=0 ; i<n ; i++){
//             if(s1[i]==' '){
//                 a.push_back(temp);
//                 temp = "";
//             }else{
//                 temp.push_back(s1[i]);
//             }
//         }
//         for(int i=0 ; i<m; i++){
//             if(s2[i]==' '){
//                 b.push_back(temp);
//                 temp = "";
//             }else{
//                 temp.push_back(s2[i]);
//             }
//         }
        
//         while(a.size() && b.size() && a.front() == b.front()){
//             a.pop_front();
//             b.pop_front();
//         }
//         while(a.size() && b.size() && a.back() == b.back()){
//             a.pop_back();
//             b.pop_back();
//         }
        
        
//         if (a.size()==0 || b.size()==0) return true;
//         return false;
        
//     }
// };
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        string temp = "";
        deque<string>a,b;
        for(char c:s1){
            if(c == ' ') a.push_back(temp),temp = "";
            else temp += c;
        }
        a.push_back(temp),temp = "";
        for(char c:s2){
            if(c == ' ') b.push_back(temp),temp = "";
            else temp += c;
        }
        b.push_back(temp),temp = "";
		// removing common from front
        while(a.size() != 0 && b.size() != 0 && (a.front() == b.front())) a.pop_front(),b.pop_front();
        //removing common from back
		while(a.size() != 0 && b.size() != 0 && (a.back() == b.back())) a.pop_back(),b.pop_back();
		if(a.size() == 0 || b.size() == 0) return true;
        return false;
    }
};
