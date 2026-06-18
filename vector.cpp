

#include<iostream>

class demo{
};
template<typename T>
class vector {

size_t capacity_v = 0;
size_t size_v = 0;
T* v = NULL;

public :

class iterator {
	public:
	T*iptr = NULL;
	
int operator!=(const vector<T>::iterator& obj1) {
	return this->iptr !=  obj1.iptr; 
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
vector(size_t capacity_v)  {	
	this->capacity_v = capacity_v;
	this->size_v = capacity_v;
	this->v = (T*)calloc(capacity_v,sizeof(T));
	
	// std::cout << v << std::endl;
}

vector(const vector& obj) {
	this->capacity_v = obj.capacity_v;
	this->size_v = obj.size_v;

	this->v = (T*)malloc(capacity_v*sizeof(T));
	
	std::cout << "copy constructor " << std::endl;
	
	for(int x = 0;x != capacity_v; x++ ) {
		*(this->v + x) = *(obj.v + x);
	}

	std::cout << "copied successfully " << std::endl;
	std::cout <<  this->v << std::endl;
	std::cout << obj.v  << std::endl;
}

/*vector& operator=(const vector& obj) {


	std::cout << "operator called "  << std::endl;
	vector v2(obj);

	std::cout << v2.v  << std::endl;
	return v2;
}*/

void push_back(T x) {
	
	if(capacity_v == size_v) {
		capacity_v*= 2;
	}

	v = (T*)realloc(v,capacity_v*sizeof(T));
	*(v + size_v) = x;
	size_v += 1;

	// std::cout << v << std::endl;
}
void pop_back() {

	if(capacity_v == 0 ) {
		std::cout << "NULL vector " << std::endl;
		return;
	}

	// std::cout << "popback " << *(v + size_v - 1) << std::endl;
	*(v + size_v - 1) = T();
	size_v = size_v - 1;                                                                                   // always use size_v-- as size_v = size_v - 1 fails in case of string and leave destruction to proper object management 

	// std::cout << *(v + size_v) << std::endl;
	// std::cout << v << std::endl;

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


~vector() {
	std::cout << "vector destructor " << std::endl; 
	free(v);
		
}

/*int operator!=(vector<T>::iterator& obj,vector<T>::iterator& obj1) {
int operator!=(vector<T>::iterator& obj,vector<T>::iterator& obj1) {
	return obj.iptr != obj1.iptr;                                              // inside class operator only overloaded if first parameter is this 
}*/


	       



};



int main() {
	
	vector<int>v(5);
	//vector<char>v2(0);
	//vector<demo>vobj(5);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	v.pop_back();

	std::cout << v[2] << std::endl;
	std::cout << v.at(2) << std::endl;

	// vector<int>::iterator itr = v.begin();
	// std::cout << v[0] << std::endl;
	// std::cout << itr.iptr << std::endl;

	for(vector<int>::iterator itr = v.begin(); itr != v.end() ; ++itr) {
		std::cout << *itr << "-> ";
	}
	std::cout << std::endl;
	
	vector<int>::reverse_iterator itr = v.rbegin();
	do{	
		std::cout << *itr << "-> ";
		--itr;
	}while(itr != v.rend());

	std::cout << std::endl;

	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	std::cout << v.front() << std::endl;
	std::cout << v.back() << std::endl;
	std::cout << v.empty() << std::endl;
	//v.clear();
	std::cout << v.empty() << std::endl; 
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;


	vector<int>v2 = v;

	for(vector<int>::iterator itr = v2.begin(); itr != v2.end() ; ++itr) {
		std::cout << *itr << "-> ";
	}
	std::cout << std::endl;
	vector<int>::reverse_iterator itr2 = v2.rbegin();
	do{	
		std::cout << *itr2 << "-> ";
		--itr2;
	}while(itr2 != v2.rend());

	std::cout << std::endl;

	return 0;
}
