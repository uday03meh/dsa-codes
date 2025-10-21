class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numops) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1;
        int l = 0, r = 0;
        int freq = 0;
        while (l < n && r < n) {
            int ops = numops;
            while (ops >= 0 && r < n && nums[l] + k >= nums[r]) {
                // unequal hai toh ops -- kardo only if ops > 0
                if (nums[l] != nums[r]) {
                    if (ops > 0)
                        ops--;
                    else
                        break;
                }
                r++;
            }
            ans = max(ans, r - l);
            cout<<ans<<endl;
            l++;
        }
        return ans;
    }
};
