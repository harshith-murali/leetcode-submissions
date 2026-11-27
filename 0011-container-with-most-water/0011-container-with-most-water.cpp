class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = INT_MIN;
        int n = height.size();

        int l = 0 , r = n - 1;
        while(l < r){
            int w = r - l;
            int h = min(height[l] , height[r]);
            int area = w * h;
            maxWater = max(maxWater, area);

            height[l] < height[r] ? l++ : r--;
        }
        return maxWater;
    }
};