#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int x = 5 , y = 10 , z = 15;
	int *p =&x , *q = &y , *r = &z;
	
	
	
	cout << " The value of x is :" << x << endl;
	cout << " The value of y is: " << y << endl; 
	cout << " The value of z is :" << z << endl;
	cout << " The value of p is: " << p << endl; 
	cout << " The value of q is :" << q << endl;
	cout << " The value of r is :" << r << endl;
	cout << " The value of *p is: " << *p << endl; 
	cout << " The value of *q is :" << *q << endl;
	cout << " The value of *r is: " << *r << endl; 
	
	int temp = z;
	
	z = x;
	x = y;
	y = temp; 
	
	cout << endl;
	cout << endl;
	
	cout << " ------------- After Swapping ------------- " << endl;
	
	cout << endl;
	cout << endl;
	
	cout << " The value of x is :" << x << endl;
	cout << " The value of y is: " << y << endl; 
	cout << " The value of z is :" << z << endl;
	cout << " The value of p is: " << p << endl; 
	cout << " The value of q is :" << q << endl;
	cout << " The value of r is :" << r << endl;
	cout << " The value of *p is: " << *p << endl; 
	cout << " The value of *q is :" << *q << endl;
	cout << " The value of *r is: " << *r << endl; 
	
	return 0;
}
