
#include<iostream>


template<typename T>
// node class 
class node {
public : 

T data = T();
node<T>* pre = NULL;
node<T>* next = NULL;

node(T x) {
this->data = x;
this->pre = NULL;
this->next = NULL;
}
template<typename... U>
node(U&& ...x) {
this->data = T(std::forward<U>(x)...);
this->pre = NULL;
this->next = NULL;
}

};

// list class 
template<typename T>
class dlist {

public :
node<T>* head = NULL;
node<T>* tail = NULL;
size_t size_dll = 0;

dlist() {
this->head = NULL;
this->tail = NULL;
this->size_dll = 0;
}

void push_back(T x) {

node<T>* n = new node(x);

if(size_dll == 0) {
n->next = NULL;
n->pre = NULL;
this->head = n;
this->tail = n;
this->size_dll++;
return;

}
n->next = NULL;
n->pre = this->tail;
this->tail->next = n;
this->tail = n;
this->size_dll++;

}
template<typename... U>

void emplace_back(U&& ...x) {

node<T>* n = new node<T>(std::forward<U>(x)...);

if(size_dll == 0) {
n->next = NULL;
n->pre = NULL;
this->head = n;
this->tail = n;
this->size_dll++;
return;

}
n->next = NULL;
n->pre = this->tail;
this->tail->next = n;
this->tail = n;
this->size_dll++;

}

void pop_back() {

if(size_dll == 0){
	return;
}

if(size_dll == 1){
	node<T>* temp = this->head;
	this->head = NULL;
	this->tail = NULL;
	delete temp;
	size_dll--;
	return;
}
node<T>* temp = this->tail;
this->tail = temp->pre;
this->tail->next = NULL;
delete temp;
size_dll--;

}


void push_front(T x) {

node<T>* n = new node(x);

if(size_dll == 0) {
n->next = NULL;
n->pre = NULL;
this->head = n;
this->tail = n;
this->size_dll++;
return;

}

n->next = this->head;
n->pre = NULL;
this->head->pre = n;
this->head = n;
this->size_dll++;


}

template<typename... U>

void emplace_front(U&& ...x) {

node<T>* n = new node<T>(std::forward<U>(x)...);

if(size_dll == 0) {
n->next = NULL;
n->pre = NULL;
this->head = n;
this->tail = n;
this->size_dll++;
return;

}

n->next = this->head;
n->pre = NULL;
this->head->pre = n;
this->head = n;
this->size_dll++;

}

void pop_front() {

if(size_dll == 0){
	return;
}
if(size_dll == 1){
	node<T>* temp = this->head;
	this->head = NULL;
	this->tail = NULL;
	delete temp;
	size_dll--;
	return;
}

node<T>* temp = this->head;
this->head = temp->next;
head->pre = NULL;
delete temp;
size_dll--;

}
// iterators class 

class iterator {
public :
node<T>* iptr = NULL;
iterator() {
this->iptr = NULL;
}
iterator(node<T>* iptr) {
this->iptr = iptr;
}
		

bool operator==(const dlist<T>::iterator& itr){
	return this->iptr == itr.iptr;
}
bool operator!=(const dlist<T>::iterator& itr){
	return this->iptr != itr.iptr;
}
dlist<T>::iterator operator+(int x) {

	dlist<T>::iterator temp = *this;
	while(x != 0) {
		temp.iptr = (temp.iptr)->next;
		x--;
	}
	return temp;
}
dlist<T>::iterator& operator++(){
	this->iptr = (this->iptr)->next;
	return *this;
}
dlist<T>::iterator operator++(int){
	dlist<T>::iterator temp = *this;
       	this->iptr = (this->iptr)->next;
	return temp;
}
dlist<T>::iterator& operator--(){
	this->iptr = (this->iptr)->pre;
	return *this;
}
dlist<T>::iterator operator--(int){
	dlist<T>::iterator temp = *this;
       	this->iptr = (this->iptr)->pre;
	return temp;
}
dlist<T>::iterator operator-(int x) {
	dlist<T>::iterator temp = *this;
	while(x != 0) {
		temp.iptr = (temp.iptr)->pre;
		x--;
	}
	return temp;
}
T& operator*() {
	return ((this->iptr)->data);
}
dlist<T>::iterator& operator=(const dlist<T>::iterator& itr) {
	this->iptr = itr.iptr;
	return *this;
}



};

dlist<T>::iterator begin() const {
dlist<T>::iterator itr(this->head);
return itr;
}
dlist<T>::iterator end() const {
dlist<T>::iterator itr(NULL);
return itr;
}


// reverse iterator 
class reverse_iterator{
public :
node<T>* iptr = NULL;
reverse_iterator() {
this->iptr = NULL;
}
reverse_iterator(node<T>* iptr) {
this->iptr = iptr;
}

bool operator==(const dlist<T>::reverse_iterator& itr){
	return this->iptr == itr.iptr;
}
bool operator!=(const dlist<T>::reverse_iterator& itr){
	return this->iptr != itr.iptr;
}
dlist<T>::reverse_iterator operator+(int x) {
	dlist<T>::reverse_iterator temp = *this;
	while(x != 0) {
		temp.iptr = (temp.iptr)->pre;
		x--;
	}
	return temp;
}
dlist<T>::reverse_iterator& operator++(){
	this->iptr = (this->iptr)->pre;
	return *this;
}
dlist<T>::reverse_iterator operator++(int){
	dlist<T>::reverse_iterator temp = *this;
       	this->iptr = (this->iptr)->pre;
	return temp;
}
dlist<T>::reverse_iterator& operator--(){
	this->iptr = (this->iptr)->next;
	return *this;
}
dlist<T>::reverse_iterator operator--(int){
	dlist<T>::reverse_iterator temp = *this;
       	this->iptr = (this->iptr)->next;
	return temp;
}
dlist<T>::reverse_iterator operator-(int x) {
	dlist<T>::reverse_iterator itr = *this;
	while(x != 0) {
		itr.iptr = (itr.iptr)->next;
		x--;
	}
	return itr;
}
T& operator*() {
	return ((this->iptr)->data);
}
dlist<T>::iterator& operator=(const dlist<T>::reverse_iterator& itr) {
	this->iptr = itr.iptr;
	return *this;
}

};

dlist<T>::reverse_iterator rbegin() const {
dlist<T>::reverse_iterator itr(this->tail);
return itr;
}
dlist<T>::reverse_iterator rend() const {
dlist<T>::reverse_iterator itr(NULL);
return itr;
}

void erase(int x) {
if(x < 0 || x > size_dll - 1) {
return;
}

if(x == 0 ) {
this->pop_front();
return;
}

if(x == size_dll - 1) {
this->pop_back();
return;
}

if(size_dll == 0) {
	return;
}

dlist<T>::iterator temp = this->begin();

while(x != 0) {
	temp.iptr = temp.iptr->next;
	x--;
}
if(size_dll == 1) {
	size_dll--;
	return;
}
temp.iptr->pre->next = temp.iptr->next;
temp.iptr->next->pre = temp.iptr->pre;

delete temp.iptr;
size_dll--;
}

void insert(int x , T y ) {
if(x < 0 || x > size_dll) {
return;
}

if(x == 0 ) {
this->push_front(y);
return;
}
if(x == size_dll ) {
this->push_back(y);
return;
}

dlist<T>::iterator temp = this->begin();

while(x != 0) {
	temp.iptr = temp.iptr->next;
	x--;
}

node<T>* n = new node<T>(y);
temp.iptr->pre->next = n;
n->next = temp.iptr;
n->pre = temp.iptr->pre;
temp.iptr->pre = n;

size_dll++;
}



void clear() {

	dlist<T>::iterator temp = this->begin();
	dlist<T>::iterator temp1 = this->begin();
	while(temp.iptr != NULL) {
		temp1.iptr = temp1.iptr->next;
		delete temp.iptr;
		temp = temp1;
	}

	this->head = NULL;
	this->tail = NULL;
	size_dll = 0;
}

inline __attribute__ ((always_inline)) int empty() {
	return size_dll == 0;
}
inline __attribute__ ((always_inline)) T& front() {
	dlist<T>::iterator itr = this->begin();
	return *(itr);
}
inline __attribute__ ((always_inline)) T& back() {
	return this->tail->data;
}
inline __attribute__ ((always_inline)) size_t size() {
	return size_dll;
}


dlist(const dlist<T>& obj ) {

	this->head = NULL;
	this->tail = NULL;
	this->size_dll = 0;
	dlist<T>::iterator itr = obj.begin();

	while(itr != obj.end()) {
		this->push_back(*itr);
		itr++;
	}

}

dlist(dlist<T>&& obj) {
	this->head = obj.head;
	this->tail = obj.tail;
	this->size_dll = obj.size_dll;
	
	obj.head = NULL;
	obj.tail = NULL;
	obj.size_dll = 0;
}
dlist<T>& operator=(const dlist<T>& obj ) {
	
	if(this == &obj){
		return *this;
	}

	this->clear();

	dlist<T>::iterator itr = obj.begin();

	while(itr != obj.end()) {
		this->push_back(*itr);
		itr++;
	}

	return *this;


}
dlist<T>& operator=(dlist<T>&& obj) {
	
	if(this == &obj){
		return *this;
	}
	this->clear();
	this->head = obj.head;
	this->tail = obj.tail;
	this->size_dll = obj.size_dll;
	
	obj.head = NULL;
	obj.tail = NULL;
	obj.size_dll = 0;

	return *this;
}



~dlist() {
	std::cout << "dlist destructor " << std::endl;
	clear();
}

void print() {

node<T>* temp = this->head;


while(temp != NULL) {
	std::cout << temp->data << "-> ";
	temp = temp->next;
}
	std::cout << std::endl;

}


};

