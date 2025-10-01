class Solution {
public:
    int numWaterBottles(int nb, int ne) {
        // brute force
        int ans = 0;
        while(nb >= ne){
            // 1. reduce nb
            nb = nb - ne;

            // 2. increment ans
            ans += ne;
            // 3. reward 1 to nb
            nb++;
        }
        return ans + nb;
    }
};
