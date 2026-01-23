class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {

        // copy into long long array to avoid runtime or overflow errors
        vector<long long> a(nums.begin(), nums.end());
        int n=nums.size();

        int count = 0;
        int badcount = 0;

        //sum,index
        set<pair<long long,int>>minpair;

        //to avoid creating the new array again and again aftermerging we can use this technique
        vector<int>previndx(n);
        vector<int>nextindx(n);

        for(int i=0;i<n;i++){
            previndx[i]=i-1;
            nextindx[i]=i+1;
        }

         //calculate badcount  and also create the minpair set 
        for (int i=0;i+1< a.size();i++) {
            if (a[i] > a[i + 1]) badcount++;
            minpair.insert({a[i]+a[i+1],i});
        }

        while (badcount != 0) {
         int firstindx=minpair.begin()->second;
         int secondindx=nextindx[firstindx];

         int first_left=previndx[firstindx];
         int second_right=nextindx[secondindx];

         //now start deleting the affected pairs in the set 
         minpair.erase(begin(minpair));


         //now u[dating the bad pairs 
         if(a[firstindx]>a[secondindx]){
            badcount--;
         }

        if(first_left>=0){
        //{d, (a+b)} //pehle bad tha baad me good ban gaya 
        if(a[first_left]>a[firstindx] && a[first_left]<=a[firstindx]+a[secondindx] ){
            badcount--;
        } //pehle good tha fir badpair ban gaya 
        else if(a[first_left]<=a[firstindx] && a[first_left]>a[firstindx]+a[secondindx] ){
            badcount++;
        }

        }


        //{(a,b) , d}
        if(second_right<n){
            //pehle good tha fir badpair ban gaya 
        if(a[second_right]>=a[secondindx] && a[second_right]< a[firstindx]+a[secondindx] ){
            badcount++;
        } 
        else if(a[second_right]<a[secondindx] && a[second_right]>= a[firstindx]+a[secondindx] ){
            badcount--;
        }
        }



        
        if(first_left>=0){
        minpair.erase({a[first_left]+a[firstindx],first_left});
        minpair.insert({a[first_left]+a[firstindx]+a[secondindx],first_left});

        }

        if(second_right<n){
        minpair.erase({a[secondindx]+a[second_right],secondindx});
        minpair.insert({a[firstindx]+a[secondindx]+a[second_right],firstindx});
        previndx[second_right]=firstindx;
        }


        nextindx[firstindx]=second_right;
        a[firstindx]+=a[secondindx];

       
        count++;
    

          
        }

        return count;
    }
};
