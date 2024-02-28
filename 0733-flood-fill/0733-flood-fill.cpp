class Solution {
public:
    bool isValid(vector<vector<int>>& image, int i, int j, int prev_color,int n , int m){
        if(i>=0 && i<n && j>=0 && j<m && image[i][j]==prev_color){
            return true;
        }
        
        return false;
    }
    void solve(vector<vector<int>>& image, int i, int j, int color , int prev_color,int n , int m){
        image[i][j]=color;
        
        int dx [] = {-1,1,0,0};
        int dy []= {0,0,-1,1};
        
        for(int z=0 ; z<4 ; z++){
            int new_i = i+dx[z];
            int new_j = j+dy[z];
            if(isValid(image,new_i,new_j,prev_color,n,m)){
                solve(image,new_i,new_j,color,prev_color,n,m);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        int prev_color = image[sr][sc];
        if(prev_color == color){
            return image;
        }
        solve(image,sr,sc,color,prev_color,n,m);
        return image;
    }
};