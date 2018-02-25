class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int l = tasks.size();
        if (!l)
            return 0;
        
        unordered_map<char, int> mymap;
        for(int i=0; i<l; i++)
            mymap[tasks[i]]++;
        
        priority_queue<int> pq;
        for (auto it = mymap.begin(); it != mymap.end(); it++)
            pq.push(it->second);
        
        int cycle = n+1;
        int total=0;
        
        while (!pq.empty())
        {
            int time =0;
            vector<int> mylist;
            
            for(int i=0; i<cycle; i++)
            {
                if (!pq.empty())
                {
                    mylist.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            
            for(auto it = mylist.begin(); it != mylist.end(); it++)
            {
                if (--*it)
                    pq.push(*it);
            }
            
            total += pq.empty() ? time : cycle;
        }
        return total;
        
    }
};