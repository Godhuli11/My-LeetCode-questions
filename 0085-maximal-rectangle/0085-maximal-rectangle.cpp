class Solution {
public:
    vector<int> getNSL(vector<int> height){
        
        vector<int> NSL(height.size());
        
        stack<int> st;
        
        for(int i=0 ; i<height.size() ; i++){
            if(st.empty()){
                NSL[i] = -1;
            }else{
                while(!st.empty() && height[st.top()] >= height[i]){
                    st.pop();
                }
                if(st.empty()){
                    NSL[i] = -1;
                }else{
                    NSL[i] = st.top();
                }
            }
            
            st.push(i);
        }
        
        return NSL;
    }
      vector<int> getNSR(vector<int> height){
        
        vector<int> NSR(height.size());
        
        stack<int> st;
          
          int n = height.size();
        
        for(int i=n-1 ; i>=0 ; i--){
            if(st.empty()){
                NSR[i] = n;
            }else{
                while(!st.empty() && height[st.top()] >= height[i]){
                    st.pop();
                }
                if(st.empty()){
                    NSR[i] = n;
                }else{
                    NSR[i] = st.top();
                }
            }
            
            st.push(i);
        }
        
        return NSR;
    }
    int getMaxArea(vector<int> height){
        
        vector<int> NSL = getNSL(height);
        vector<int> NSR = getNSR(height);
        
        int maxArea = INT_MIN;
        
        for(int i=0 ; i<height.size() ; i++){
            maxArea = max(maxArea , height[i]*(NSR[i]-NSL[i]-1));
        }
        
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();  
        
        vector<int> height(m,0);
        
        for(int j=0 ; j<m ; j++){
            height[j] = (mat[0][j] == '1') ? 1 : 0 ;
        }
        
        int maxArea = getMaxArea(height) ;
        
        for(int r=1 ; r<n ; r++){
            for(int c=0 ; c<m ; c++){
                if(mat[r][c] == '1'){
                    height[c] += 1;
                }else{
                    height[c] = 0;
                }
            }
            maxArea = max(maxArea , getMaxArea(height));
         }
        
        return maxArea;
    }
};
// vector<int> getNSL(vector<int>& height) {
//         int n = height.size();
//         vector<int> NSL(n);
//         stack<int> st;
        
//         for (int i = 0; i < n; i++) {
//             // If stack is empty, there is no smaller element on the left
//             if (st.empty()) {
//                 NSL[i] = -1;
//             } else {
//                 // Pop elements from stack until we find an element smaller than 'height[i]'
//                 while (!st.empty() && height[st.top()] >= height[i]) {
//                     st.pop();
//                 }
//                 // If stack is empty now, there's no smaller element on the left
//                 if (st.empty()) {
//                     NSL[i] = -1;
//                 } else {
//                     NSL[i] = st.top();
//                 }
//             }
//             // Push current index 'i' onto the stack
//             st.push(i);
//         }
        
//         return NSL;
//     }
    
//     // Function to find the nearest smaller element on the right for each element in 'height'
//     vector<int> getNSR(vector<int>& height) {
//         int n = height.size();
//         vector<int> NSR(n);
//         stack<int> st;
        
//         for (int i = n - 1; i >= 0; i--) {
//             // If stack is empty, there is no smaller element on the right
//             if (st.empty()) {
//                 NSR[i] = n;
//             } else {
//                 // Pop elements from stack until we find an element smaller than 'height[i]'
//                 while (!st.empty() && height[st.top()] >= height[i]) {
//                     st.pop();
//                 }
//                 // If stack is empty now, there's no smaller element on the right
//                 if (st.empty()) {
//                     NSR[i] = n;
//                 } else {
//                     NSR[i] = st.top();
//                 }
//             }
//             // Push current index 'i' onto the stack
//             st.push(i);
//         }
        
//         return NSR;
//     }
    
//     // Function to calculate the maximum rectangle area based on histogram heights
//     int getMaxArea(vector<int>& height) {
//         vector<int> NSL = getNSL(height);
//         vector<int> NSR = getNSR(height);
        
//         int maxArea = INT_MIN;
        
//         // Calculate the area for each histogram bar
//         for (int i = 0; i < height.size(); i++) {
//             int width = NSR[i] - NSL[i] - 1;
//             int area = height[i] * width;
//             maxArea = max(maxArea, area);
//         }
        
//         return maxArea;
//     }
    
//     // Main function to find the maximal rectangle area in the binary matrix
//     int maximalRectangle(vector<vector<char>>& mat) {
//         if (mat.empty() || mat[0].empty()) return 0;
        
//         int n = mat.size();    // Number of rows
//         int m = mat[0].size(); // Number of columns
        
//         // Initialize the histogram height vector for the first row
//         vector<int> height(m, 0);
//         for (int j = 0; j < m; j++) {
//             height[j] = (mat[0][j] == '1') ? 1 : 0;
//         }
        
//         // Get the maximum area from the first row
//         int maxArea = getMaxArea(height);
        
//         // Process each subsequent row to update the histogram heights and calculate the max area
//         for (int r = 1; r < n; r++) {
//             for (int c = 0; c < m; c++) {
//                 if (mat[r][c] == '1') {
//                     height[c] += 1;
//                 } else {
//                     height[c] = 0;
//                 }
//             }
//             // Update maxArea with the maximum area found in the current histogram heights
//             maxArea = max(maxArea, getMaxArea(height));
//         }
        
//         return maxArea;
//     }
// };