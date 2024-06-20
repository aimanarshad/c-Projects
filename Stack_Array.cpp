#include <iostream>

using namespace std;

struct Stack{
	int top;
	int arr[5];
Stack(){
	top=-1;
}
bool isEmpty(){
	return(top==-1);
}
bool isFull(){
	return(top==4);
		
}
void push(int value){

	if(isFull()){
		cout<<"Stack overflow"<<endl;
		return ;
	}
	else{
		arr[top]=value;
		top++;
		cout << "Pushed " << value << " into the stack.\n";
	}
}
 void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow: Cannot pop, the stack is empty.\n";
            return;
        }
        cout << "Popped " << arr[top--] << " from the stack.\n";
    }
void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
	
int main(){
	Stack s1;
	int value;
	int option;
	do{
		cout << "\nChoose an operation:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display Stack\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
		cin>>option;
		switch(option){
			case 1:
				cout<<"enter a value to push"<<endl;
				cin>>value;
				s1.push(value);
				break;
			case 2:
				cout<<"stack after poping";
				s1.pop();
				break;
			case 3:
				cout<<"stack"<<endl;
				s1.display();
				break;
			case '4':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
	
	}
	
	}while(option!=4);
	
	return 0;
}
