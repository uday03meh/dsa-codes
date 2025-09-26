class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int target = nums[i] + nums[j];
                for(int k = j + 1; k < n; k++){
                    // i need the third side to be a number that is less than
                    // target sum
                    // assume nums[k] is the largest side
                    if((nums[k] < nums[i] + nums[j]) && 
                    (nums[i] < nums[k] + nums[j]) &&
                    (nums[j] < nums[i] + nums[k]) ){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
