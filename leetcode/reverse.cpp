class Solution {
public:
    int reverse(int x) {
        long long tx = x;
        long long maxv = (1LL << 31) -1;
        long long ans = 0;
        while(tx){
            ans = ans*10 + tx%10;
            if(abs(ans) > maxv )return 0;
            tx/=10;
        }

        return int(ans);
    }
};
