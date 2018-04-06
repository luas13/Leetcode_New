/*
My soln: 1

unordered_map<long long, set<long long>> hash to keep track of the amount
of jumps one can take from a particular index, set bcz it will be in sorted manner
& we can again evaluate the same for the indexes which can be reached from current
index.

queue<long long> keeps track of index which needs computation

unordered_map<long long, long long> stones_map keeps track of which
position are safe i.e. stones exists, it's just a mapper

For every new location you reach, populate it's set with k-1, k, k+1 steps, where k 
was used to reach it

At the end just check if the set corresponding to last stone is non empty, that will suggest
that at least one previous index has the jump capability to reach till last stone. eg. Let's 
say if the frog's last jump was k units from any previous index i which made it reach the last 
stone then the set corressponding to last stone will have at least these values (k-1, k, k+1 ...).
I put ... because last stone could be reached from more than 1 previous index. Since we also
have an optimization check 

if (newv == stones[l-1])
 	return 1;

this will ensure that we return true if it's possible the moment we reach last stone.
At the end if we can't reach the last stone then that statement comes into picture.

*/

class Solution {
public:
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
   
    // 2nd Method:
	
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

//---------------------------------------------------------
// 2nd Method Clean code
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int l = stones.size();
        
        if (!l || l==1 || stones[1] != 1)
            return false;
        
        unordered_map<long long, unordered_set<long long>> hash;
        hash[0].insert(0);
        
        for( long long pos: stones)
        {
            for(long long step: hash[pos])
            {
                if (step - 1 > 0) hash[pos + step-1].insert(step-1);
                hash[pos + step].insert(step);
                hash[pos + step+1].insert(step+1);
            }
        }
        
        return (!hash[stones[l-1]].empty());
    }
};
