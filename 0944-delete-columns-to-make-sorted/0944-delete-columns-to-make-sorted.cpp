class Solution {
public:

    bool issortedasc(vector<int>&num){

        for(int i=0;i<num.size()-1;i++){
            if(num[i]>num[i+1]){
                return false;

            }
        }

        return true;


    }


    int minDeletionSize(vector<string>& strs) {
        int ans=0;
   

        int rows=strs.size();
        int cols=strs[0].size();


        for(int i=0;i<cols;i++){
                vector<int>arr;
            for(int j=0;j<rows;j++){
                arr.push_back((strs[j][i])-'a');
            }  
            if(!issortedasc(arr)){
                ans++;
            }
        }

        return ans;

    }
};