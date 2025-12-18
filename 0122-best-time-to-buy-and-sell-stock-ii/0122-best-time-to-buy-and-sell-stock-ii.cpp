class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>x(n,0);

        x[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
           if(prices[i]>prices[i+1]){
            x[i]=prices[i];
           }else{
            x[i]=prices[i+1];
           }
        }

       
        int ans=0;
        for(int i=0;i<n;i++){
            ans += (x[i]-prices[i]);

        }
        return ans;

        
    }
};