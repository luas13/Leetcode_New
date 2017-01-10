class mycomp{
public:
    bool operator()(pair<int,int> p1, pair<int, int> p2)
    {
        return (p1.second < p2.second);
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        int l = nums.size();
        if (!l)
            return result;
        
        unordered_map<int, int> mymap;
        for(int i=0; i<l; i++)
        {
            if (mymap.find(nums[i]) != mymap.end())
                mymap[nums[i]]++;
            else
                mymap.insert(pair<int, int>(nums[i], 1));
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomp> pq;
        for (auto it= mymap.begin(); it != mymap.end(); it++)
            pq.push(*it);
            
        while(k>0 && !pq.empty())
        {
            result.push_back(pq.top().first);
            k--;
            pq.pop();
        }
        return result;    
    }
};