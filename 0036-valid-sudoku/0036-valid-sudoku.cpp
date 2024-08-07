class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
        
        set<string> st;
        
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j < 9 ; j++){
                if(mat[i][j]=='.'){
                    continue;
                }
                
                string row = to_string(mat[i][j]) +"_ROW_"+ to_string(i);
                string col =to_string(mat[i][j]) +"_COL_"+ to_string(j);
                string box = to_string(mat[i][j])+"_BOX_"+ to_string(i/3) + "__" + to_string(j/3);
                if(st.find(row)!=st.end()||st.find(col)!=st.end()||st.find(box)!=st.end()){
                    return false;
                }
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        
        return true;
    }
};