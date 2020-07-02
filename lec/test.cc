#include <iostream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]) {
   for (int j = 0; j < 10; j++) {
   int i = rand(); 
   sleep(i%10 * 0.1);
   cout << i%10 << endl;
   }
   return 0;
}

