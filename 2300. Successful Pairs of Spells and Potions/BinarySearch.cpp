#define ll long long
class Solution {
public:
    int binarysearch(ll success, vector<int> &potions, ll spell){
        
        int m = potions.size();
        
        int start = 0, end = m-1;
        int idx = m;
        
        while(start <= end){
            int mid = (start + end)/2;
            if(spell*potions[mid] >= success){
                end = mid - 1;
                idx = min(mid, idx);
            }
            else {
                start = mid + 1;
            }
        }

        return m - idx;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ll spell = spells[i];
            int count = binarysearch(success, potions, spell);
            ans.push_back(count);
        }
        return ans;
    }
};
