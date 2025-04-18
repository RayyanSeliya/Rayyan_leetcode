class Solution {
public:
int solve(vector<int>&nums,vector<int>&dp,int i){

    //base case 
    if(i>=nums.size()) return 0;
    

    //already calculated
    if(dp[i]!=-1) return dp[i];

    int include =nums[i]+ solve(nums,dp,i+2);
    int skip=solve(nums,dp,i+1);
    dp[i]=max(include,skip);

    return dp[i];



}



    int rob(vector<int>& nums) {

        vector<int>dp(nums.size(),-1);
        int i=0;
        return solve(nums,dp,i);

        
    }
};