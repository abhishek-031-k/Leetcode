class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int ans = 0;
        for(int i = 0; i < n; i++){
        while(!st.empty() && heights[st.top()] > heights[i]){
            int element = st.top();
            st.pop();
           int nse = i;
         int  pse = st.empty() ? -1 : st.top();
           ans = max(ans, heights[element]*(nse-pse-1));
        }
        st.push(i);
        }
        while(!st.empty()){
         int nse = n;
         int element = st.top();
         st.pop();
        int pse = st.empty() ? -1 : st.top();
         ans = max(ans, heights[element]*(nse-pse-1));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>dp(m, 0);
        int maxarea = 0;
        for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
          if(matrix[i][j] == '0')dp[j] = 0;
          else dp[j]++;
        }
        maxarea = max(maxarea, largestRectangleArea(dp));
        }
        return maxarea;
    }
};