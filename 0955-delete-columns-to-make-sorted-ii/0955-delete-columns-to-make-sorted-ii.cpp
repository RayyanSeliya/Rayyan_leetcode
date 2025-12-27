class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int rows=strs.size();
        int cols=strs[0].size();
        int ans=0;

        //ye isisliye rkh rhe hai kyuki agar starting ke columns sahi order me hai to aage ke columns se answer glt nah aajaye 
        vector<int>issorted(rows-1,false);
        
        for(int col=0;col<cols;col++){
            bool isnotok=false;

            for(int row=0;row<rows-1;row++){
                if(!issorted[row] && strs[row][col]>strs[row+1][col]){
                    isnotok=true;
                    ans++;
                    break;
                }
    
            }

            if(isnotok) continue;

            //agar voh column safe hai already sorted hai to use preserve karo 
            for(int i=0 ; i<rows-1;i++){
                if(!issorted[i] && strs[i][col]<strs[i+1][col]){
                    issorted[i]=true;
                }
            }

        }


        return ans;

        
    }
};