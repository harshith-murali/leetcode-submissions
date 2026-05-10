class Solution {
public:
    int place(vector<int> &arr, int students , int pages){
        int n = arr.size();
        int cntStudents = 1;
        long long studPages = 0;
        for(int i=0; i<n; i++){
            if(studPages + arr[i] <= pages){
                studPages += arr[i];
            }else{
                cntStudents++;
                studPages = arr[i];
            }
        }
        return cntStudents;
    }
    int findPages(vector<int> &arr, int students) {
        // code here
        int n = arr.size();
        if(students > n) return -1;
        int s = *max_element(arr.begin() , arr.end());
        int e = accumulate(arr.begin() , arr.end() , 0);
        
        while(s <= e){
            int mid = s + (e-s)/2;
            int noOfStudents = place(arr , students, mid);
            if(noOfStudents > students){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return s;
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums , k);
    }
};