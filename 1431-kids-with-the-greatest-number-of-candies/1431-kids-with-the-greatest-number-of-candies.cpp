class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(begin(candies) , end(candies));
        vector<bool> res;
        for(int candy : candies){
            res.push_back(candy + extraCandies >= maxCandies);
        }
        return res;
    }
};