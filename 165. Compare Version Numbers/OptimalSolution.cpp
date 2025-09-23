class Solution {
public:
    int compareVersion(string a, string b) {
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        while(i < n || j < m){
            int num1 = 0, num2  =0 ;
            while(i < n && a[i] != '.'){
                // building the num1
                num1 = num1 * 10;
                num1 += a[i] - '0';
                i++;
            }
            while(j < m && b[j] != '.'){
                // building the num1
                num2 = num2 * 10;
                num2 += b[j] - '0';
                j++;
            }
            if(num1 < num2){
                return -1;
            }
            else if(num1 > num2){
                return 1;
            }

            // increment both i and j because they were stuck at '.'
            i++;j++;
        }
        // Time Complexity = O(max(n, m))
        // space Complexity = O(max(n, m))
        return 0;
    }
};
