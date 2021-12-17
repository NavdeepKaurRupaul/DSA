#include<iostream>
using namespace std;
#include<unordered_map>
#include<cstring>
char* uniqueChar(char *str){
  unordered_map<char,int> map;
  for(int i=0;str[i]!='\0';i++){
    map[str[i]]++;
  }
  char* a=new char[strlen(str)];
  int j=0;
  for(int i=0;str[i]!='\0';i++){
    if(map.count(str[i])>0){
      //cout<<str[i];
      a[j++]=str[i];
      map.erase(str[i]);
    }
  }
  return a;
}
int main() {
	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}

