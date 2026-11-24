class Solution {
public:
    int getMask(int x) {
        int mask = 0;

        if (x % 2 == 0) mask |= (1 << 0);
        if (x % 3 == 0) mask |= (1 << 1);
        if (x % 5 == 0) mask |= (1 << 2);
        if (x % 7 == 0) mask |= (1 << 3);

        return mask;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;   // every length-2 subarray is valid

        vector<int> masks(n);
        for (int i = 0; i < n; i++) {
            masks[i] = getMask(nums[i]);
        }

        for (int i = 0; i < n; i++) {
            int used = 0;

            for (int j = i; j < n; j++) {
                if (used & masks[j]) break;

                used |= masks[j];
                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};