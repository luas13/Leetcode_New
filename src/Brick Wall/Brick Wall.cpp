class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int r = wall.size();
        int c = wall[0].size();
        
        if(!r)
            return 0;
        
        int rows=0;
        for(int i=0; i<c; i++)
            rows += wall[0][i];
        
        map<int, int> mymap;
        int sum = 0, maxvc= 0;
        for(int i=0; i<r; i++)
        {
            sum = 0;
            for(int j=0; j<wall[i].size(); j++)
            {
                sum += wall[i][j];
                if(sum != rows)
                {
                    if(mymap.find(sum) == mymap.end())
                        mymap[sum] = 1;
                    else
                        mymap[sum]++;

                    if(maxvc < mymap[sum])
                        maxvc = mymap[sum];
                }
            }
        }
        
        return maxvc==1 ? r-1: r-maxvc; 
    }
};