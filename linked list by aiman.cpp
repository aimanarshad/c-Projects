#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
	int data;
	Node* next;
};
Node* head = NULL;

void  insert(int value){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data= value;
	newNode->next=NULL;
	
	if(head==NULL){
		head=newNode;
		return;
	}
	else{
		Node* temp = head;
		
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
		cout<<"inserted value is"<<value<<endl;
	}
}
void insertATHead(int value){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=value;
	newNode->next=head;
	head=newNode;
	cout<<"inserted value at head"<<endl;

}
bool search(int key){
	Node* temp = head;
	while(temp!=NULL){
		if(temp->data==key){
			cout<<"value found"<<endl;
			return true;
		
		}
		temp =temp->next;
	
	}
	cout<<"value not found"<<endl;
	return false;
	
}

void display(){
	Node* temp =head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	Node* head = NULL;
	int value;
	int choice;
	int key;
	do{
		cout<<"1-insert"<<endl;
		cout<<"2-insertAtHead"<<endl;
		cout<<"3-display"<<endl;
		cout<<"4-search"<<endl;
	
		cout<<"5-exit"<<endl;
		
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"enter value to insert"<<endl;
				cin>>value;
				insert(value);
				break;
			case 2:
				cout<<"insert a value at head";
				cin>>value;
				insertATHead(value);
				break;
			case 3:
				display();
				break;
			case 4:
				cout<<"enter a value to search";
				cin>>key;
				search(key);
				cout<<"value found";
				break;
		
			case 5:
				cout<<"exit"<<endl;
				
	}
	}while(choice!=5);
	
	return 0;
}

