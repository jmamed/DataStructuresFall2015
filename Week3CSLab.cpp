#include <iostream>
#include <stdlib.h>
using namespace std;

class Node{
	friend class List;

	private:
		int num;
		Node *next;

	public:
		Node(){}

		Node(int& d)
		{
			num = d; next = NULL;
		}
}*head;

class List
{
private:
	Node *root;
public:
	List(){
		root = new Node();
		root = NULL;
	}

	~List(){
		delete root;
	}

	void Print();
	void Append(int num);
	void Delete(int num);

};

//Print contents of the list
void List::Print () {

		Node *temp_node = root;
		while (temp_node != NULL)
		{
			cout << temp_node->num << " ---> ";
			temp_node = temp_node->next;
		}
		if (temp_node== NULL)
			cout << "NULL" << endl;

}

//Append a node to he linked list
void List::Append(int data) {

		Node *new_data = new Node(data);
		if (root == NULL)
		{
			root = new_data;
			return;
		}
		else
		{
			Node *temp_node = root;
			while (temp_node->next != NULL)
			{
				temp_node = temp_node->next;
			}
			temp_node->next = new_data;
		}

}

//Delete a node from the list
void List::Delete(int data) {

	Node *temp_node = root;
	Node *prev = NULL;

    if (temp_node->next == NULL){
            cout << "EMPTY" << endl;
 }
	while (temp_node != NULL)
	{
		if (temp_node->num == data)
		{
			if (temp_node == head)
			{
				head = temp_node->next;
				free(temp_node);
				return;
			}
			else
			{
				prev->next = temp_node->next;
				free(temp_node);
				return;
			}
		}
		else
		{
			prev = temp_node;
			temp_node = temp_node->next;

		}
	}
}

//Test the program
int main() {

	//new list
	List list;

	//append nodes to the list
	list.Append(100);
	list.Print();
	list.Append(200);
	list.Print();
	list.Append(300);
	list.Print();
	list.Append(400);
	list.Print();
	list.Append(500);
	list.Print();
    //delete nodes from the list
	list.Delete(400);
	list.Print();
	list.Delete(300);
	list.Print();
	list.Delete(200);
	list.Print();
	list.Delete(500);
	list.Print();
	list.Delete(100);


	system("pause");
}
