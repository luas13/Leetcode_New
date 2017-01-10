class Solution {
public:
    /*
    // Below solution is using queue and unordered map of <int, set>
    // It takes 812 ms but is quite intuitive
    bool canCross(vector<int>& stones) {
        int l = stones.size();
        if (!l || l==1 || stones[1] != 1)
            return false;
        queue<long long> q;
        
		// unordered_map<long long, unordered_set<long long>> wont help
		// will fail for this test case: [0,1,3,6,10,13,15,18]
		
		unordered_map<long long, set<long long>> hash;
        
        unordered_map<long long, long long> stones_map;
        for(int i=0; i<l; i++)
            stones_map[stones[i]] = 1;
            
        hash[1].insert(1);
        hash[1].insert(2);
        q.push(1);
        
        while(!q.empty())
        {
            int index = q.front();
            //cout<<"q index val = "<<index<<endl;
            q.pop();
            set<long long> tmp = hash[index];
            
            for (auto it = tmp.begin(); it != tmp.end(); it++ )
            {
                //cout<<"*it = "<<*it<<endl;
                long long newv = index + *it;
                //cout<<"newv= "<<newv<<endl;
                
                if (newv == stones[l-1])
                    return 1;
                        
                if (stones_map[newv])
                {
                    if (hash[newv].empty())
                    {
                        q.push(newv);
                        //cout<<"value pushed in q is ="<<newv<<endl;
                    }
                    //else
                      //  cout<<"value "<<newv<<" already exist in hash"<<endl;
                        
                    hash[newv].insert(*it - 1);
                    hash[newv].insert(*it);
                    hash[newv].insert(*it + 1);
                }
            }
        }
        return (!hash[stones[l-1]].empty());
    }
    */
    
    // Below is a DP solution. O(N*N)
    // The elegance is you just need to add entries of the index which
    // can be reached in a hash table. At the same time we also add the
    // step by which that index is reached. Imp point here is u just run
    // a for loop picking the index where stone lies and not all the index
    // reachable which got entries in hash table. At the end check whether  
    // there is an entry of stones.back() in hash table or can put a 
    // check before also.
    
    bool canCross(vector<int>& stones) {
        int l = stones.size();
        if (!l || l==1 || stones[1] != 1)
            return false;
            
        unordered_map<long long, unordered_set<long long>> hash;
        hash[0].insert(0);
        
        // There is one important difference between map::find() and 
        // map::operator []. While map::find() will never change the 
        // contents of map, operator [] will create an element if it
        // does not exist. In some cases this could be very convenient,
        // but it’s definitly a bad idea to use operator [] many times
        // in a loop, when you do not want to add new elements. That’s
        // why operator [] may not be used if map is passed as a const
        // reference parameter to some function.
        
        for (long long pos : stones)
        {
            for (long long step : hash[pos])
            {
                if (step - 1 > 0)   hash[pos + step -1].insert(step-1);
                hash[pos + step].insert(step);
                hash[pos + step + 1].insert(step+1);
                
                //if (!hash[stones[l-1]].empty())
                  //  return true;
                // Better to use as above may add entry of stones[l-1]
                // 2nd aspect: One downfall to check this in a loop is
                // the time of execution goes to 572ms while it goes
                // 532 ms if i dont use
                
                //if (hash.find(stones[l-1]) != hash.end())
                    //return true;
            }
        }
        return (!hash[stones[l-1]].empty());
    }
    
};