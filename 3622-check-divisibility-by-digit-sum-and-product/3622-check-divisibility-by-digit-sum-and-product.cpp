class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n, sum = 0, product = 1;
        while(temp > 0){
           sum += temp % 10;
           product *= temp % 10;
           temp /= 10;
        }
        return n % (sum + product) == 0;
    }
};