class Solution {
public:
    bool sumGame(string num){
        int n = num.size();
        int left_sum = 0, right_sum = 0, left_symbol = 0, right_symbol = 0;
        for(int i = 0; i < n/2; i++){
            if(num[i] == '?')left_symbol++;
            else left_sum += (num[i] - '0');
        }
        for(int i = n/2; i < n; i++){
            if(num[i] == '?')right_symbol++;
            else right_sum += (num[i] - '0');
        }
        if((left_symbol + right_symbol) % 2 == 1)return true;
        return 2 * (left_sum - right_sum) != 9 * (right_symbol - left_symbol);
    }
};