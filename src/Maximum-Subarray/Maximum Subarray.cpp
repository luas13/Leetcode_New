//DP solution sum[i]=max( sum[i-1] + A[i], A[i])   max_sum= max(max_sum, sum[i] ), TC= O(n) SC= O(n)
//So here is Kadane's algorithm TC= O(n) SC= O(1)

class Solution {
public:
    int maxSubArray(int A[], int n) {
        
        if( n == 0 )
            return 0;

        if( n == 1 )
            return ( A[0] );
    
        int max_so_far =0, max_ending_here = 0;
        int maxv = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            if(maxv < A[i])
                maxv= A[i];
                
            max_ending_here += A[i];
            if(max_ending_here < 0)
                max_ending_here = 0;
            else if( max_so_far < max_ending_here )
                max_so_far = max_ending_here;
        }
        if(maxv < 0)
            return maxv;
            
        return max_so_far;
    }
};
