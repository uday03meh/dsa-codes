class Solution {
public:
    int bs(vector<int>& nums, int ss, int target) {
        int n = nums.size();
        int start = ss;
        int end = n - 1;
        int idx = 0;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] < target) {
                // this is what i want
                // but i will explore for a bigger of idx
                idx = max(idx, mid);
                start = mid + 1;
            } else if (nums[mid] >= target) {
                end = mid - 1;
            }
        }

        return max(idx - ss+1, 0);
    }
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int target = nums[i] + nums[j];
                // i need the third side to be a number that is less than
                // target sum
                ans += bs(nums, j + 1, target);
            }
        }
        return ans;
    }
};
