#include <iostream>
#include <cstdlib>
using namespace std;

struct Stack{
	int data;
	Stack* next;
};
Stack* top=NULL;

void push(int value){
	Stack* newStack=(Stack*)malloc(sizeof(Stack));
		if(newStack==NULL){
		cout<<"stack overflow";
		exit(1);
		
	}
	newStack->data=value;
	newStack->next=NULL;
	
	newStack->next=top;

	top=newStack;
	
}

int pop(){
	Stack* temp = top;
	int val=temp->data;
	top=temp;
	top=top->next;
	free(temp);
	temp=NULL;
	return val;
	
}
void display(){
	Stack* temp=top;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	int choices;
	int value;
	do{
	
		cout<<"1-push"<<endl;
		cout<<"2-push"<<endl;
		cout<<"3-display"<<endl;
		cout<<"4-exit"<<endl;
		cout<<"enter your choices"<<endl;
		cin>>choices;
		switch(choices){
			case 1:
				cout<<"enter value to push on stack"<<endl;
				cin>>value;
				push(value);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				cout<<"exit..."<<endl;
		}
	}while(choices!=0);
	return 0;
}
