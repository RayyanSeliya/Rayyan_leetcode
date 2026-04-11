class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;

        int answer=INT_MAX;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);

        }

        for(auto it : mp ){
            vector<int>& idx = it.second;
            int n=idx.size();

            if(n<3){
                continue;
            }

            // ab is vector me 3 size ka window pe min nikalo 
            for(int i=0;i<=n-3;i++){
                int j=i+2;
                int sum= 2*(idx[j]-idx[i]);
                answer = min(answer, sum);  

            }

        }
        return answer==INT_MAX ?-1 : answer ;
  
    }
};