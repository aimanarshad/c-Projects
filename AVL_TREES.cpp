#include <iostream>
#include <cstdlib>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	int height;
};
Node* root=NULL;
int getHeight(Node* n){
	if(n==NULL){
		return 0;
	}
	return n->height;
}
int balanceFactor(Node* n){
	return getHeight(n->left)-getHeight(n->right);
}
int updateHeight(Node* n){
	return 1+max(getHeight(n->left),getHeight(n->right));
}
Node* leftRotate(Node* x){
	Node* y=x->right;
	Node* z=y->left;
	y->left=x;
	x->right=z;
	updateHeight(y);
	updateHeight(x);
	
	return y;
}
Node* rightRotate(Node* y){
	Node* x=y->left;
	Node* z= x->right;
	x->right=y;
	y->left=z;
	updateHeight(y);
	updateHeight(x);
	return x;
}
Node*  insert(Node* root,int value){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=value;
	newNode->height=1;
	newNode->left=NULL;
	newNode->right=NULL;
	
	if(root==NULL){
		root= newNode;
	}
	if(value<root->data){
		root->left=insert(root->left,value);
	}
	if(value>root->data){
		root->right=insert(root->right,value);
	}
	
	return root;
	updateHeight(root);
	int balance =balanceFactor(root);
	
	if(balance>1 && value<root->left->data)
		return rightRotate(root);
	if(balance<-1 && value>root->right->data)
		return leftRotate(root);
	if(balance>1 && value>root->left->data)
		root->left=leftRotate(root->left);
		return rightRotate(root);
	if(balance<-1 && value<root->right->data)
		root->right=rightRotate(root->right);
		return leftRotate(root);
	return root;
}



void postorder(Node* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
		
	}
}
int main(){
	int value;
	int choice;
	do{
		
		cout<<"1-insert"<<endl;
		cout<<"2-display"<<endl;
		cout<<"exit"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"enter value to insert"<<endl;
				cin>>value;
				insert(root,value);
				break;
			case 2:
				postorder(root);
				break;
			case 3:
				cout<<"exit"<<endl;
				break;
			
		}	
		}while(choice!=3);
	return 0;
}
