#include "NODE.H"
#include "LIST.H"


int main()
{
    List firstList;
    int oddArray[] = {1, 3, 5, 7, 9};


    for (int i = 0; i < 5; i++)
    {
        firstList.AddNode(oddArray[i]);
    }
    firstList.Display();
    
    List *circularList = firstList.CircularList();


    cout << "\n Adding a new element in the circular linked list: " << endl;
    circularList->Add_NewNode(11);
    circularList->Circular_Display();
    
    cout << "\n";
    int position = 3 , oldValue = 9, newValue = 5;


    cout << "\n Deleting Node a specific node in the list:" << endl;
    circularList->Delete_Specific_Node(position);
    circularList->Circular_Display();
    
    cout << "\n";


    cout << "\n Swap Nodes : " << endl;
    circularList->Swap_Nodes(position);
    circularList->Circular_Display();


    cout << "\n Updating Node : " << endl;
    List *updatedList = circularList->Update_Node(oldValue , newValue);
    updatedList->Circular_Display();


}
