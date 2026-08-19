class Solution {
public:
    int UpperBound(vector<pair<int, int>>&v, int t) {
        int low = 0, high = v.size() - 1;
        int ans = v.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid].first > t) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker){
        int ans = 0;
        vector<pair<int, int>>v;
        for(int i = 0; i < profit.size(); i++)v.push_back({difficulty[i], profit[i]});
        sort(v.begin(), v.end());
        for(int i = 1; i < v.size(); i++)v[i].second = max(v[i].second, v[i - 1].second);
        for(int i = 0; i < worker.size(); i++) {
            int idx = UpperBound(v, worker[i]);
            if(idx == 0)continue;
            ans += v[idx - 1].second;
        }
        return ans;
    }
};