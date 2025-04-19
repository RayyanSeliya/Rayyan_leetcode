class Solution {
public:

  int calculatelower(int start,int l,int end ,int element,vector<int>&nums,int&lower){
        int n=nums.size();
         while(start<n && start<=end){
                int mid=start+(end-start)/2;
                if((long long )element+(long long)nums[mid]>=(long long )lower){
                    l=mid;
                    end=mid-1;
                }else{
                    start=mid+1;

                }           

            }
            return l;
  }


 int calculateupper(int start,int u,int end ,int element,vector<int>&nums,int &upper){
    int n=nums.size();

         while(start<n && start<=end){

                int mid=start+(end-start)/2;
                if((long long )element+(long long)nums[mid]<=(long long )upper){
                    u=mid;
                    start=mid+1;
                }else{
                    end=mid-1;

                }           

            }
            return u;
  }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long  count=0;


        for(int i=0;i<n;i++){
            int start=i+1,end=n-1;
            int l=-1,u=-1;
            int element=nums[i];

           int low= calculatelower(start,l,end,element,nums,lower);
           cout<<low<<" low dekh "<<endl;
           int upp= calculateupper(start,u,end,element,nums,upper);
             cout<<upp<<" upp dekh "<<endl;
             if(upp!=-1 && low!=-1){
                  count+=(upp-low+1);
             }
        
       
        }
        return count;
        
    }
};