class Solution {
public:
    int lowbs(vector<int> &nums, int target){
        int l = 0, r = nums.size()-1;
        // give me smallest element's index which is >= x-k
        int ans = r;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] >= target){
                ans = min(ans, mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }

    int highbs(vector<int> &nums, int target){
        int l = 0, r = nums.size()-1;
        // give me biggest element's index which is <= x+k
        int ans = 0;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] <= target){
                l = mid + 1;
                ans = max(ans, mid);
            }
            else r = mid - 1;
        }
        return ans;
    }
    int maxFrequency(vector<int>& nums, int k, int numops) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        map<int, int> mp;
        for(auto i : nums)mp[i]++;
        int ans = 1;
        for(int x = nums[0]; x <= nums[n-1]; x++){
            int l = lowbs(nums, x-k);
            int r = highbs(nums, x+ k);
            // cout<<"x: "<<x<<endl;
            // cout<<"l: "<<l<<endl;
            // cout<<"r: "<<r<<endl;
            int ops = 0;
            if(mp.find(x) != mp.end()) ops = r - l + 1 - mp[x]; // +ve quanitty
            else ops = r - l + 1;
            ops = min(numops, ops);
            // cout<<"ops: "<<ops<<endl;
            ans = max(ans, mp[x] + ops);
            // cout<<"ans: "<<ans<<endl;
            
        }
        return ans;
    }
};
