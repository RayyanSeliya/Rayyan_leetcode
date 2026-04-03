class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // map<int,int>m;
        // for(int i=0;i<nums.size();i++){
        //     m[nums[i]]++;
        // }

        // int ans=0;

        // for(auto i:m){
        //     if(i.second>(nums.size() /2)){
        //       ans+=i.first;

        //     }
        // }

        // return ans;

        int count = 0;
        int elem;

        for (int i = 0; i < nums.size(); i++) {

            if (count == 0) {
            count++;
             elem = nums[i];

            }

            else if (nums[i] == elem) {
                count++;

            } else {
                count--;
            }
        }

        for (auto i : nums) {
            if (i == elem) {
                count++;
            }
        }

        if (count> (nums.size() / 2)) {
            return elem;
        }

        return -1;
    }
};