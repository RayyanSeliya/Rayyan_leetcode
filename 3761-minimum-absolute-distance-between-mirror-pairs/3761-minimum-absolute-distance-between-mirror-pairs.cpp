class Solution {
public:
    int reverseint(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            int rev = reverseint(nums[i]);

            // check if current matches any previous reversed
            if(mp.count(nums[i])) {
                ans = min(ans, i - mp[nums[i]]);
            }

            // store reversed value
            mp[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};