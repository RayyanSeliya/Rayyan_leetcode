class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int rows=mat.size();
        int cols=mat[0].size();

        
        for(int i=0;i<rows;i++){
            int newidx=k%cols ;

            for(int j=0;j<cols;j++){
                if(i%2==0){
                    if(j-newidx <0 ){
                        if(mat[i][j-newidx+cols]!=mat[i][j]){
                            return false;
                        }
                    }else{
                        if(mat[i][j-newidx]!=mat[i][j]){
                            return false;
                        }

                    }
                }
                else{

                    if(j+newidx>=cols){
                        if((mat[i][j+newidx-cols])!=mat[i][j]){
                            return false;
                        }
                    }else{
                        if(mat[i][j+newidx]!=mat[i][j]){
                            return false;
                        }

                    }

                }
            }
        }

        return true;

    }
};