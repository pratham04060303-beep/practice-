

#include<iostream>

template<typename T>
class stack {

size_t size_s = 0;
size_t capacity_s = 1;
T* s = NULL;

public:

stack() {
this->size_s = 0;
this->capacity_s = 1;
this->s = new T[capacity_s];

}

stack(const stack<T>& sta) {

this->size_s = sta.size_s;
this->capacity_s = sta.capacity_s;
this->s = new T[capacity_s];

for(size_t x = 0; x != size_s; x++ ){
*(this->s + x) = *(sta.s + x);
}

}
stack(stack<T>&& sta) {

this->size_s = sta.size_s;
this->capacity_s = sta.capacity_s;
this->s = sta.s;
sta.s = NULL;
sta.size_s = 0;
sta.capacity_s = 1;

}
stack<T>& operator=(const stack<T>& sta) {
if(this == &sta) {
return *this;
}

delete [] this->s;
this->size_s = sta.size_s;
this->capacity_s = sta.capacity_s;
this->s = new T[capacity_s];

for(size_t x = 0; x != size_s; x++ ){
*(this->s + x) = *(sta.s + x);
}
return *this;
}
stack<T>& operator=(stack<T>&& sta) {
if(this == &sta) {
return *this;
}

delete [] this->s;

this->size_s = sta.size_s;
this->capacity_s = sta.capacity_s;
this->s = sta.s;
sta.s = NULL;
sta.size_s = 0;
sta.capacity_s = 1;

return *this;

}


void resize() {
capacity_s = capacity_s*2;
T* temp = this->s;
this->s = new T[capacity_s];
for(size_t x = 0; x != size_s; x++ ) {
*(this->s + x) = *(temp + x);
}

delete [] temp;
}

void push(const T& x) {
if(size_s == capacity_s) {
resize();
}

*(this->s + size_s) = x;
size_s++;

}
template<typename... U>
void emplace(U&& ...x) {

if(size_s == capacity_s) {
resize();
}

*(this->s + size_s) = T(std::forward<U>(x)...);
size_s++;

}

void pop() {
if(size_s == 0 ) {
return;
}

*(this->s + size_s - 1) = T();
size_s--;
}

void swap(stack<T>& sta) {
	
size_t size = this->size_s;
size_t capacity = this->capacity_s;
this->size_s = sta.size_s;
this->capacity_s = sta.capacity_s;
T* temp = this->s;
this->s = sta.s;
sta.s = temp;
sta.size_s = size;
sta.capacity_s = capacity;


}

inline __attribute__ ((always_inline)) size_t size() {
	return size_s;
}
inline __attribute__ ((always_inline)) T top() {
	if(size_s == 0) {
	return 0;
	}
	return *(this->s + size_s - 1);
}
inline __attribute__ ((always_inline)) bool empty() {
	return size_s == 0;
}

~stack() {
	std::cout << "stack destructor " << std::endl;
	delete [] this->s;
}

};
template<typename T>
void swap(stack<T>& s, stack<T>& s1) {
	s.swap(s1);
}

int main() {

	return 0;
}
