#include <iostream>
using namespace std;
int k=0,i=0,j=0,t=0;
char output[100];
void removeX(char input[]) {
if(t==0)
{
  if(input[i]!='\0')
  {
    if(input[i]!='x')
    {
      output[j]=input[i];
      j++;i++;
      removeX(input);
    }
    else
    {
      i++;
      removeX(input);
    }
  }
  else if(input[i]=='\0')
  {
    output[j]=NULL;
    t=1;
  }
}
  if(t==1)
  {
    if(k<=j)
    {
      input[k]=output[k];
      k++;
      removeX(input);
    }
  }
}
int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}

