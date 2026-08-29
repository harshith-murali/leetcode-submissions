class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;

        for(int x : left){
            result = max(x, result);
        }
        for(int x : right){
            result = max(n-x,result);
        }
        return result;
    }
};