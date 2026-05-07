class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> prev(n);

        for(int j=0; j<n; j++) prev[j] = triangle[n-1][j];

        for(int i=n-2; i>=0; i--){
                vector<int> curr(n);
            for(int j=i; j>=0; j--){
                    curr[j] = min (
                    triangle[i][j] + prev[j],
                    triangle[i][j] + prev[j+1]
                );
            }
            prev = curr;
        }
       return prev[0];
    }
};