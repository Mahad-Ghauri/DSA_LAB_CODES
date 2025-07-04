#include "NODE.H"
#include "LIST.H"

int main()
{
    List firstList;
    int oddArray[] = {1, 3, 5, 7 ,9  ,7 , 11 }; 

    
    for (int i = 0; i < 7; i++)
    {
        firstList.AddNode(oddArray[i]);
    }
    firstList.Display();
    
    List *circularList = firstList.CircularList();

    cout << "\n Adding a new element in the circular linked list: " << endl;
    circularList->Add_NewNode(13);
    circularList->Circular_Display();
    
    cout << "\n";
    int position = 3, value = 5;

    cout << "\n";
    cout << "\n Size of the list is " << circularList->getSize() << endl;



    cout << "\n Updating Node : " << endl;
    bool found = circularList->Check_Node(value);
    if (found)
    {
        cout << " The value " << value << " is present  in the list " << endl;
    }

    cout << "\n";
    cout << "\n Check circular list : " << endl;
    bool choice = circularList->Check_Circular_List();
    if (choice)
    {
        cout << " The list is not circular list "  << endl;
    }
    else
    {
        cout << " The list is circular " << endl;
    }


    cout << "\n";
    cout << "\n Moving the elements to the end of the list " << endl;
    List* movingList = circularList->Move_End();
    movingList->Circular_Display();


}