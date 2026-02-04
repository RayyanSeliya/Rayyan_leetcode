class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
         int n = nums.size();
        long long ans = LLONG_MIN;

        int i = 1;
        while (i < n - 2) {
            //  Find strictly decreasing middle segment
            int midL = i, midR = i;
            long long midSum = nums[i];

            while (midR + 1 < n && nums[midR + 1] < nums[midR]) {
                midSum += nums[++midR];
            }

            // Need at least one decreasing step
            if (midL == midR) {
                i++;
                continue;
            }

            // Expand left strictly increasing
            long long leftSum = 0, bestLeft = LLONG_MIN;
            int l = midL;

            while (l - 1 >= 0 && nums[l - 1] < nums[l]) {
                leftSum += nums[--l];
                bestLeft = max(bestLeft, leftSum);
            }

            if (bestLeft == LLONG_MIN) {
                i++;
                continue;
            }

            // Expand right strictly increasing
            long long rightSum = 0, bestRight = LLONG_MIN;
            int r = midR;

            while (r + 1 < n && nums[r + 1] > nums[r]) {
                rightSum += nums[++r];
                bestRight = max(bestRight, rightSum);
            }

            if (bestRight == LLONG_MIN) {
                i++;
                continue;
            }

            // Combine
            ans = max(ans, bestLeft + midSum + bestRight);

            // Jump i to avoid reprocessing
            i = midR;
        }

        return ans;
    }
};