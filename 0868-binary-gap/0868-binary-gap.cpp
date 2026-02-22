class Solution {
public:

    string convert(int n){
        string y="";

        while(n!=0){
            y.push_back((n%2)+'0');
            n/=2;

        }

        reverse(y.begin(),y.end());

        return y;
    }
    int binaryGap(int n) {
        string x=convert(n);
        unordered_set<int>st;
       
        int maxlen=0;

        for(int i=0;i<x.length();i++){

            if(x[i]=='1'){
                if(!st.empty()){
                int index=*st.begin();
                st.clear();
                maxlen=max(maxlen,i-index);
            }
            st.insert(i);

            }
            
        }

        return maxlen;


    }
};