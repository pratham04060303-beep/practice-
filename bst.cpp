
#include<iostream>
#include<queue> 

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
return NULL;
}

while(temp != NULL && x != temp->data) {

if(x < temp->data ) {
temp = temp->lnode;
}else if(x > temp->data ) {
temp = temp->rnode;
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

void level_order (node<T>* temp) {
std::queue<node<T>*>q;
q.push(temp);
size_t count = n_count;
// std::cout << n_count << count << std::endl;

	while(count != 0 ) {
		//if(q.front() != NULL ){
		std::cout << (q.front()->data) << " " ;
		//}
		if(q.front()->lnode != NULL ) {
		q.push(q.front()->lnode);
		}
		if(q.front()->rnode != NULL ) {
		q.push(q.front()->rnode);
		}
		q.pop();
		count--;
	}


}



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

// normal iterators 
class iterator {
	public:
node<T>* iptr = NULL;
node<T>* root = NULL;
node<T>* next = NULL;

public :
iterator() {
this->iptr = NULL;
this->root = NULL;
this->next = NULL;
}

T& operator*() {
return this->iptr->data;
}

node<T>* nexty(node<T>* temp) {
if(temp == NULL ) {
return NULL;
}

nexty(temp->lnode);
if(this->next == NULL) {
if(temp->data > this->iptr->data ) {
	// std::cout << temp->data << "-> ";
	this->next = temp;
}

}
nexty(temp->rnode);

return this->next;

}

bst<T>::iterator& operator++() {
this->next = NULL;
this->iptr = nexty(this->root);
return *this;
}

int operator!=(bst<T>::iterator& itr) {
	return this->iptr != itr.iptr;
}

bst<T>::iterator& operator+(int x) {
	while(x != 0) {
	this->iptr = nexty(this->root);
	x--;
	}
	return *this;
}
};


bst<T>::iterator& begin() const {
bst<T>::iterator* itr = new iterator();

node<T>* temp = this->root;
while(temp->lnode != NULL) {
temp = temp->lnode;
}
itr->iptr = temp;
itr->root = this->root;

return *itr;

}
/*bst<T>::iterator& end() const {
bst<T>::iterator* itr = new iterator();

node<T>* temp = this->root;
while(temp->rnode != NULL) {
temp = temp->rnode;
}
itr->iptr = temp;

return *itr;

}*/

bst<T>::iterator& end() const {
bst<T>::iterator* itr = new iterator();
itr->iptr = NULL;
return *itr;
}

// constant iterators 

class const_iterator : public iterator {
public :

const T& operator*() const {
return this->iptr->data;
}

};

bst<T>::const_iterator& cbegin() const {
bst<T>::const_iterator* itr = new const_iterator();

node<T>* temp = this->root;
while(temp->lnode != NULL) {
temp = temp->lnode;
}
itr->iptr = temp;
itr->root = this->root;

return *itr;

}
bst<T>::const_iterator& cend() const {
bst<T>::const_iterator* itr = new const_iterator();
itr->iptr = NULL;
return *itr;
}


inline __attribute__ ((always_inline))bool contains(const T& x) {
	return this->search(x) != NULL;
}
inline __attribute__ ((always_inline))bool empty() {
	return root == NULL;
}

};

int main() {

    bst<int> b;

    int arr[] = {50,30,70,20,40,60,80,35,45,55,65};

    for(int x : arr) {
        b.insert(x);
    }

	for(auto it = b.begin(); it != b.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
        std::cout << b.contains(70) << std::endl;
        std::cout << b.contains(85) << std::endl;
        std::cout << b.search(70) << std::endl;
        std::cout << b.search(85) << std::endl;
		std::cout << b.empty() << std::endl;

		bst<int>::const_iterator itr = b.cbegin();
	for(itr; itr != b.cend(); ++itr) {
        std::cout << *itr << " ";
    }
	std::cout << std::endl;

	b.level_order(b.root);
	std::cout << std::endl;


	return 0;
}

