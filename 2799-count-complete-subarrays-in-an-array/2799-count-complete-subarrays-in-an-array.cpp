class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        for(auto it : nums){
            st.insert(it);
        }

        int result=0;


        int unicount=st.size();
        int i=0;
        int n=nums.size();

        unordered_map<int,int>mp;

        
        for(int j=0;j<nums.size();j++){

            mp[nums[j]]++;

            while(mp.size()==unicount && i<n ){
                result+=n-j; 
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
              
        }

        return result;
    }
};