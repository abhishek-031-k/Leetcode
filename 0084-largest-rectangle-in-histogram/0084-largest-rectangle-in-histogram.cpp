class Solution {
public:
    
    void FindNSE(int n, vector<int>&nse, vector<int>&nums){
         stack<int>st;
         for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i])st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
         }
    }

    void FindPSE(int n, vector<int>&pse, vector<int>&nums){
         stack<int>st;
         for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i])st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
         }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nse(n, n), pse(n, -1);
        FindNSE(n, nse, heights);
        FindPSE(n, pse, heights);
        int largest = 0;
        for(int i = 0; i < n; i++){
         largest = max(largest, (heights[i] * (nse[i] - pse[i] - 1)));
        }
        return largest;
    }
};