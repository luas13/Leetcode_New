/*
One Simple Solution could be Hashing. Use a hash function to 
convert long string to short string. In hashing, that may be 
collisions (2 long urls map to same short url) and we need a 
unique short url for every long url so that we can access long url back.

A Better Solution is to use the integer id stored in database 
and convert the integer to character string that is at most 6 
characters long. This problem can basically seen as a base 
conversion problem where we have a 10 digit input number and 
we want to convert it into a 6 character long string.

Below is one important observation about possible characters in URL.

A URL character can be one of the following
1) A lower case alphabet [‘a’ to ‘z’], total 26 characters
2) An upper case alphabet [‘A’ to ‘Z’], total 26 characters
3) A digit [‘0’ to ‘9’], total 10 characters

There are total 26 + 26 + 10 = 62 possible characters.

So the task is to convert a decimal number to base 62 number.

To get the original long url, we need to get url id in database. 
The id can be obtained using base 62 to decimal conversion.
*/

class Solution {
    // A string which consists of 62 possible characters
    string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // long url to short url mapper
    unordered_map<string, string> ls_url_mapper;
    // database id to long url
    unordered_map<long int, string> id_to_url;
    long int id;
public:
    Solution()
    {
        id = 0;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (ls_url_mapper.find(longUrl) != ls_url_mapper.end())
            return ls_url_mapper[longUrl];
        
        id++;
        int count = id;
        string result = "";
        
        // Convert given integer id to a base 62 number
        while(count > 0)
        {
            // use above dict string to store actual character
            // in short url
            result = dict[count%62] + result;
            count = count/62;
        }
        
        // We want a minimum length of 6 for short url
        while (result.length() < 6)
        {
            result = "0" + result;
        }
        
        id_to_url[id] = longUrl;
        ls_url_mapper[longUrl] = result;
        
        return result;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        long int id = 0;
        
        for(int i=0; i<shortUrl.length(); i++)
        {
            // A simple base conversion logic
            // dict.find(shortUrl[i]) gives the index in dict
            id = 62*id + int(dict.find(shortUrl[i]));
        }
        
        if (id_to_url.find(id) != id_to_url.end()) return id_to_url[id];
        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));