class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;
        long long cost = 0;

        deque<pair<int,int>> dq;

        int r = n - 1;

        for(int l = n - 1; l >= 0; l--) {

            int cnt = 1;

            while(!dq.empty() && dq.front().first < nums[l]) {
                auto [val, freq] = dq.front();
                dq.pop_front();

                cost += 1LL * (nums[l] - val) * freq;
                cnt += freq;
            }

            dq.push_front({nums[l], cnt});

            while(cost > k) {

                int val = nums[r];

                auto [mx, freq] = dq.back();
                dq.back().second--;

                cost -= (mx - val);

                if(dq.back().second == 0)
                    dq.pop_back();

                r--;
            }

            ans += r - l + 1;
        }

        return ans;
    }
};