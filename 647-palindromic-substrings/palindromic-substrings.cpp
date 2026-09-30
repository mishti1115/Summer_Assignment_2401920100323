class Solution {
public:
    bool isPal(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (isPal(s, i, j))
                    ans++;
            }
        }

        return ans;
    }
};