

#include<iostream>


template<typename T>

class node {

public :
	T data;
	node<T>* lnode = NULL;
	node<T>* rnode = NULL;
	int height;

public :
	node() {
	
	this->data = T();
	this->lnode = NULL;
	this->rnode = NULL;
	this->height = 1;
	
	}

};

template<typename T>
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

long height(node<T>* n ) {
	if(n != NULL ){
		return n->height;
	}
	return -1;
}

int updateheight(node<T>* temp) {
if(temp == NULL ) {
return -1;
}
//std::cout << temp->data << " "<< temp->height << std::endl;

temp->height = 1 + std::max(updateheight(temp->lnode),updateheight(temp->rnode));
//std::cout << temp->data << " "<< temp->height << std::endl;
// std::cout << balance(temp) << std::endl;
return temp->height;
}
int balance(node<T>* temp) {
int height_balance = height(temp->lnode) - height(temp->rnode);
return height_balance;
}


void balance_avl(node<T>* n ) {
updateheight(this->root);
if(n == NULL  ) {
	return;
}

if(n == this->root) {
	return;
}
node<T>* temp = this->root;
node<T>* temp1 = this->root;
node<T>* temp2 = this->root;
node<T>* temp3 = this->root;

while(temp != NULL && temp->data != n->data ) {
	temp3 = temp2;
	temp2 = temp1;
	temp1 = temp;
	if(temp->data < n->data ) {
		temp = temp->rnode;
	}else{
		temp = temp->lnode;
	}
} 
//std::cout << "data " <<   temp->data  << std::endl; 
/*if(temp1 == this->root) {
	if(balance(this->root) > 1 ) {
		this->root = temp1->lnode;
		temp1->lnode->rnode = temp1;
	}else if(balance(this->root) < -1){
		this->root = temp1->rnode;
		temp1->lnode->rnode = temp1;
	}
	return;
}*/
if(temp2 == this->root ) {
	if(balance(this->root) > 1 ) {
		this->root = temp1;
		temp2->lnode = temp1->rnode;
		temp1->rnode = temp2;
	}else if(balance(this->root) < -1){
		this->root = temp1;
		temp2->rnode = temp1->lnode;
		temp1->lnode = temp2;
	}
	updateheight(this->root);
}
//std::cout << balance(temp2) << std::endl;
//std::cout << balance(temp1) << std::endl;

if(balance(temp2) > 1){
// ll
if(balance(temp1) > 0) {
if(temp3->lnode == temp2 ) {
	temp3->lnode = temp1;
}else {
	temp3->rnode = temp1;
}
temp2->lnode = temp1->rnode;
temp1->rnode = temp2;
}
updateheight(this->root);
// lr
if(balance(temp1) < 0) {
	temp2->lnode = temp;
	temp1->rnode = temp->lnode;
	temp->lnode = temp1;
	
if(temp2 == temp3->lnode) {
	temp3->lnode = temp;
}else {
	temp3->rnode = temp;
}
	temp2->lnode = temp->rnode;
	temp->rnode = temp2;
}

updateheight(this->root);
}else if(balance(temp2) < -1 ) {
// rr
if(balance(temp1) < 0) {

if(temp2 == temp3->lnode) {
	temp3->lnode = temp1;
}else {
	temp3->rnode = temp1;
}
temp2->rnode = temp1->lnode;
temp1->lnode = temp2;
}
updateheight(this->root);
// rl
if(balance(temp1) > 0) {
temp2->rnode = temp;
temp1->lnode = temp->rnode;
temp->rnode = temp1;

if(temp2 == temp3->lnode) {
	temp3->lnode = temp;
}else {
	temp3->rnode = temp;
}
temp2->rnode = temp->lnode;
temp->lnode = temp2;
}
updateheight(this->root);	
}
balance_avl(temp1);

}
void push(T x) {
node<T>* n = new node<T>();
n->rnode = NULL;
n->lnode = NULL;
n->data = x;
if(this->root == NULL ) {
this->root = n;
std::cout << n->data << std::endl;
updateheight(this->root);

return;
}
node<T>* temp = this->root;
node<T>* temp1 = NULL;
while(temp != NULL){
temp1 = temp;
if(x < temp->data ) {
temp = temp->lnode;
}else if(x > temp->data ) {
// std::cout << temp->data << std::endl;
// std::cout << temp->rnode << std::endl;
temp = temp->rnode;
// std::cout << temp << std::endl;

}else{
delete n;
return;
}
this->size_a++;
// std::cout << temp->data << std::endl;

}
 // std::cout << n->data << std::endl;
if(temp1->data < x) {
temp1->rnode = n;
 std::cout << temp1->rnode->data << std::endl;
}else{
temp1->lnode = n;
 std::cout << temp1->lnode->data << std::endl;
}
//this->preorder(this->root );
//std::cout << "root " << this->root->data << std::endl; 
updateheight(this->root);
balance_avl(n);

}

void preorder(node<T>* temp) {
if(temp == NULL ) {
	return;
}
std::cout << temp->data /*<< " ( "  << balance(temp) << " ) "*/ << "-> ";
preorder(temp->lnode);
preorder(temp->rnode);
}

};

int main() {

	node<int>* node1 = new node<int>();
	avl<int> a;

	a.push(13);
	a.push(14);
	a.push(15);
	a.push(12);
	a.push(11);
	a.push(17);
	//a.push(13);
	a.push(16);
	a.push(8);
	a.push(9);
	a.push(1);
	a.preorder(a.root);
	std::cout << std::endl;

	return 0;
}
