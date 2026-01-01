class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n=digits.size();
        vector<int>res;
        
        int digit=digits[n-1];
        int num=digit+1;
        int sum=0,carry=0;
        sum=num%10;
        carry=num/10;
        res.push_back(sum);

        

        for(int i=n-2;i>=0;i--){
            
        int digi=digits[i];
        int ans=digi+carry;
        carry=ans/10;
        sum=ans%10;
        res.push_back(sum);

        }
        if(carry){
            res.push_back(carry);
        }
        
    reverse(res.begin(),res.end());

    return res;

    

    }
};