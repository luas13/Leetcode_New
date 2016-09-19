class Solution {
public:
    int numDecodings(string s) {
    
    //int l=s.length();
    if(s.length()==0)
        return 0;
        
    //char str[] = new char [s.length()];
    char *str = new char[10000];
    strcpy (str, s.c_str());
    
    //int decode[]= new int[str.length()];
    int *decode= new int[10000];
    
    int l=strlen(str);
    
    if( str[l-1] - '0' == 0)
            decode[l-1]=0;
        else
            decode[l-1]=1;
    
    if(l >= 2)
    {
        if( str[l-2] - '0' > 2)
        {
            if( str[l-1] - '0' == 0 )
                decode[l-2]=0;
            else
                decode[l-2]=1;
        }
            
        else if( str[l-2] - '0' == 2 ) 
        {
            if( str[l-1] - '0' > 6 ) 
                decode[l-2]=1;
            else if(str[l-1] - '0' == 0)
                decode[l-2]=1;
            else
                decode[l-2]=2;
        }
        
        else if( str[l-2] - '0' == 1 ) 
        {
            if( str[l-1] - '0' == 0 )
                decode[l-2]=1;
            else
                decode[l-2]=2;
        }
        
        else
            decode[l-2]=0;
    }
    
    if(l > 2)
    {
        for(int j=l-3; j>=0 ; j--)
        {
            if(str[j] - '0'== 0)
                decode[j]=0;
            else
            {
                int ways=0;
                
                if(str[j] - '0'< 2 || str[j] - '0' == 2 && str[j+1] - '0' <= 6)
                    ways=1;
            
                decode[j]=decode[j+1] + ways * decode[j+2];
            }
        }
    }
    delete(str);
    
    return decode[0];
    
    delete(decode);
    }
};
