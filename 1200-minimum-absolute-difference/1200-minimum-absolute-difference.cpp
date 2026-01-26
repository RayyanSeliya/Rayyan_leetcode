class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;

        int mindiff = INT_MAX;
        for (int i= 1;i <n; i++) {
            mindiff =min(mindiff, arr[i] - arr[i - 1]);
        }

        for (int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i - 1];
            if (diff == mindiff) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};