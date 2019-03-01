#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream myfile;
  if (myfile.is_open()) {     // Kiểm tra việc mở tệp có thành công?
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}
