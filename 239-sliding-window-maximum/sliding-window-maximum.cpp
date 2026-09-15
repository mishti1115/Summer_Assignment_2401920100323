class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {

            // Window se bahar ho gaya
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Chhote elements ko remove karo
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Window complete hone ke baad answer
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};