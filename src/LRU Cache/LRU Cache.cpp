// Also see LRU cache from geeksforgeeks.org

class LRUCache {
private:
    // <key, iterator of a pair<key, value> >
    unordered_map<int, list<pair<int,int>>::iterator> mymap;
    // key, value
    list<pair<int,int>> dq;
    int csize;
    
public:
    LRUCache(int capacity) {
        csize = capacity;
    }
    
    int get(int key) {
        if (mymap.find(key) == mymap.end())
            return -1;
        else
        {
            // make sure item which is referenced is brought 
            // to the front of deque
            pair<int, int> tmp = *(mymap[key]);
            dq.erase(mymap[key]);
            dq.push_front(tmp);
            mymap[key] = dq.begin();
            
            return tmp.second;
        }
    }
    
    void put(int key, int value) {
        if (mymap.find(key) == mymap.end())
        {
            if (dq.size() == csize)
            {
                // Imp, dq.back() doesn't return an iterator
                // but here returns a pair
                pair<int, int> tmp = dq.back();
                dq.pop_back();
                mymap.erase(tmp.first);
            }
        }
        else
            dq.erase(mymap[key]);
        dq.push_front(make_pair(key, value));
        mymap[key] = dq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */