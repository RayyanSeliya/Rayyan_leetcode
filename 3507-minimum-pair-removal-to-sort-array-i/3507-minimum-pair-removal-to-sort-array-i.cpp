class Solution {
public:

    bool issorted(vector<int>&arr){
        bool ans=true;
        int n=arr.size();


        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                ans=false;
                break;
            }
        }
        return ans;

    }

    int minimumPairRemoval(vector<int>& nums) {
      
        int count=0;

     if(issorted(nums)) return 0;


     while(true){
        if(issorted(nums)) break;

        int n= nums.size();

        map<int,vector<int>> mp;

        
        for(int i=0;i<n-1;i++){
            int sum=nums[i]+nums[i+1];
            //sum->indx
            mp[sum].push_back(i);
        }

        auto it=mp.begin();
        int indx=it->second[0];

        //newindex pe sum ko insert krdo and aage ka erase krdo 
        nums[indx]=nums[indx]+nums[indx+1];
        nums.erase(nums.begin()+indx+1);

        count++;

     }


return count;


    }
};