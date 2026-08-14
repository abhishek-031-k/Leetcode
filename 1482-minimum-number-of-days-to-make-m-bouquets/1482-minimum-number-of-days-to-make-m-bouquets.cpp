class Solution {
public:
    bool solve(int mid, vector<int>&bloomDay, int m, int k){
       int count = 0, no_of_bouquet = 0;
       for(int i = 0; i < bloomDay.size(); i++){
           if(bloomDay[i] <= mid){
            count++;
           if(count == k){
            no_of_bouquet++;
           count = 0;
           }
           }
           else count = 0;
       }
       return (no_of_bouquet >= m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL*m*1LL*k > n)return -1;
        int low = INT_MAX, high = 0;
        for(auto &it: bloomDay){
            low = min(low, it);
            high = max(high, it);
        }
        while(low <= high){
            int mid = low + (high - low)/2;
            if(solve(mid, bloomDay, m, k)) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};