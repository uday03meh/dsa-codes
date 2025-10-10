// 1. Using 2 for loops
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        // k starting points starting from end
        int n = energy.size();
        for(int sp = n-1; sp >= n-k; sp--){
            for(int i = sp; i >= 0; i-=k){
                if(i + k < n)energy[i] += energy[i+ k];
            }
        }

        return *max_element(energy.begin(), energy.end());
    }
};

// 2. Single for loop
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        // k starting points starting from end
        int n = energy.size();
        for(int sp = n-1; sp >= 0; sp--){
            if(sp + k < n)energy[sp] += energy[sp+ k];
        }

        return *max_element(energy.begin(), energy.end());
    }
};
