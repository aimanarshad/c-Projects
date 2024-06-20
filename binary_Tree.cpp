#include <iostream>
#include <cstdlib>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
Node* root=NULL;
Node* insert(Node* root,int value){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=value;
	newNode->left=NULL;
	newNode->right=NULL;
	
	if(root==NULL){
		root=newNode;
		
	}
	if(value<root->data){
		root->left=insert(root->left,value);
		
	}
	if(value>root->data){
		root->right=insert(root->right,value);
	
	}
	return root;
}
Node* search(Node* root,int tosearch){
	if(root->data==tosearch){
		return root;
	}
	
	if(root->data<tosearch){
		return search(root->left,tosearch);
	}

	return search(root->right,tosearch);
	
}
//Node* deleteNode(Node* root,int todel){
//	if(root==NULL){
//		return root;
//	}
//	if(todel<root->data){
//		root->left=deleteNode(root->left,todel);
//			
//}
//	if(todel>root->data){
//		root->right=deleteNode(root->right,todel);
//	}
//	else{
//		if(root->left==NULL){
//			Node* temp = root->right;
//			free(root);
//			return temp;
//		}
//		if(root->right==NULL){
//			Node* temp= root->left;
//			free(root);
//			return temp;
//		}
//		
//		else{
//			Node* temp =inorder(root->right);
//			root->right=temp->data;
//			root->right=deleteNode(root->right,temp->todel)
//		}
//		
//	}
//	return root;
//}
void preorder(Node* root){
	if(root!=NULL){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(Node* root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
		
	}
	
}
void postorder(Node* root){
		if(root!=NULL){
			postorder(root->left);
			postorder(root->right);
			cout<<root->data<<" ";
		
	}
}
int main(){
	Node* root=NULL;
	int choice;
	int value;
	int tosearch;
	
	do{
		
		cout<<"1-insert"<<endl;
		cout<<"2-preorder"<<endl;
		cout<<"3-inorder"<<endl;
		cout<<"4-postorder"<<endl;
		cout<<"5-search"<<endl;
		cout<<"6-exit"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"enter value"<<endl;
				cin>>value;
				root=insert(root,value);
				break;
			case 2:
				cout<<"preorder"<<endl;
				preorder(root);
				break;
			case 3:
				cout<<"inorder"<<endl;
				inorder(root);
				break;
			case 4:
				cout<<"postorder"<<endl;
				postorder(root);
				break;
			case 5:
				cout<<"enter value to search"<<endl;
				cin>>tosearch;
				if(search(root,tosearch)!=NULL){
					cout<<"value found"<<endl;
				}
				else{
					cout<<"value not found";
				}
				break;
			
			case 6:
				cout<<"exit"<<endl;
				
		}
	}while(choice!=6);
	return 0 ;
}
