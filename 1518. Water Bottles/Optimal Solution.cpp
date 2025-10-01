class Solution {
public:
    int numWaterBottles(int nb, int ne) {
        // brute force
        int ans = 0;
        while(nb >= ne){
            // 1. increment ans
            ans += (nb/ne)*(ne);
            
            // 2. reduce nb
            // remaining + reward
            nb = nb%ne + nb/ne;
        }
        return ans + nb;
    }
};
