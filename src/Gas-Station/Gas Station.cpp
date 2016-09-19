//keep inserting the station in the queue till curr_gas is not negative,the moment it becomes negative start dequeing 
// from the queue.Queue is implemented through the array and two flags s and e.

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if(!gas.size() || !cost.size() || gas.size() != cost.size())
            return -1;
            
        int s=0,e=1;
        int curr_gas= gas[s] - cost[s];
        
        while(e != s || curr_gas < 0)
        {
            while(curr_gas < 0 && s != e)
            {
                curr_gas -= gas[s] - cost[s];
                s= (s+1) % cost.size();
                
                if(s == 0)
                    return -1;
            }
            
            curr_gas += gas[e] - cost[e];
            e= (e+1) % cost.size();
        }
        return s;
        
    }
};
