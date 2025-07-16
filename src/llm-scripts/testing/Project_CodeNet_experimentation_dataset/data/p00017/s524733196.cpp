#include <iostream>
#include <string>

using namespace std;

bool isPlain(string secret){
    bool find_the,find_that,find_this;
    
    find_the = (secret.find("the") != string::npos);
    find_that = (secret.find("that") != string::npos);
    find_this = (secret.find("this") != string::npos);

    return (find_the || find_that || find_this);
}

string decipher(string secret){
    int gap = 1;
    string plain;
    bool check;
    
    //"the", "that", "this"
    check = isPlain(secret);
    
    if(check){
        plain = secret;
    }
    else {
        while(gap<=26){
            string::iterator it = secret.begin();
            for (; it != secret.end(); it += 1){
                if('a'<=*it & *it <='z')
                    *it = (*it!='z') ? *it + 1 : 'a';
                //cout << *it;
            }
            //cout << endl;
            gap++;
            if(isPlain(secret)) break;
        }
    }
    return secret;
}


int main (int argc, char const* argv[]){
    string secret, plain;
    
    
    //暗号文の取得
    getline(cin,secret);
    while(!secret.empty()){
        
        //暗号解読
        plain = decipher(secret);
        //平文の出力
        cout << plain << endl;
        
        getline(cin,secret);
    }
    
    
    return 0;
}