#define ll long long
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int numneg = 0, denneg = 0;
        ll num = numerator, den = denominator;

        if (num < 0 && den > 0) {
            numneg++;
            num *= -1;
        }
        if (num > 0 && den < 0) {
            denneg++;
            den *= -1;
        }
        ll q = num / den;
        ll r = num % den;
        string ans = to_string(q);
        // building up the part before decimal

        if ((numneg + denneg) == 1) {
            ans.insert(0, "-");
        }
        if (r == 0) {
            // simply return the answer
            return ans;
        }
        ans += ".";
        map<int, int> mp;
        // element (remainder) -> idx
        // remainder != 0
        while (r != 0) {
            if (mp.find(r) != mp.end()) {
                // we have that number in map already
                ans.push_back(')');
                ans.insert(mp[r], "(");
                break;
            }

            else {
                mp[r] = ans.size();
                r = r * 10;
                q = r / den;
                r = r % den;
                ans += to_string(q);
            }
        }
        return ans;
    }
};
