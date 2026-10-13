class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int>pq;
        long long ans = 0;
       for(int i = 0; i < n; i++)pq.push(nums[i]*nums[i]);
        int mid = 0;
        if(n % 2 == 0)mid = (n+1)/2;
        else mid = (n-1)/2;
        int count = n-1;
        while(!pq.empty()){
            if(count < mid){
                long long x = pq.top();
                ans -= x;
                pq.pop();
                count--;
            }
            else{
                 long long z = pq.top();
                ans += z;
                pq.pop();
                count--;
            }
        }
      
        return ans;
    }
};