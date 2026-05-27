class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int row, int col , int expVal){
        int n = grid.size();
        if(row < 0 || col < 0 || row >= n || col >= n || grid[row][col] != expVal) return false;

        if(expVal == n*n - 1)return true;

        int ans1 =  isValid(grid, row - 2, col+1, expVal+1);
        int ans2 =  isValid(grid, row - 1, col+2, expVal+1);
        int ans3 =  isValid(grid, row + 1, col+2, expVal+1);
        int ans4 =  isValid(grid, row + 2, col+1, expVal+1);
        int ans5 =  isValid(grid, row + 2, col-1, expVal+1);
        int ans6 =  isValid(grid, row + 1, col-2, expVal+1);
        int ans7 =  isValid(grid, row - 1, col-2, expVal+1);
        int ans8 =  isValid(grid, row - 2, col-1, expVal+1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, 0 , 0 , 0);
    }
};