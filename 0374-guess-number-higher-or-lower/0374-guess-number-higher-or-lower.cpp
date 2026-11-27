class Solution {
public:
    int guessNumber(int n) {
        int s = 1, e = n;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int res = guess(mid); // Query the API with your guess
            
            if (res == 0) {
                return mid;       // Found the picked number
            } else if (res == 1) {
                s = mid + 1;      // Guess was too low; search the right half
            } else {
                e = mid - 1;      // Guess was too high; search the left half
            }
        }
        
        return -1; // Fallback if not found
    }
};