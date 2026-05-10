class Solution {
public:
    bool canWePlace(vector<int>& position, int m, int dist){
        int n = position.size();
        int balls = 1, last = position[0];
        for(int i=0; i<n; i++){
            if(position[i] - last >= dist){
                balls++;
                last = position[i];
            }
        }
        return balls >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin() , position.end());
        int s = 0;
        int e = position[n-1] - position[0];

        while(s <= e){
            int mid = s + (e-s)/2;
            if(canWePlace(position , m , mid)){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return e;
    }
};