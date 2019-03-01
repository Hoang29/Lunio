#include <bits/stdc++.h>

using namespace std;


// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {
   string m;
   if(year % 4 == 0){
       m = "12.09.";
   }
   if(year % 4 != 0){
       m = "13.09.";
   }
   return m;
}

int main()
{
int n;
cin >> n;
string m = dayOfProgrammer(n);
cout << m<<n;
return 0;
}
