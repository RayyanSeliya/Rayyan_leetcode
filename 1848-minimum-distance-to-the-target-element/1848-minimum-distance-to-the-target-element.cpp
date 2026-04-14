class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        

        int n=nums.size();
        int left=-1,right=-1;
    
        

        for(int i=start;i>=0;i--){
            if(nums[i]==target){
                left=i;
                break;
            }
        }

          for(int i=start;i<n;i++){
            if(nums[i]==target){
                right=i;
                break;
            }
        }

        int minimum=100000;

        if(right!=-1 && left!=-1){
            if(start-left >right-start){
                minimum=right;
            }else{
                minimum=left;
            }
           
        }else if(right!=-1){
            minimum=right;
        }else{
            minimum=left;
        }
       

        return abs(minimum-start);


    }
};