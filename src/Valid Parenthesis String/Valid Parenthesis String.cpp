/*
Why low = max(low, 0) ?
So you can't use * as a right bracket where there are no left brackets to match with.
For example: s = '*(()'.

low is lowest POSSIBLE number of OPEN left bracket, which means possibly it 
can't go below 0 because we have the liberty to consider * as empty

At the end of the iteration low can be anything positive or zero.
At the end we check whether low == 0, because
If low is greater than 0, it means that the number of left parentheses is too much, 
there are not enough right parentheses to offset, and false is returned. 
It cannot be negative because low is decremented only when low is greater than 0.

In essence, low is decremented on the occurence of ‘*’ only when low is > 0 . This means 
that we will treat ‘*’ as closing braces upto the point of maintaining low to zero.
In rest cases we will treat '*' as empty

When high is less than 0 at any time, it means that there are too many right parentheses 
and return false
 
Another way to think:
low: the number of the left parenthesis when the asterisk is treated as the right parenthesis or empty charcter
high: the number of left parenthesis when the asterisk is treated as the left parenthesis
*/

// Soln: 1

Class Solution {
 public :
     bool checkValidString( string s) {
         int low = 0 , high = 0 ;
         for ( char c : s) {
             if (c == ' ( ' ) {
                 ++low; ++ high;
            } else  if (c == ' ) ' ) {
                 if (low > 0 ) --low;
                 -- high;
            } else {
                 if (low > 0 ) --low;
                 ++ high;
            }
            if (high < 0 ) 
		return  false ;
        }
        return low == 0 ;
    }
};

//------------------------------------------------------------------------------------------
// Read below for understanding
	
	
/*
O(n) solution the best you can get.

// Soln: 3 Same algo
bool checkValidString(string s) {
		auto lo = 0, hi = 0;
		for (auto c : s) {
			if (c == '(') {
				++lo;
				++hi;
			}
			else if (c == ')') {
				--lo;
				--hi;
			}
			else {
				--lo;
				++hi;
			}
			if (hi < 0) {
				return false;
			}
			if (lo < 0) {
				lo = 0;
			}
		}
		return lo == 0;
	}

Soln: 2
"balance": the number of extra open left brackets.

My extra points: We keep track of lowest no of open left bracket
possible & highest no of open left bracket possible using low 
& high after seeing a particular character.

Just think how low can increase or decrease. Also think how high can
increase or decrease.

The main breaking condition is if high ever goes below 0.
That means we can never balance it with equal no of '(' brackets.
But low can go below 0 due to the algo but that is not significant.
In that case we just again initialise it to be 0.
------------------------------------------------------------------

Soln: 2
Now, As per the solution given
When checking whether the string is valid, we only cared about the "balance":
the number of extra, open left brackets as we parsed through the string. 
For example, when checking whether '(()())' is valid, we had a balance of 
1, 2, 1, 2, 1, 0 as we parse through the string: '(' has 1 left bracket, 
'((' has 2, '(()' has 1, and so on. This means that after parsing the first 
i symbols, (which may include asterisks,) we only need to keep track of what
the balance could be.

For example, if we have string '(***)', then as we parse each symbol, the 
set of possible values for the balance is [1] for '('; [0, 1, 2] for '(*'; 
[0, 1, 2, 3] for '(**'; [0, 1, 2, 3, 4] for '(***', and [0, 1, 2, 3] for '(***)'.

Furthermore, we can prove these states always form a contiguous interval. 
Thus, we only need to know the left and right bounds of this interval. 
That is, we would keep those intermediate states described above as 
[lo, hi] = [1, 1], [0, 2], [0, 3], [0, 4], [0, 3].

Algorithm

Let lo, hi respectively be the smallest and largest possible number of 
open left brackets after processing the current character in the string.

If we encounter a left bracket (c == '('), then lo++, otherwise we could 
write a right bracket, so lo--. If we encounter what can be a left bracket 
(c != ')'), then hi++, otherwise we must write a right bracket, so hi--. 
If hi < 0, then the current prefix can't be made valid no matter what our 
choices are. Also, we can never have less than 0 open left brackets. 
At the end, we should check that we can have exactly 0 open left brackets.
*/
class Solution {
public:
    bool checkValidString(string s) {
        int l = s.length();
        if (!l)
            return true;
        int low = 0, high = 0;
        
        for(int i=0; i<l; i++)
        {
            low += s[i] == '(' ? 1: -1;
            high += s[i] != ')' ? 1: -1;
            
            if (high < 0)
                break;
            
            low = max(low, 0);
        }
        return low == 0;
    }
};
