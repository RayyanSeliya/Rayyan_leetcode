class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n,0);

        for(int i=0;i<n;i++){
            if(nums[i]>0){
            int index=(nums[i]+i) % n ;
            result[i]=nums[index];
            }else{
                int index2 =(nums[i]+i) %n ;
                if(index2<0) index2+=n;
                result[i]=nums[index2];
            }

        }

        return result;

    }
};