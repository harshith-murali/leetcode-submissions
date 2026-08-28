class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> rightMax(n,0) , leftMax(n,0);
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        int res = 0;
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        for(int j=n-2; j>=0; j--){
            rightMax[j] = max(rightMax[j+1], height[j]);
        }

        for(int i=0; i<n; i++){
            int h = min(leftMax[i], rightMax[i]) - height[i];

            res += h;
        }

        return res;
    }
};