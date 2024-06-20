#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
};
Node* head=NULL;

void insertHead(int value){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=value;
	newNode->next=head;
	if(head!=NULL){
		head->prev=newNode;
		
	}
	head=newNode;
	

}
void insertTail(int value){
	
	if(head==NULL){		
		insertHead(value);
		return;
		
		
	}
	
	
	Node* newNode= (Node*)malloc(sizeof(Node));
	newNode->data=value;
	newNode->next=NULL;
	
	Node* temp=head;
	while(temp->next=NULL){
		temp=temp->next;
	}
	temp->next=newNode;
	newNode->prev=temp;
	
	}

void display(){
	Node* temp =head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void deleteNode(int todel){
	Node* temp =head;
	
	
}
int main(){
	Node* head =NULL;
	int value;
	int choices;
	do{
		cout<<"1-insert at tail"<<endl;
		cout<<"2- insert at head"<<endl;
		cout<<"3-display"<<endl;
		cout<<"enter choice to work"<<endl;
		cin>>choices;
		switch(choices){
			case 1:
				cout<<"enter a value to insert"<<endl;
				cin>>value;
				insertTail(value);
				break;
			case 2:
				cout<<"enter a value to insert"<<endl;
				cin>>value;
				insertHead(value);
				break;
			case 3:
				display();
				break;
			case 4:
				cout<<"exit..";
				
		}
		
	}while(choices!=4);
	return 0;
}
