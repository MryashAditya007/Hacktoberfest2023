#include <iostream>
# define Z 50

using namespace std;

void displayArr(int arr[], int n){
   for( int i = 0; i < n; i++ ){
      cout << arr[ i ] << ", ";
   }
   cout << endl;
}

void pickSubarray( int A[], int n, int sub[], int &m, int i, int j ) {
   int ind = 0;
   for( int k = i; k < j; k++, ind++ ) { 
      sub[ ind ] = A[ k ]; 
      m += 1;
   } 
}

int main() {
   int A[ Z ] = {57, 10, 14, 19, 86, 52, 32, 14, 76, 65, 32, 14};
   int n = 12;
   
   int sub[ Z ];
   int m = 0;
   
   cout << "Given Array: ";
   displayArr( A, n );
   
   cout << "Sub array from index 3 to 9: ";
   pickSubarray( A, n, sub, m, 3, 9); 
   displayArr( sub, m );
}
