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