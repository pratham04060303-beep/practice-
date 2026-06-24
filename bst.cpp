
#include<iostream>

template<typename T>
class node {

public :
T data;
node<T>* rnode = NULL;
node<T>* lnode = NULL;

node(T x) {

this->data = x;
this->rnode = NULL;
this->lnode = NULL;
}

node() {
this->data = T();
this->rnode = NULL;
this->lnode = NULL;
}

T& operator*() {
return this->data;
}

};

template<typename T>

class bst {
public :
node<T>* root = NULL;
size_t n_count;


public :

bst() {
this->n_count = 0;

this->root = NULL;

}

void insert(const T& x) {
node<T>* n = new node(x);
if(root == NULL) {
root = n;
n_count++;

return;
}

node<T>* temp = this->root;
node<T>* temp1 = NULL;
size_t count = 0;

while(temp != NULL){
temp1 = temp;
count++;
if(n->data > temp->data ) {
	temp = temp->rnode;	
}else if(n->data < temp->data ) {
	temp = temp->lnode;
}else if(n->data == temp->data) {
	delete n;
	return;
}

}

if(temp1->data > n->data ) {
temp1->lnode = n;
}else if(temp1->data < n->data ) {
temp1->rnode = n;
}
n_count++;
}

node<T>* search(T x) {

node<T>* temp = this->root;

if(root == NULL) {
return temp;
}

while(temp != NULL && x != temp->data) {

if(x < temp->data ) {
temp = temp->lnode;
}else if(x > temp->data ) {
temp = temp->rnode;
}
if(temp == NULL) {
return this->root;
}
}
if(temp == NULL ) {
	return NULL;
}
return temp;
}

// unneccesary calculations 
/*void preorder() {
static node<T>* parent = this->root;
node<T>* temp = parent;
std::cout << temp->data << "-> ";
if(root->lnode == NULL && root->rnode == NULL) {
return;
}

if(temp->lnode != NULL) {
if(temp->lnode->lnode == NULL && temp->lnode->rnode == NULL ) {
	std::cout << temp->lnode->data << "-> "; 
}else{	
parent = parent->lnode;
preorder();
parent = temp;
}
}

if(temp->rnode != NULL) {
if(temp->rnode->lnode == NULL && temp->rnode->lnode == NULL  ) {
	std::cout << temp->rnode->data << "-> "; 
}else{
parent = parent->rnode;
preorder();
parent = temp;
}
}

}*/

void preorder(node<T>* temp) {

	if(temp == NULL ) {
		return;
	}
std::cout << temp->data << "-> "; 
preorder(temp->lnode);
preorder(temp->rnode);
 
}

void postorder(node<T>* temp ) {
if(temp == NULL ) {
	return;
}
postorder(temp->lnode);
postorder(temp->rnode);
std::cout << temp->data << "-> " ;

}

void inorder(node<T>* temp) {


if(temp == NULL) {
return;
}
inorder(temp->lnode);
std::cout << temp->data << "-> " ;
inorder(temp->rnode);
}


void min(node<T>* temp) {
	if(root == NULL) {
		return;
	}
if(temp->lnode == NULL ) {
	std::cout << temp->data << std::endl;
	return;
}
min(temp->lnode);
}

void max(node<T>* temp) {
	if(root == NULL) {
		return;
	}
if(temp->rnode == NULL ) {
	std::cout << temp->data << std::endl;
	return;
}
max(temp->rnode);
}

void erase(const T& x) {
	
node<T>* temp = this->root;
node<T>* temp1 = temp;
if(root == NULL) {
return;
}

while(temp != NULL && x != temp->data) {
if(x < temp->data ) {
temp1 = temp;
temp = temp->lnode;
}else if(x > temp->data ) {
temp1 = temp;
temp = temp->rnode;
}
}
if(temp == NULL) {
return;
}

if(temp == root ) {
if(temp->lnode == NULL && temp->rnode == NULL )  {
delete temp;
this->n_count--;
root = NULL;
return;
}
if(temp->lnode != NULL && temp->rnode != NULL ) {
node<T>* temp2 = temp->lnode;

while(temp2->rnode != NULL ) {
temp2 = temp2->rnode;
}
std::cout << temp2->data << std::endl;

temp2->rnode = temp->rnode;
root = temp->lnode;
this->n_count--;
delete temp;
return;

}

if(temp->lnode == NULL || temp->rnode == NULL ) {
if(temp->rnode == NULL ) {
root = temp->lnode;
delete temp;
}else {
root = temp->rnode;
}
delete temp;
this->n_count--;

return;
}

}


// leafnode 
if(temp->lnode == NULL && temp->rnode == NULL )  {
if (temp1->rnode == temp ) {
temp1->rnode = NULL ;
delete temp;
}else{
temp1->lnode = NULL;
delete temp;
}
this->n_count--;
return;
}

// middlenode with two child 
if(temp->rnode != NULL && temp->lnode != NULL) {
if(temp1->rnode == temp ) {
temp1->rnode = temp->lnode;
}else{
temp1->lnode = temp->lnode;
}

node<T>* temp2 = temp->lnode;

while(temp2->rnode != NULL) {
temp2 = temp2->rnode;
}

temp2->rnode = temp->rnode;

delete temp; 
this->n_count--;
return;
}

// middlenode only one child
if(temp->lnode == NULL || temp->rnode == NULL )  {
if(temp->rnode == NULL ) {
if(temp1->rnode == temp ) {
temp1->rnode = temp->lnode;
}else{
temp1->lnode = temp->lnode;
}
}else{
if(temp1->rnode == temp ) {
temp1->rnode = temp->rnode;
}else{
temp1->lnode = temp->rnode;
}
}
delete temp;
this->n_count--;
return;
}


}

inline __attribute__ ((always_inline)) size_t node_count() {
	size_t node_c = this->n_count;
	return node_c;
}

long height(node<T>* temp) {

	long a_countr = -1;
	long a_countl = -1;

	if(temp == NULL) {
		return a_countr;
	}
	a_countl = 1 + height(temp->lnode);
	a_countr = 1 + height(temp->rnode);

	if(a_countl > a_countr ) {
		return a_countl;
	}else{
		return a_countr;
	}

}
void clear(node<T>* temp ) {
if(temp == NULL ) {
	return;
}
clear(temp->lnode);
clear(temp->rnode);
delete temp;
this->n_count = 0;

}
// rule of five 

node<T>* copy(node<T>* temp) {

if(temp == NULL) {
return NULL;
}
node<T>* n = new node<T>();
n->lnode = copy(temp->lnode);
n->rnode = copy(temp->rnode);
n->data = temp->data;

return n;

}

bst(const bst<T>& b ) {
this->root = this->copy(b.root);
this->n_count = b.n_count;

}

bst(bst<T>&& b) {
size_t count = n_count;
node<T>* node = this->root;
this->root = b.root;
this->n_count = b.n_count;
b.root = NULL;
b.n_count = 0;

}

bst<T>& operator=(const bst<T>& b ) {
if(this == &b) {
return *this;
}
this->clear(this->root);
this->root = this->copy(b.root);
this->n_count = b.n_count;
return *this;

}

bst<T>& operator=(bst<T>&& b) {
if(this == &b) {
return *this;
}
this->clear(this->root);
size_t count = n_count;
node<T>* node = this->root;
this->root = b.root;
this->n_count = b.n_count;
b.root = NULL;
b.n_count = 0;

return *this;

}

~bst() {
	std::cout << "bst destructor " << std::endl;
	this->clear(this->root);
	root = NULL;
	n_count = 0;
}

};

int main() {
bst<int> b1;
for(int i = 0; i < 10; i++)
    b1.insert(i);
b1.inorder(b1.root);
std::cout << std::endl;
bst<int> b2(b1);    
b2.inorder(b2.root);
std::cout << std::endl;         // copy ctor
bst<int> b3(std::move(b1));
b3.inorder(b3.root); 
std::cout << std::endl; // move ctor

bst<int> b4;
b4 = b2;            
b4.inorder(b4.root);   
std::cout << std::endl; // copy assignment

bst<int> b5;
b5 = std::move(b3); 
b5.inorder(b5.root);    
std::cout << std::endl;     // move assignment
    return 0;
}
