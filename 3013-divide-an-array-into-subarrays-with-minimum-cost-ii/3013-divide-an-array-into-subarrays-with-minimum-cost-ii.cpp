class Solution {
public:
    typedef long long ll;
    typedef pair<ll ,ll> p;
     

    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n=nums.size();
        set<p>kminimum ;// stores kminimum elements in the present window 
        set<p>remaining ;//stores the unwanted popped up element (larger ones )

        ll sum=0; // stores minimum sum  elements  at that present window 

        int i=1;

        //fill the minimumelement set until thelast part of the subarray occurs isisliye i-dist <1
        while(i-dist<1){
            kminimum.insert({nums[i],i});
            sum+=nums[i];

            //agar k-1 se zyada element aagya set me to  larger vale ko remove krna hoga 
            if(kminimum.size()>k-1){
                p temp = *kminimum.rbegin();
                sum-=temp.first;
                remaining.insert(temp);
                kminimum.erase(temp);
            }
            i++;
        }


        ll result=LONG_MAX; //stores minimum sum of k-1 elements 

        //0, 1 ... 
        //ab ek window ban gyi ab shifting start 
    
        while(i<n){
            kminimum.insert({nums[i],i});
            sum+=nums[i];


              //agar k-1 se zyada element aagya set me to  larger vale ko remove krna hoga 
            if(kminimum.size()>k-1){
                p temp = *kminimum.rbegin();
                sum-=temp.first;
                remaining.insert(temp);
                kminimum.erase(temp);
            }


            result=min(result,sum );
             
             //shift the window by excluding the i-dist element anbd add the new i+1 element 
            p remove= {nums[i-dist],i-dist};
            if(kminimum.count(remove)){
                sum-=remove.first;
                kminimum.erase(remove);

                //agar hatay hai toh size kam hogya required toh check ki koi transfer ho skta hai kya 
                if(!remaining.empty()){
                    p temp = *remaining.begin();
                    kminimum.insert(temp);
                    sum+=temp.first;
                    remaining.erase(temp);
                }

            }else{
                remaining.erase(remove);
            }

            i++;

        }


        return nums[0]+result;

    }
};