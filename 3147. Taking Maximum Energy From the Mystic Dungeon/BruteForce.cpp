class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = -1e9;
        for(int sp = 0; sp < energy.size(); sp++){
            int sum = 0;
            for(int i = sp; i < energy.size(); i+= (k)){
                sum += energy[i];
            }
            ans = max(sum, ans);
        }
        return ans;
    }
};
// TLE aaayega
