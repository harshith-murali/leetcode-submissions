class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int minPrice = INT_MAX;
        int secMinPrice = INT_MAX;

        for(int price : prices){
            if(price < minPrice){
                secMinPrice = minPrice;
                minPrice = price;
            }else{
                secMinPrice = min(secMinPrice, price);
            }
        }

        int sum = minPrice + secMinPrice;
        return sum <= money ? money - sum : money;
    }
};