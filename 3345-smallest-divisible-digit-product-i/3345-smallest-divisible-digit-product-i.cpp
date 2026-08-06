class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = 0; i < 10; i++){
             int x =  n + i;
            int temp = 1;
            while(x > 0){
                temp = x%10 * temp;
                x /= 10;
            } 
            if(temp % t == 0)return n + i;
        }
        return 0;
    }
};