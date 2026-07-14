class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)return 0;
        if(n == 1)return 1;
        if(n == 2)return 1;
    
        int prev2 = 0, prev = 1, curr = 1;
        for(int i = 3; i <= n; i++){
         int x = curr + prev + prev2;
         prev2 = prev;
         prev = curr;
         curr = x;
        }
      return curr;
    }
};