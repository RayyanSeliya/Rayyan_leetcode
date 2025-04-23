class Solution {
public:
        int digitsum(int x){
            int sum=0;

            while(x!=0){
                sum+=x%10;
                x/=10;

            }
            return sum;

        }
    int countLargestGroup(int n) {
        vector<int>mp(40,0);

        for(int i=1;i<=n;i++){
            int sum=digitsum(i);
            mp[sum]++;

        }
        int count=0;


        int maxi=*max_element(mp.begin(),mp.end());
         for(int i=1;i<mp.size();i++){
            if(mp[i]==maxi){
                count++;
            }
         }

         return count;

        
    }
};