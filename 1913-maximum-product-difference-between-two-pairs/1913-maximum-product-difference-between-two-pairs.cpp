class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int largest = INT_MIN;
        int second_largest = INT_MIN;

        int smallest = INT_MAX;
        int second_smallest = INT_MAX;

        for(int num : nums){
            if(num > largest){
                second_largest = largest;
                largest = num;
            }else{
                second_largest = max(second_largest , num);
            }
        }

        for(int num : nums){
            if(num < smallest){
                second_smallest = smallest;
                smallest = num;
            }else{
                second_smallest = min(second_smallest , num);
            }
        }

        return (largest * second_largest) - (smallest * second_smallest);
    }
};