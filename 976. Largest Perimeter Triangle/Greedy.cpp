class Solution {
public:


    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end()); // nlogn
        
        for(int cidx = n-1 ; cidx >= 2; cidx--){
            int c = nums[cidx];
            int a = nums[cidx-2];
            int b = nums[cidx - 1];
            if(a + b > c){
                return a + b + c;
            }
        }

        return 0;
    }
};
