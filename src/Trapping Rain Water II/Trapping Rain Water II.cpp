class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size()==0) return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        int row = heightMap.size(), col = heightMap[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        int ans = 0, Max = INT_MIN;
        
        // Insert Border elements of 2D Elevation map
        // Mark all border elements as Visited
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(!(i==0 || i==row-1 || j==0 || j==col-1)) continue;
                //cout<<"Coordinates are: "<<i<<", "<<j<<endl;
                //cout<<"Height= "<<heightMap[i][j]<<endl;
                que.push(make_pair(heightMap[i][j], i*col+j));
                visited[i][j] = 1;
            }
        }
        
        // For each popped element of pq check its 4 neighbouring
        // elements and keep adding to water when height of neighbouring element
        // is smaller than the current max height
        // Initially 1st popped element will be the smallest of all border elements
        // The max height at this stage is itself.
        // Visualise using this example
        //[[5,5,5,1],
	    // [5,1,1,5],
	    // [5,1,5,5],
	    // [5,2,5,8]]
	    // Think of how water can flow inwards and get trapped
	    
        vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!que.empty())
        {
            auto val = que.top(); que.pop();
            int height = val.first, x = val.second/col, y = val.second%col;
            //cout<<"Coordinates are: "<<x<<", "<<y<<endl;
            //cout<<"Height= "<<height<<endl;
            
            Max = max(Max, height);
            for(auto d: dir)
            {
                int x2 = x + d[0], y2 = y + d[1];
                if(x2>=row || x2<0 || y2<0 || y2>=col || visited[x2][y2]) continue;
                visited[x2][y2] = 1;
                if(heightMap[x2][y2] < Max) 
                {
                    ans += Max - heightMap[x2][y2];
                    //cout<<"ans "<<ans<<endl;
                }
                que.push(make_pair(heightMap[x2][y2], x2*col+y2));
            }
        }
        return ans;
    }
};