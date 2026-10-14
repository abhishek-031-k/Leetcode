class Solution {
public:

    long long make_pal(int n, bool flag){
        string ans = to_string(n);
        int len = ans.length();
        for(int i = len - 1 - flag; i>=0; i--){
            ans += ans[i];
        }

        return stoll(ans);
    }

    bool is_pow10(long long n){
        
        while(n%10 == 0){
            n/=10;
        }
        return n == 1;
    }

    string nearestPalindromic(string str){
        long long num = stoll(str);
        int len = (str.length()+1)>>1;
        long long low = pow(10, len-1);
        long long high = pow(10, len);
        high--;
        bool flag = (str.length()&1);
        int l = low, r = high;


        while(l <= r){
            int mid = (l+r)>>1;

            long long req_pal = make_pal(mid, flag);

            if(req_pal>=num) r = mid-1;
            else l = mid+1;

        }

        if(num/10 == 0) return to_string(num-1);

        if(is_pow10(num)){
            return to_string(num-1);
        }

        if(is_pow10(num-1)){
            return to_string(num-2);
        }

        if(is_pow10(num+1)) return to_string(num+2);

        long long res1 = make_pal(l, flag);
        if(res1 == num) res1 = make_pal(l+1, flag);
        long long res2 = make_pal(r, flag);
        if(res2 == num) res2 = make_pal(r-1, flag);
        return (res1 - num)<(num - res2)?to_string(res1):to_string(res2);


         
    }
};