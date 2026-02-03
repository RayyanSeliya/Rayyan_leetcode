class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int first=-1,second=-1,third=1;
        
        int n=nums.size();

        int i=0;

        while(i<n-1 && nums[i]<nums[i+1]){
            i++;
            first=i;

        }
        cout<<first<<endl;

        int j=n-1;


        while(j>0 && nums[j]>nums[j-1]){
            j--;
            second=j;

        }

        cout<<second<<"see second"<<endl;

        if(first!=-1 && second!=-1){
            for(int i=first;i<second;i++){
                if(nums[i]<nums[i+1]){
                    third=0;
                }
        }

        }
        
        

        if(first!=-1 && second!=-1  &&  first <second && third){
            return true;
        }else {
            return false;

        }
    }
};