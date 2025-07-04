#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int x = 2 , y = 8;
	int *p =&x , *q = &y;
	int **num1 = & p , **num2 = &q;
	
	
	cout << " The address of x is :" << p << " and the value of  x is: " << x << endl; 
	
	cout << endl;
	
	cout << " The value of p is :" << p << " and the value of  *p is: " << *p << endl; 
	
	cout << endl;
	
	cout << " The address of y is :" << q << " and the value of  y is: " << y << endl; 
	
	cout << endl;

	cout << " The value of q is :" << q << " and the value of  *q is: " << *q << endl; 
	
	cout << endl;
	
	cout << " The address of p is :" << num1 << " and the value of  q is: " << num2 << endl; 
	
	
	return 0;
}
