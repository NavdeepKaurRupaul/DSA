#include <iostream>
using namespace std;
#include<cstring>
bool checkAB(char input[]) {
if(strlen(input)==0){
    return true;
}  
    if(input[0]!='a'){
        return false;
    }
    if(input[1]==NULL){
        return true;
    }
    if(input[1]=='a'){
        return checkAB(input+1);
    }
    if(input[2]==NULL||input[1]!='b'||input[2]!='b'){
       return false; 
    }
    return checkAB(input+3);
}
int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}

