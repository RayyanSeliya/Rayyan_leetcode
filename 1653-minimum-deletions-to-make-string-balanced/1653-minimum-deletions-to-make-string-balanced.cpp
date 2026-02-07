class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        int i=0;
        int ans=0;


        while(i<n){

            if(s[i]!='b'){
                i++;
                continue;
            }

            int bcount=0;
            int acount=0;

            while(i<n && s[i]=='b'){
                bcount++;
                i++;
            }

            while(i<n && s[i]=='a'){
                acount++;
                i++;
            }

            ans+=min(acount,bcount);
            

        }

        return ans;


    }
};