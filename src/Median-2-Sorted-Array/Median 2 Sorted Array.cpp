/*
Analysis:
Note that the definition of the Median:
(1) If the size of the sequence N is odd: N/2+1th element is median.
(1) If the size of the sequence N is even:  average of the N/2th and N/2+1th element is median.

So in this problem, median of the two sorted arrays is the (m+n)/2+1 th element (if m+n is odd),
the average of (m+n)/2 th and (m+n)/2+1 th  (if m+n is even).
E.g.,  [1,2,3],[5,6,7], the median is (3+5)/2 = 4.0.
          [1,2,3,4], [1,3,5,7,9], the median is 3.

Our task becomes finding the Kth (K or K+1, K=(m+n)/2) number in two sorted arrays, in O(log(m+n))
time constraint (what's in your mind to see log? Yes, binary search).

Similar to but slight different from binary search, we still divide K into two halves each time.
 Two pointers are used for each array, so that we can compare which side is smaller (?A[pa]>B[pb]).
E.g., A = [1,3,5,7,9]  B = [2,4,8,10,12,14,16,18]. K=(5+8) /2= 6.

pa = K/2 = 3;
pb = K-pa = 3;
         pa
A[1,3,5,7,9]
         pb
B[2,4,8,10,12,14,16,18]

if (A[pa]<B[pb]), which means the elements from A[0] to A[pa] must exist in the first Kth elements.
The next step now becomes finding the (K-pa) th (equals to K/2) element in the array A[pa:end] and B[].
 This procedure can be viewed as "cutting" K/2 elements from the "smaller" array, and continue find the
  other K/2 th elements from the "bigger" array and the array after the cut. Note that smaller and
  bigger here is the comparison of the last elements.

if (A[pa]>B[pb]), the same procedure is applied but we "cut" the B array.

In this way, every time we have "cut" K/2 elements from one of the arrays, the next time is to cut
(K/2) /2 elements from the new arrays, until:
(1) K=1, the smaller one from A[0] and B[0] is the "Kth element".
(2) One of the array meets the end. Then just return the current Kth element from the other array.

*/

#include <iostream>
#include <vector>

using namespace std;

double getMedian(vector<int>& nums1, int m, vector<int>& nums2, int n, int k){
    if (m > n)
        return getMedian(nums2, n, nums1, m, k);
    if (m == 0)
        return nums2[k-1];
    if (k == 1)
        return min(nums1[0], nums2[0]);
    int p1 = min(k/2, m);
    int p2 = k - p1;
    if (nums1[p1 - 1] <= nums2[p2 - 1]){
        std::vector<int> newNums1(nums1.begin()+p1, nums1.end());
        return getMedian(newNums1, m-p1, nums2, n, k-p1);
    }
    else{
        std::vector<int> newNums2(nums2.begin()+p2, nums2.end());
        return getMedian(nums1, m, newNums2, n-p2, k-p2);
    }
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int total = len1 + len2;
        if (total % 2){
            return (getMedian(nums1, len1, nums2, len2, total/2 + 1));
        }
        else{
            return ((getMedian(nums1, len1, nums2, len2, total/2) + getMedian(nums1, len1, nums2, len2, (total/2 + 1)) ) / 2);
        }
    }
};

int main()
{
    //cout << "Hello world!" << endl;
    std::vector<int> nums1;
    std::vector<int> nums2;
    nums1.push_back(2);
    //nums2.push_back(2);
    Solution s;// = new Solution();
    cout<<" The median is = "<<s.findMedianSortedArrays(nums1, nums2);
    return 0;
}
