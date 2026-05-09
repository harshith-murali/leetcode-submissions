class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        if(x==0) return 0;
        int s = 1 , e = x/2;
        while(s <= e){
            long long mid = s + (e-s)/2;
            if(mid * mid <= x){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return e;
    }
};