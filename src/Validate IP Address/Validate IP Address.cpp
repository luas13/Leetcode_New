class Solution {
public:
    string val4(string IP)
    {
        stringstream str(IP);
        int l = IP.length();
        if (IP[l-1] == '.')
            return "Neither";
        string token;
        int dot= 0;
        while(getline(str, token, '.'))
        {
            dot++;
            int len = token.length();
            
            for (int i=0; i<len; i++)
                if (!isdigit(token[i]))
                    return "Neither";
                    
            if (token.length() == 0 || (dot-1) > 3 || (len>1 && token[0] == '0') || len > 3 || stoi(token) < 0 || stoi(token) > 255)
                return "Neither";
        }
        if (dot-1 != 3)
            return "Neither";
        return "IPv4";
    }
    
    bool ishexchar(char c)
    {
        if ( (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
            return true;
        else
            return false;
    }
    string val6(string IP)
    {
        stringstream str(IP);
        int l = IP.length();
        if (IP[l-1] == ':')
            return "Neither";
        string token;
        int colon= 0;
        while(getline(str, token, ':'))
        {
            colon++;
            int len = token.length();
            
            for (int i=0; i<len; i++)
                if (!isalnum(token[i]) || (isalpha(token[i]) && !ishexchar(token[i])) )
                    return "Neither";
                    
            if (token.length() == 0 || (colon-1) > 7 || len>4)
                return "Neither";
        }
        if (colon-1 != 7)
            return "Neither";
        return "IPv6";
    }
    
    string validIPAddress(string IP) {
        int l = IP.length();
        if (l == 0)
            return "Neither";
        int i= 0;
        while(i<l)
        {
            if (IP[i] == '.')
                return val4(IP);
            
            if (IP[i] == ':')
                return val6(IP);

            i++;
        }
        return "Neither";
    }
};