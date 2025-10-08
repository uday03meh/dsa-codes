#define ll long long
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ll spell = spells[i];
            int count = 0;
            for(int j = 0; j < m; j++){
                if(spell * (ll)potions[j] >= success){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
