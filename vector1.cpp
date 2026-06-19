

#include<iostream>

class demo{
};
template<typename T>
class vector {

size_t capacity_v = 1;
size_t size_v = 0;
T* v = NULL;;

public :

class iterator {
	public:
	T*iptr = NULL;


bool operator!=(const vector<T>::iterator& obj1) {
	// std::cout << this->iptr << std::endl;
	// std::cout << obj1.iptr << std::endl;
	return this->iptr !=  obj1.iptr; 
}

bool operator==(const vector<T>::iterator& obj1) {
	return this->iptr == obj1.iptr;
}

vector<T>::iterator operator+(int x) {	                                                               // if we use dynamic memory for iterator object then the memory leak occurs 
	vector<T>::iterator i;
	i.iptr = this->iptr + x;
	return i;
}
vector<T>::iterator operator-(int x) {
		
	vector<T>::iterator i;
	i.iptr = this->iptr - x;
	return i;
}
iterator operator++(int) {
	vector<T>::iterator temp;
	temp = *this;
	this->iptr = this->iptr + 1; 
	return temp;
}
iterator& operator++() {                                        // there is difference in i++ and ++i i++ returns temp while ++i returns i + 1
	this->iptr += 1;
	return *this;
}

iterator& operator--() {                                        // there is difference in i++ and ++i i++ returns temp while ++i returns i + 1
	this->iptr -= 1;
	return *this;
}

T& operator*() {                                             // there should be T& instead of T gives acctual value and also in stl it is done by T& = refrence 
	return *(this->iptr);
}

};

class reverse_iterator : public iterator {
};

vector<T>::iterator begin() {
	vector<T>::iterator it;
	it.iptr = v;
	// std::cout << it.iptr << std::endl;
	return it;
}

vector<T>::reverse_iterator rend() {
	vector<T>::reverse_iterator it;
	it.iptr = v - 1;
	return it;
}

vector<T>::iterator end() {
	
	vector<T>::iterator it;
	it.iptr = v + size_v;
	// std::cout << it.iptr << std::endl;
	return it;
}
vector<T>::reverse_iterator rbegin() {
	
	vector<T>::reverse_iterator it;
	it.iptr = v + size_v - 1;

	// std::cout << *(v + size_v) << std::endl;
	// std::cout << v << std::endl;
	return it;
}


public :
vector()  {	
	this->capacity_v = 1;
	this->size_v = 0;
	this->v = new T[capacity_v];
	
	// std::cout << v << std::endl;
}

// move constructor 

vector(vector&& obj) {

	this->capacity_v = obj.capacity_v;
	this->size_v = obj.size_v;
	this->v = obj.v;

	obj.v = NULL;
	obj.capacity_v = 0;
	obj.size_v = 0;


} 

vector(const vector& obj) {
	this->capacity_v = obj.capacity_v;
	this->size_v = obj.size_v;

	this->v = new T[obj.capacity_v];
	
	for(int x = 0;x != size_v; x++ ) {
		*(this->v + x) = *(obj.v + x);
	}
}

vector<T>& operator=(const vector<T>& obj) {

	if(this == &obj) {
		return *this;
	}

	delete [] v;
	this->capacity_v = obj.capacity_v;
	this->size_v = obj.size_v;

	this->v = new T[obj.capacity_v];
	
	for(int x = 0;x != size_v; x++ ) {
		*(this->v + x) = *(obj.v + x);
	}

	std::cout << "assignment " << std::endl;

	return *this;

}

vector<T>& operator=(vector&& obj) {

	if(this == &obj) {
		return *this;
	}
	delete [] v;

	this->capacity_v = obj.capacity_v;
	this->size_v = obj.size_v;
	this->v = obj.v;

	obj.v = NULL;
	obj.capacity_v = 0;
	obj.size_v = 0;

	return *this;

}


void resize() {

	// size_t old_capacity = capacity_v;
	capacity_v = capacity_v*2;
	T* new_v = new T[capacity_v];

	for(size_t x = 0;x != size_v; x++ ) {
		*(new_v + x) = 	*(v + x);
	}

	delete [] v;
	v = new_v;

}
/*vector& operator=(const vector& obj) {


	std::cout << "operator called "  << std::endl;
	vector v2(obj);

	std::cout << v2.v  << std::endl;
	return v2;
}*/

void push_back(T x) {
	
	if(capacity_v == size_v) {
		resize();
	}
	*(v + size_v) = x;
	size_v += 1;

	// std::cout << v << std::endl;
}
template<typename... U>
void emplace_back(U&&... x) {
if(capacity_v == size_v) {
	resize();

}

	*(v + size_v) = T(std::forward<U>(x)...);
	size_v += 1;
	
}


void pop_back() {

	if(size_v == 0 ) {
		std::cout << "NULL vector " << std::endl;
		return;
	}

	*(v + size_v - 1) = T();
	size_v--;                                                                                   // always use size_v-- as size_v = size_v - 1 fails in case of string and leave destruction to proper object management 

}

inline __attribute__ ((always_inline)) T& at(int x) {
	return *(v + x);
}
inline __attribute__ ((always_inline)) T& operator[](int x) {
	return *(v + x);
}

inline __attribute__ ((always_inline)) T& front() {
	return *(v + 0);
}

inline __attribute__ ((always_inline)) size_t size() {
	return size_v;
}
inline __attribute__ ((always_inline)) T& back() {
	return *(v + size_v - 1);
}
inline __attribute__ ((always_inline)) size_t capacity() {
	return capacity_v;
}
inline __attribute__ ((always_inline)) bool empty() {
	return size_v == 0;
}
inline __attribute__ ((always_inline)) void clear() {
	for(int x = 0; x != size_v; x++){
		*(v + x) = T();
	}
	size_v = 0;
	return;
}
void insert(int x, T y) {
	if(this->size_v == this->capacity_v) {
		resize();
	}
	vector<T>::iterator itr = this->begin() + x;
	vector<T>::iterator itr2 = this->end();
	this->size_v++;

	for(itr2 ; itr2 != itr ; --itr2 ) {
		*(itr2) = *(itr2 - 1); 
	}

	*(itr) = y;

}

void erase(int x) {

	if(x < 0 || x >= size_v) {
		return;
	} 
	vector<T>::iterator itr = this->begin() + x;
	vector<T>::iterator itr2 = this->end();
	this->size_v--;

	for(itr ; itr != itr2 - 1 ; itr++ ) {
		*(itr) = *(itr + 1); 
	}

	
} 



~vector() {
	std::cout << "vector destructor " << std::endl; 
	delete [] v;
		
}

/*int operator!=(vector<T>::iterator& obj,vector<T>::iterator& obj1) {
int operator!=(vector<T>::iterator& obj,vector<T>::iterator& obj1) {
	return obj.iptr != obj1.iptr;                                              // inside class operator only overloaded if first parameter is this 
}*/


	       



};



int main() {
	
	vector<int> v;
 	v.emplace_back(4);
//	v.emplace_back(3);
//	v.emplace_back(2);
//	v.emplace_back(1);
//	v.emplace_back(0);

	for(vector<int>::iterator iptr = v.begin(); iptr != v.end() ; iptr++) {
		std::cout << *(iptr) << std::endl;
	}
	// vector<int>v2(v);
	// vector<int>v1(std::move(v));
	// vector<int>v3;
	   //    v3 = v1;

	     //  vector<int>::iterator itr = v.begin();
	      //  vector<int>::iterator itr1 = v.end();
		// itr++;
	       // std::cout << (itr == itr1) << std::endl;
	v.insert(1,4);
	v.erase(1);

	for(vector<int>::iterator iptr = v.begin(); iptr != v.end() ; iptr++) {
		std::cout << *(iptr) << std::endl;
	}

	return 0;
}
