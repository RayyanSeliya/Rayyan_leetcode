class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int maxi=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=maxi){
                count++;
                maxi=max(maxi,nums[i]);
            }
        }
        return count;
        
    }
};