/*
T.C: nlogk

Keep the window elements in a multiset and keep an iterator 
pointing to the middle value (to "index" k/2, to be precise)

1. There might be duplicates, so use a multiset for a window
2. insert(x) in multiset is logarithmic as multiset is based on BST
3. Make use of mext and prev iterators
4. Time complexity for next and prev is 
    Constant for random-access iterators and 
    Linear in n for bidirectional iterators.
5. Multiset uses bidirectional iterators so tc is linear
6. std::multiset::lower_bound: Returns an iterator pointing to the 
first element in the container which is not considered to go 
before val (i.e., either it is equivalent or goes after).
T.C: logarithm
7. Similarly std::multiset::upper_bound: Returns an iterator pointing 
to the first element in the container which is considered to go after val.
8. T.C for erase(position) is amortized constant.

*/
class Solution {
  public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        multiset<int> window;
        vector<double> medians;
        for (int i = 0; i < nums.size(); i++) {
            window.insert(nums[i]);
            if (window.size() >= k) {
                auto mid = next(window.begin(), k / 2);
                cout<<"mid val: "<<*mid<<endl;
                medians.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);
                window.erase(window.lower_bound(nums[i - k + 1]));
            }
        }
        return medians;
    }
};