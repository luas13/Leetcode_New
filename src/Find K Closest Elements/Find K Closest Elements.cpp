// Soln1: Using Binary Search find the right index
// Traverse left & right to get the best neighbors
// Around 130 ms

class Solution {
public:
    int findIndex(vector<int>& arr, int x, int low, int high)
    {
        if (low > high)
            return -1;
        int mid = low + (high - low)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x && x < arr[mid+1])
            return mid;
        if (arr[mid] > x)
            return findIndex(arr, x, low, mid-1);
        return findIndex(arr, x, mid+1, high);
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        int l = arr.size();
        if (!l)
            return result;
        
        int index = findIndex(arr, x, 0, l-1);
        multiset<int> tset;
        
        if (index == -1)
            index = 0;
        
        int li;
        int ri = index+1;
        
        if (arr[index] == x)
        {
            tset.insert(x);
            k--;
            
            li = index-1;
        }
        else
            li = index;
            
        while(k > 0 && li >= 0 && ri < l)
        {
            if (x-arr[li] <= arr[ri]-x)
            {
                tset.insert(arr[li--]);
                k--;
            }
            
            if (!k)
                break;
            
            if (x-arr[li] > arr[ri]-x)
            {
                tset.insert(arr[ri++]);
                k--;
            }
        }
        
        if (k!=0)
        {
            if (li<0)
            {
                for(int i= ri; k>0 && i<l; i++, k--)
                    tset.insert(arr[i]);
            }
            
            if (ri>=l)
            {
                for(int i= li; k>0 && i>=0; i--, k--)
                    tset.insert(arr[i]);
            }
        }
        
        return vector<int> (tset.begin(), tset.end());
    }
};

// Soln 2: Best but a little bit convoluted
// Most elegant soln
// Inject the algorithm in binary search itself
// initialise high to be arr.size() - k
// find the best index, here starting index

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0, high = arr.size() - k;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (x - arr[mid] > arr[mid + k] - x) 
                low = mid + 1;
            else high = mid;
        }

        return vector<int> (arr.begin() + low, arr.begin() + low + k);
    }
};