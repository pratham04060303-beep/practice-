

#include<iostream>


template<typename T>

class node {

public :
	T data;
	node<T>* lnode = NULL;
	node<T>* rnode = NULL;
	size_t height;

public :
	node() {
	
	this->data = T();
	this->lnode = NULL;
	this->rnode = NULL;
	this->height = 0;
	
	}

};

class avl {
public :
size_t size_a = 0;
//size_t n_count = 0;
long height_a = -1 ;
node<T>* root = NULL;

public :
avl() {
this->size_a = 0;
//this->n_count = 0;
this->height_a = 0;
this->root = NULL;
}

// checkbalance 

// ll
// rr
// lr
// rl
//
// ll 

void balance(node<T>* T )

void push(T x) {
node<T>* node = new node();
node->rnode = NULL;
node->lnode = NULL;
node->data = x;
if(size_a == 0 ) {
this->root = node;
return;

}
node<T>* temp = this->root;
node<T>* temp1 = NULL;
node<T>* temp2 = NULL;
while(temp != NULL){
temp2 = temp1;
temp1 = temp;
if(x < temp->data ) {
temp = temp->lnode;
}else if(x > temp->data ) {
temp = temp->rnode;
}else{
delete node;
return;
}
temp1->height++;
}

if(temp1->data < x) {
temp1->rnode = node;
}else{
temp1->lnode = node;
}



}





};
