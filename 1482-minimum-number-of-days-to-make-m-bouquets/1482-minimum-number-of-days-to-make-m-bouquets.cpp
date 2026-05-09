class Solution {
public:
    bool possible(vector<int>& arr, int k, int m, int day){
        int cnt = 0 , noOfBouquets = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(arr[i] <= day){
                cnt++;
            }else{
                noOfBouquets += cnt / k;
                cnt = 0;
            }
        }
        noOfBouquets += cnt / k;
        return (noOfBouquets >= m);
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if(1LL * m*k > n) return -1;
        int s = *min_element(arr.begin() , arr.end());
        int e = *max_element(arr.begin() , arr.end());
        while(s <= e){
            int mid = s + (e-s)/2;
            if(possible(arr , k , m, mid)){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return s;
    }
};