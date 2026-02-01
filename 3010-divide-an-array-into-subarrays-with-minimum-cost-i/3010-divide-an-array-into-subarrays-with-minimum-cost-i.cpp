class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans=nums[0];

        int firstsmall=INT_MAX;
        int secondsmall=INT_MAX;


        for(int i=1;i<nums.size();i++){
            if(nums[i]<firstsmall){
               secondsmall=firstsmall;
              firstsmall=nums[i];
            }else if(nums[i]<secondsmall){
                secondsmall=nums[i];
            }
        }
       
       int sum=firstsmall+secondsmall;

        return sum+ans;
        
    }
};