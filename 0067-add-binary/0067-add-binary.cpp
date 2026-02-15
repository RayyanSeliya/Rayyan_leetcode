class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.length();
        int m=b.length();

        if(n<m){
            a.insert(0,m-n,'0');
        }else if(n>m){
            b.insert(0,n-m,'0');
        }


        string ans="";
        int carry=0;

        n=a.length();



        for(int i=n-1;i>=0;i--){
            int sum=0;
            if(a[i]=='1' && b[i]=='1'){
                sum=2+carry;
                cout<<"if sum"<<sum<<endl;
            }else{
                sum=(a[i]-'0')+(b[i]-'0')+carry;
               
            }

            ans.push_back((sum%2)+'0');
            carry=sum/2;


            }

        if(carry){
            ans.push_back('1');
        }


        
       

        reverse(ans.begin(),ans.end());

        return ans;

    }
};