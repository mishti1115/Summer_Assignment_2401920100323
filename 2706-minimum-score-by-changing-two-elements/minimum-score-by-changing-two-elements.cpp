class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        if (n <= 3) return 0;

        sort(nums.begin(), nums.end());

        return min({
            nums[n - 3] - nums[0],   // change two largest
            nums[n - 2] - nums[1],   // change one smallest, one largest
            nums[n - 1] - nums[2]    // change two smallest
        });
    }
};