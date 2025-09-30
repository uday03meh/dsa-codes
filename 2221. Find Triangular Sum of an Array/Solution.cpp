class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size() > 1){
            int previdx = 0;
            int nextidx = 1;
            while(nextidx != nums.size()){
                // update
                nums[previdx] = (nums[previdx] + nums[nextidx])%10;
                // increment
                previdx++;nextidx++;
            }
            // pop
            for(auto i : nums){
                cout<<i<<", ";
            }
            cout<<endl;
            nums.pop_back();
        }
        return nums[0];
    }
};
