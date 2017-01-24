/*

#include <queue>
#include <iostream>


using namespace std;
int main()
{
  std::queue<int> arr1;

  for (int i = 0; i < 5; ++i) arr1.push(i);

  arr1.push(5);
  //arr1.pop();
  arr1.push(6);
  arr1.pop();

  //cout << arr1<< endl;

  return 0;
}

*/

/*
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define max 10
using namespace std;
class Stack_Op
{
    private:
        int arr[max];
        int top;
        public:
            Stack_Op()
            {
                top=-1;
            }
            int push()
            {
                if(top==max-1)
            {
            cout<<“Overflow”<< endl;
            return 0;
            }
            int value;
            cout <<“Enter an integer to push into stack\n” ;
            cin >> value;
            top++;
            arr[top]=value;
            //cout<<val” is inserted”;endl;
            return 1;
            }

            int pop()
            {
                //check underflow
                if(top==-1)
                    {
                        cout<<“Underflow”<<endl;
                        cout<<“Press any key to continue”;
                        getch();
                        return NULL;
                    }
                    int val=arr[top];
                    arr[top]=NULL;
                    top–;
                    cout<<“One is element is poped”;
                    return val;
            }
            void display()
            {
                //check underflow
                if(top==-1)
                {
                cout<<“Underflow”<<endl;
                cout<<“Press any key to continue”;
                getch();
                }
                else{
                int i;
                for(i=top;i>=0;i–)
                {
                cout<<“Stack value at “<<i<<” is “<<arr[i]<<endl;
                }
                getch();
                }
            }
};

void main()
{
    Stack_Op obj1;
    int opt;
    while(1)
        {
            clrscr();
            cout<<“1. Push Operation\n2. POP Operation\n3. Display stack\n4.Exit\n”;
            cin>>opt;
            switch(opt)
            {
                case 1: int flag=obj1.push();
                if(flag)
                cout<<“One element is pushed\n”;
                cout<<“press any key to continue\n”;
                getch();
                break;
                case 2: int val2;
                val2=obj1.pop();
                cout<<“press any key to continue\n”;
                getch();
                break;
                case 3: clrscr();
                obj1.display();
                break;
                case 4: exit(0);
                default: cout<<“Press within the range 1-4\n”;
                cout<<“Press any key to continue”;
                getch();
                break;
            }
        }
}
*/


//Adapted from CS Data Structures Lab 4
// 9/30/2015

#include <iostream>
using namespace std;

struct SNode{

	int Number;
	SNode *Next;

};

class Stack{

public:
	//Constructors
	Stack();
	Stack(const Stack & stack);
	~Stack();


	//Methods
	bool IsFull();
	bool IsEmpty();
	void Push(int Number);
	void Pop(int &Number);
	void Top(int &Number);
	int GetLength();
	void Print();


private:
	SNode *Head;
	int Length;

};

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
Stack::Stack()
{
	Head = NULL;
	Length = 0;
}

//----------------------------------------------
// Constructor function.
//----------------------------------------------
Stack::Stack(const Stack & stack)
{
	// Create first node
	SNode *copy = new SNode();
	Head = copy;

	// Walk list to copy nodes
	SNode *ptr = stack.Head;
	while (ptr != NULL)
	{
		copy->Next = new SNode();
		copy = copy->Next;
		copy->Number = ptr->Number;
		copy->Next = NULL;
		ptr = ptr->Next;
	}

	// Tidy first node
	copy = Head;
	Head = copy->Next;
	delete copy;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
Stack::~Stack()
{
	// Walk stack deleting data
	while (Head != NULL)
	{
		SNode *Temp = Head;
		Head = Head->Next;
		delete Temp;
	}

	// Reset head
	Head = NULL;
	Length = 0;
}

//-----------------------------------------------------------
// Check to see if stack is full.
//-----------------------------------------------------------
bool Stack::IsFull()
{
	return (false);
}

//-----------------------------------------------------------
// Check to see if stack is empty.
//-----------------------------------------------------------
bool Stack::IsEmpty()
{
	return (Length == 0);
}

//-----------------------------------------------------------
// Push data into the stack.
//-----------------------------------------------------------
void Stack::Push(int Number)
{
	// Check for full stack
	if (IsFull())
		return;

	// Allocate space for data
	SNode *Temp = new SNode;
	if (Temp == NULL)
		return;

	// Insert data at head of list
	Temp->Number = Number;
	Temp->Next = Head;
	Head = Temp;
	Length++;

	// cout << "Push " << Number << endl;
}

//-----------------------------------------------------------
// Pop data from the stack.
//-----------------------------------------------------------
void Stack::Pop(int &Number)
{
	// Check for empty stack
	if (IsEmpty())
		return;

	// Extract information from node
	Number = Head->Number;

	// Pop item from linked list
	SNode *Temp = Head;
	Head = Head->Next;
	delete Temp;
	Length--;

	// cout << "Pop " << Number << endl;
}

//-----------------------------------------------------------
// Return data from top of stack.
//-----------------------------------------------------------
void Stack::Top(int &Number)
{
	// Check for empty stack
	if (IsEmpty())
		return;

	// Return information from node
	Number = Head->Number;

	// cout << "Top " << Number << endl;
}

//-----------------------------------------------------------
// Return the number of elements in stack.
//-----------------------------------------------------------
int Stack::GetLength()
{
	return Length;
}

//-----------------------------------------------------------
// Print all records in the stack.
//-----------------------------------------------------------
void Stack::Print()
{
	// Walk the stack printing data
	cout << "size = " << Length << ", data = ";
	SNode *Temp = Head;
	while (Temp != NULL)
	{
		cout << Temp->Number << " ";
		Temp = Temp->Next;
	}
	cout << endl;
}

//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
int main()
{
	Stack s;
	s.Push(10);
	s.Push(9);
	s.Push(5);
	s.Print();
	s.Push(1);
	s.Push(4);
	s.Push(2);
	s.Print();

	int num;
	s.Pop(num);
	s.Print();
	s.Pop(num);
	s.Print();
	s.Pop(num);
	s.Print();
	s.Pop(num);
	s.Print();
	s.Pop(num);
	s.Print();
	s.Pop(num);
	s.Print();
	return 0;
}

