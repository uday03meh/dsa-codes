class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // nlogn , O(1) space
        // rock bottom
        nums[0] -= k;
        int prev = nums[0];
        // nums[i-1] -> prev -> last updated value
        for (int i = 1; i < n; i++) {
            int low = nums[i] - k;
            int high = nums[i] + k;

            if (low <= prev) {
                if (prev + 1 <= high) {
                    nums[i] = prev + 1;
                    prev = nums[i];
                }
            }
            else {
                nums[i] = low;
                prev = nums[i];
            } 
        }

        sort(nums.begin(), nums.end());

        // unique erase
        for (auto i : nums) {
            cout << i << ", ";
        }
        cout << endl;
        auto it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        return nums.size();
    }
};
