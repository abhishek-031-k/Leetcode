class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans = 0, last = 0;
        for(auto &it: requests){
            ans += abs(last - it);
            last = it;
        }
        return ans;
    }
};