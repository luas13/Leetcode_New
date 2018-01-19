1st Method

/*
Sum of gas of all stations >= Sum of cost of all stations => Soln exist
Tank = Sum of differences of gas & cost from current start point
Keep updating start station and resetting tank, if tank < 0
In total we have all the accumulated -ve values to the left of current start

At the end check if sum of total & tank > 0, then the current start is the answer
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() != cost.size())
            return 0;
        int l = gas.size();
        
        int start=0, tank=0, total=0;
        
        for(int i=0; i<l; i++)
        {
            tank += gas[i] - cost[i];
            if (tank < 0)
            {
                total += tank;
                start = i + 1;
                tank = 0;
            }
        }
        return ((total+tank) < 0)? -1: start;
    }
};

------------------------------------------------------------------------------------------------------------------
2nd Method

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
