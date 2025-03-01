#include <bits/stdc++.h>
using namespace std;


struct node{
	struct node * left ;
	struct node * right ;
	int data ;
	node(int val){
		data = val;
		left = right= nullptr;
	}

};

void preorder(struct node * root){
	if(root == nullptr){
		return ;
	}
	cout<<root->data<<endl;
	preorder(root->left);
	preorder(root->right);

}

void postorder(struct node * root){
	if(root == nullptr){
		return ;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<endl;
}



 void inorder(struct node * root){
if(root== nullptr){
	return ; 
 }
 inorder(root->left);
 cout<<root->data<<" ";
 inorder(root->right);
}





int main(){
 

          
    
      node* root = new node(1);
    
        // Level 1
        root->left = new node(2);
        root->right = new node(3);
    
        // Level 2
        root->left->left = new node(4);
        root->left->right = new node(5);
        root->right->left = new node(6);
        root->right->right = new node(7);
    
        // Level 3
        root->left->left->left = new node(8);
        root->left->left->right = new node(9);
        root->left->right->left = new node(10);
        root->left->right->right = new node(11);
        root->right->left->left = new node(12);
        root->right->left->right = new node(13);
        root->right->right->left = new node(14);
        root->right->right->right = new node(15);
    
}    