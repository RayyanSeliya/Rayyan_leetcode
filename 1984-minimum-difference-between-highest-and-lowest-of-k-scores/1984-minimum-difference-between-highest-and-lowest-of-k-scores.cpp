class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        int min_diff=INT_MAX;
        int i=0;
        int j=k-1;
        while(j<nums.size()){

            int diff=nums[j]-nums[i];
            min_diff=min(min_diff,diff);
            
            i++;
            j++;


        }
        

        return min_diff;
        



    }
};