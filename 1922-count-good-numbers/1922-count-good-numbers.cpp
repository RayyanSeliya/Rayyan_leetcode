class Solution {
public:

  const long long  MOD=1000000007;

   
   long long  solve(long long base,long long exponent,long long  MOD){
   long long result=1;

   while(exponent!=0){


    if(exponent&1){
        result=(result*base) % MOD;

    }

    base=(base*base)% MOD;
    exponent/=2;

   }
   

return result;



   }





    int countGoodNumbers(long long n) {

     long long evencount=(n+1)/2;
     long long oddcount=n/2;
    long long ans=( (solve(5,evencount,MOD) * solve(4,oddcount,MOD) )  ) % MOD;

    return ans;

    }
};