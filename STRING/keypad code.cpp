#include <iostream>
#include <string>
using namespace std;

int keypad(int num, string output[]){
    if(num==0 || num==1){
        output[0]="[]";
        return 1;
    }
    int so=keypad(num/10,output);
    int digit = num%10;
    if(digit==2){
        for(int i=0;i<so;i++){
            output[i+2*so]=output[i]+'a';
            output[i+so]=output[i]+'b';
            output[i]=output[i]+'c';
        }
        return so*3;
    }
    else if(digit==3){
        for(int i=0;i<so;i++){
            output[i+2*so]=output[i]+'d';
            output[i+so]=output[i]+'e';
            output[i]=output[i]+'f';
    }
        return 3*so;
    }
    else if(digit==4){
        for(int i=0;i<so;i++){
            output[i+2*so]=output[i]+'g';
            output[i+so]=output[i]+'h';
            output[i]=output[i]+'i';
    }
        return 3*so;
    }
    else if(digit==5){
        for(int i=0;i<so;i++){
            output[i+2*so]=output[i]+'j';
            output[i+so]=output[i]+'k';
            output[i]=output[i]+'l';
    }
        return 3*so;
    }
    else if(digit==6){
        for(int i=0;i<so;i++){
            output[i+2*so]=output[i]+'m';
            output[i+so]=output[i]+'n';
            output[i]=output[i]+'o';
    }
        return 3*so;
    }
    else if(digit==7){
        for(int i=0;i<so;i++){
            output[i+3*so]=output[i]+'p';
            output[i+2*so]=output[i]+'q';
            output[i+so]=output[i]+'r';
            output[i]=output[i]+'s';
    }
        return 4*so;
    }
    else if(digit==8){
        for(int i=0;i<so;i++){
            output[i+2*so]=output[i]+'t';
            output[i+so]=output[i]+'u';
            output[i]=output[i]+'v';
    }
        return 3*so;
    }
        else if(digit==9){
        for(int i=0;i<so;i++){
            output[i+3*so]=output[i]+'w';
            output[i+2*so]=output[i]+'x';
            output[i+so]=output[i]+'y';
            output[i]=output[i]+'z';
    }
        return 4*so;
    }
}
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}


