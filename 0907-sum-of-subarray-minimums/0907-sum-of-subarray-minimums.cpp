class Solution {
public:

    void PSE(int n, vector<int>&pse, vector<int>&arr){
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i])st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void NSE(int n, vector<int>&nse, vector<int>&arr){
         stack<int>st;
         for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
         }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7, ans = 0;
        vector<int>pse(n, -1), nse(n, n);
        NSE(n, nse, arr);
        PSE(n, pse, arr);
        for(int i = 0; i < n; i++){
            int left = i - pse[i], right = nse[i] - i;
          ans = (ans + (left * right *1LL* arr[i])% mod)%mod;
        }
        return ans;
    }
};