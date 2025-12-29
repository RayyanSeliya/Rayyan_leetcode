class Solution {
public:

    int firstnegativeelement(vector<int>& arr){
        int n=arr.size();
        int s=0,e=n-1;

        int store=-1;

        while(s<=e){
            int mid=s+(e-s)/2;

            if(arr[mid]>=0){
                s=mid+1; //right jaau 
            }
            else if(arr[mid]<0){
                store=mid;//pehle store karlo 
                e=mid-1; //aur pehle search karo left me ..
            }
        }

        return store;
    }



    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();

        for(auto & row : grid){
            int indx=firstnegativeelement(row);
            cout<<indx<<":"<<endl;
            if(indx!=-1){
              count+=(n-indx);
            }
            
        }

        return count;

    }
};