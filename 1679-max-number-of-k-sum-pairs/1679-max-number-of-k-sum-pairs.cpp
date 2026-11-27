class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int ops = 0;

        for(int num : nums){
            int tar = k - num;
            if(freq[tar] > 0){
                ops++;
                freq[tar]--;
            }else{
                freq[num]++;
            }
        }

        return ops;
    }
};