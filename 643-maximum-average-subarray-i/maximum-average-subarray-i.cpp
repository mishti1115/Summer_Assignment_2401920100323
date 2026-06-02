class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        int n = nums.size();
        int i = 0;
         int j = 0;
         double avg ;
         double maxi = INT_MIN;
         double size = k;
         while(j<n) {
            sum = sum + nums[j];
            if(j-i + 1==k) {
                avg = (double)sum/ size;
                maxi = max(maxi, avg);
                sum -=nums[i];
                i++;
            }
            j++;
         }
          return maxi;
    }
   
};