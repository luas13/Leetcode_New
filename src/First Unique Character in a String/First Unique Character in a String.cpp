/*
Soln: 1 Requires an array of size 26 though constant

The solution is built around the fact that 2 integers, presentonce and 
presentmultiple is used to memorize which letter of the alphabet appears 
only once, and which one appears more then once. The result of this analysis 
occupies the space of just 2 unsigned int: a second analysis of the string 
is then done to catch the first letter in it that is already known for being 
present only once.

Final observations
Works as long as the set of chars is < number_of_bits(int): that's why I 
limit it to the english alphabet - generally a u_int is made of 32 bits on 
modern architectures.
In case you didn't get how does it work, the output is reconstructed from 
an Hexadecimal value where the result is the first bit (from right to left) 
set to "1"
It avoids to use of strlen to calculates the length of the input. 
This makes the solution a "2 * O(n) == O(n)" => VERY COOL
The space occupied is "O(1)" (constant):; 1 pointer, 2 support u_int, 
2 solution-carrying u_int, 1 hashmap of SIZE_OF_ALPHABET integers

*/
# define NORMALIZE_CHAR(C) (C-'a')

class Solution {
    unsigned int present_once = 0;
    unsigned int present_multiple = 0;
    
    // binary for 0x1 is 1
    // binary for 0x2 is 10
    // binary for 0x4 is 100
    // binary for 0x8 is 1000
    // binary for 0x10 is 10000
    const unsigned int char_to_bit[26] = {
        0x1, 0x2, 0x4, 0x8, // a, b, c, d
        0x10, 0x20, 0x40, 0x80, // ...
        0x100, 0x200, 0x400, 0x800,
        0x1000, 0x2000, 0x4000, 0x8000,
        0x10000, 0x20000, 0x40000, 0x80000, //...
        0x100000, 0x200000, 0x400000, 0x800000, // u, v, w, x
        0x1000000, 0x2000000 // y, z
    };
    
public:
    int firstUniqChar(string input) {
        int i;
        int input_length;
        for ( i = 0; ; ++i )
        {
            if ( input[i] != '\0' ) ///< Doesn't use "strlen" - It checks at every iteration if we reached the end of the string
            {
                // If the current char is not already marked as "present multiple times"
                if ( !( present_multiple & char_to_bit[ NORMALIZE_CHAR(input[i]) ] ) )
                {
                    // It it is already marked as "present once"
                    if ( present_once & char_to_bit[ NORMALIZE_CHAR(input[i]) ] )
                    {
                        // Then mark it as "present multiple times" and unmark it's "present once"
                        present_multiple |= char_to_bit[ NORMALIZE_CHAR(input[i]) ];
                        present_once &= ~char_to_bit[ NORMALIZE_CHAR(input[i]) ];
                    }
                    else
                    {
                        // Otherwise, mark it as "present once"
                        present_once |= char_to_bit[ NORMALIZE_CHAR(input[i]) ];
                    }
                }
            }
            else
            {
                // Store the input length to make next iteration easier
                input_length = i;
                break;
            }
        }

        // Look for the first char that is marked as "present only once" => that's the solution
        for ( i = 0; i < input_length; ++i )
        {
            if ( present_once & char_to_bit[ NORMALIZE_CHAR(input[i]) ] )
            {
                return i;
            }
        }
        return -1;
    }
};

// Soln 2: Requires array of size 26 but clean & fast than above
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int pos[26];
        memset(pos, -1, sizeof(pos));

        for (int i = 0; i < (int)s.length(); i++) {
            int idx = s[i] - 'a';
            if (pos[idx] == -1) // first occurrence
                pos[idx] = i;
            else if (pos[idx] >= 0) // second occurrence
                pos[idx] = -2;
        }

        int ans = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (pos[i] >= 0) {
                ans = min(ans, pos[i]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};


// Soln 3: Best Constant space O(1)
// Assumptions: All character are from a to z
// O(1) space, no array[26] required

class Solution {
    unsigned int present_once = 0;
    unsigned int present_multiple = 0;
    
public:
    int firstUniqChar(string input) {
        int i;
        int input_length;
        for ( i = 0; ; ++i )
        {
            if ( input[i] != '\0' ) 
            {
                int val = input[i] - 'a';
                // If the current char is not already marked as "present multiple times"
                if ( !( present_multiple & 1<< val ) )
                {
                    // It it is already marked as "present once"
                    if ( present_once & 1<< val )
                    {
                        // Then mark it as "present multiple times" and unmark it's "present once"
                        present_multiple |= 1<< val;
                        present_once &= ~ (1<< val);
                    }
                    else
                        present_once |= 1<< val;
                }
            }
            else
            {
                // Store the input length to make next iteration easier
                input_length = i;
                break;
            }
        }

        
        // Look for the first char that is marked as "present only once" => that's the solution
        for ( i = 0; i < input_length; ++i )
        {
            if ( present_once & 1<< (input[i] - 'a') )
                return i;
        }
        return -1;
    }
};