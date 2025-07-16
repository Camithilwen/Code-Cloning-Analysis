
#include <iostream>
#include <vector>
#include <cstdio>

//2^32/26 = 165191049.846153846153846 = 165191050
#define MAGIC 0x9D89D8A

char shift (char c, int amount)
{
    long n;
    long q ;
    long r;
    
    n = (long) c - 'a' +  amount;
    q = n * MAGIC;
    q >>= 32;
    r = n - q * 26;
    
    return (char) 'a' + r;
}

void shiftString (char* s, int amount)
{
    int i = 0;
    while (s[i]) {
        
        if (s[i] == ' ') {}
        else if (s[i] == '.') {}
        else { s[i] = shift(s[i], amount); }
        i++;
    }
    
}

int main(int argc, const char * argv[]) {

   
    char buffer[256];
    std::string line;
    std::vector<std::string> listString;
    int result = 0;
    std::size_t found;
    
    
    while (std::getline(std::cin, line))
    {
        //sprintf(buffer, "%s", line.c_str());
        listString.push_back(line);
    }
    
    
    std::vector<std::string>::iterator it;
    
    it = listString.begin();
    
    do {
        result = 0;
        sprintf(buffer, "%s", (*it).c_str());
        
        while (!result)
        {
            
            shiftString(buffer, -1);
            line = buffer;
            
            result = 0;
            
            found = line.find("the");
            result += found!=std::string::npos;
            
            found = line.find("this");
            result += found!=std::string::npos;

            found = line.find("that");
            result += found!=std::string::npos;

        }
        
        printf("%s\n", buffer);
        
    } while (++it < listString.end());

    return 0;
}