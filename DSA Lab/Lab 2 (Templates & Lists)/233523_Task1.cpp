#include<iostream>
using namespace std;
template <typename type>

class Box
{
	type length;
    type width;
public:
    
    Box()
	{
		length = 0;
		width = 0;
	}

    void setLength(type val) 
	{
        length = val;
    }

    void setWidth(type val) 
	{
        width = val;
    }
    
    type getLength()
	{
        return length;
    }
    
    type getWidth()
	{
        return width;
    }
    
    bool checkEqualLength(Box<type>& check)
	{
		if(length == check.length)
		{
			return true;
		}
		else
		{
			return false;
		}
	} 
	 
	bool checkEqualWidth(Box<type>& check)
	{
		if(width == check.width)
		{
			return true;
		}
		else
		{
			return false;
		}
	} 
	 
	
};

int main()
{
	Box<int> intval;
	intval.setLength(8);
	intval.setWidth(8);
	cout<<"The lenght of box is "<<intval.getLength()<<endl;
	cout<<"The width of box is "<<intval.getWidth()<<endl;
	
	 cout << "\n\n";
    
	
	Box<float> floatval;
	floatval.setLength(8.5);
	floatval.setWidth(8.5);
	cout<<"The lenght of box is "<<floatval.getLength()<<endl;
	cout<<"The width of box is "<<floatval.getWidth()<<endl;
    
    
    
    cout << "\n\n";
    
    Box<float> floatval2;
	floatval2.setLength(9.5);
	floatval2.setWidth(8.5);
	
	cout<<"The lenght of box is "<<floatval.getLength()<<endl;
	cout<<"The width of box is "<<floatval.getWidth()<<endl;
	
	 cout << "\n\n";
    
	
	cout<<"The lenght values are equal or not :"<<(floatval.checkEqualLength(floatval2));
	cout<<"\n1 represents equality and 0 represents unequality "<<endl;
	
	 cout << "\n\n";
    
	
	cout<<"The lenght values are equal or not "<<(floatval.checkEqualWidth(floatval2));
	cout<<"\n1 represents equality and 0 represents unequality :"<<endl;
}
