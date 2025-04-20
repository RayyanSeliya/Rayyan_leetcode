class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long score=0;
        int i=0;
        int n=values.size();
        unordered_set<int>st;
        
        while(i>=0 && i<n && !st.count(i)){
                  st.insert(i);
            if(instructions[i]=="add"){
                score+=values[i];
                 i=i+1;
            }else if(instructions[i]=="jump"){
                i=(i+values[i]);   
            }
      
            
        }

        return score;
        
    }
};