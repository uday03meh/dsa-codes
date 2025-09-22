class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // 1. freq table
        // element, frequency
        map<int, int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        // O(n(logn)) TC
        // O(n) SC
        
        // 2 Find maximum frequency
        int f = 1;
        for(auto i : mp){
            // i.first -> key
            // i.second -> value
            f = max(f, i.second);
        }
        // SC = O(1)
        // TC = O(n)

        // 3. Increment count if frequency of that element matches
        // the frequency of f
        int count = 0;
        for(auto i : mp){
            if(f == i.second){
                count += f;
            }
        }
        // SC = O(1)
        // TC = O(n)
        
        return count;

    }
};
