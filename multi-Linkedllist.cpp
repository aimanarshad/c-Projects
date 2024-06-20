#include <iostream>
#include <cstdlib>
using namespace std;

// Node structure for the multi-linked list
struct Node {
    int data;
    Node* next; // Pointer to the next node in the main linked list
    Node* down; // Pointer to the down node in the sub-list

    
};
Node* head=NULL;


    // Function to insert a new element into the multi-linked list
void insert(Node* &head,int value) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data=value;
        newNode->next=NULL;
        newNode->down=NULL;
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
 // Function to find a node with a given value in the main linked list
Node* findNode(int value) {
    Node* temp = head;
    while (temp != NULL) {
            if (temp->data == value) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    // Function to insert a new element into the sub-list of a node
void insertIntoSubList(int parentValue, int value) {
        Node* parent = findNode(parentValue);
        if (parent == NULL) {
            cout << "Parent node not found." << endl;
            return;
        }

        Node* newNode = (Node*)malloc(sizeof(Node));
        if (parent->down == NULL) {
            parent->down = newNode;
        } else {
            Node* temp = parent->down;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

   

    // Function to display the multi-linked list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            Node* downTemp = temp->down;
            while (downTemp != NULL) {
                cout << downTemp->data << " -> ";
                downTemp = downTemp->next;
            }
            temp = temp->next;
            cout << "NULL" << endl;
        }
    }

int main(){

Node* head = NULL;
	int value;
	int choice;
	int parentValue;
	do{
		cout<<"1-insert"<<endl;
		cout<<"2-insertIntoSubList"<<endl;
		cout<<"3-display"<<endl;
	
	
		cout<<"4-exit"<<endl;
		
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"enter value to insert"<<endl;
				cin>>value;
				insert(head,value);
				break;
			case 2:
				cout<<"insert a value at head";
				cin>>value;
				insertIntoSubList(parentValue,value);
				break;
			case 3:
				display();
				break;
		
		
			case 4:
				cout<<"exit"<<endl;
				
	}
	}while(choice!=4);
	
	return 0;
}


