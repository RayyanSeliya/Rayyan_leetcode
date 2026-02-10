class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_set<int>st1;
        unordered_set<int>st2;
        int maxlen=0;

        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                 if(nums[j]%2==0){
                    st1.insert(nums[j]);
                 }else{
                    st2.insert(nums[j]);
                 }
                 if(!st1.empty()&& !st2.empty()&& st1.size()==st2.size()){
                  maxlen=max(maxlen,j-i+1);
                  }
            }
            st1.clear();
            st2.clear();
            
        }

        return maxlen;

    }
};