int main() {

	dlist<int> dll;
	dll.push_back(5);
	dll.push_back(6);
	dll.push_back(7);
	dll.push_front(5);
	dll.push_front(6);
	dll.push_front(7);
	dll.emplace_back(8);
	dll.emplace_front(8);
	dll.print();
	dlist<int>::iterator itr;
	dlist<int>::reverse_iterator itr1;
	dll.pop_front();
	dll.pop_back();
	dll.erase(3);
	dll.erase(2);
	dll.erase(0);
	dlist<int> dll1;
	dll1 = dll;
	dlist<int> dll2(dll1);
	dlist<int> dll3(std::move(dll2));
	dlist<int> dll4;
	dll4 = std::move(dll3);

	for(dlist<int>::iterator itr = dll1.begin(); itr != dll1.end(); itr++) {
		std::cout << *(itr) << "-> ";
	}
	std::cout << std::endl;
	for(dlist<int>::iterator itr = dll.begin(); itr != dll.end(); itr++) {
		std::cout << *(itr) << "-> ";
	}
	std::cout << std::endl;
	for(dlist<int>::iterator itr = dll2.begin(); itr != dll2.end(); itr++) {
		std::cout << *(itr) << "-> ";
	}
	std::cout << std::endl;
	for(dlist<int>::iterator itr = dll3.begin(); itr != dll3.end(); itr++) {
		std::cout << *(itr) << "-> ";
	}
	std::cout << std::endl;
	for(dlist<int>::iterator itr = dll4.begin(); itr != dll4.end(); itr++) {
		std::cout << *(itr) << "-> ";
	}
	std::cout << std::endl;


	return 0;

}
