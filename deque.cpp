

#include<iostream> 


template<typename T>

class deque {
	public :
size_t f = 0;
size_t capacity_d = 1;
size_t size_d = 0;
T* dq = NULL;

public : 
// class iterator;
class iterator {
	public:
	deque<T>* d;
	T* iptr = NULL;

	iterator(deque<T>* d) {
		this->d = d;
	}
int operator!=(const deque<T>::iterator& obj) {
	return this->iptr != obj.iptr;
}

iterator& operator++() {
	this->iptr = d->dq  + ((this->iptr - d->dq) + 1) % d->capacity_d;
	return *this;
}

T& operator*() {
	return *(this->iptr);
}

};

public:

deque<T>::iterator begin() {
	
	iterator it(this);
	it.iptr = dq +  f;

	return it;
	
}

deque<T>::iterator end() {

	iterator it(this);
        it.iptr = dq + (f + size_d) % capacity_d;

	return it;	
	
}




public :

deque() {
this->capacity_d = 1;
this->size_d = 0;
this->dq = new T[capacity_d];

}

void resize() {
	size_t old_capacity = capacity_d;

	capacity_d = capacity_d*2;
	T* dq_new = new T[capacity_d];
	for(size_t x = 0; x != size_d; x++ ) {
		*(dq_new + x) = *(dq + (f + x) % old_capacity);
	}
	f = 0;
	delete [] dq;

	dq =  dq_new;    
}


void push_back(T x) {

if(size_d == capacity_d) {
	resize();
}


*(dq + (size_d+f) % capacity_d) = x;
size_d += 1;
}



/*void push_front(T x) {

if(f == 0) {                                                                    instead of doin all this use circular indexing 

T* dq_new = new T[capacity_d];
*(dq_new + f) = x;

for(int x = 0; x != size_d; x++ ) {
*(dq_new + f + x + 1) = *(dq + f + x);
}
delete dq;
dq = dq_new;    
}else{
*(dq + f -1) = x;

}
size_d += 1;
}*/

void push_front(T x) {

	if(capacity_d == size_d ) {
		resize();
	}

f = (f + capacity_d - 1) % capacity_d;

*(dq + f) = x;

size_d++;

}

/*template<typename U>                                               // not perfect one 
void emplace_back(U& x) {

if(size_d == capacity_d) {
	resize;

}

*(dq + size_d) = x;
size_d += 1;


}

template<typename U>
void emplace_front(U& x) {


if(size_d == capacity_d) {
	resize();
}

f = (f + capacity_d - 1) % capacity_d;

*(dq + f) = x;

si`aze_d += 1;
}*/

template<typename... U>
void emplace_back(U&& ...x) {

if(size_d == capacity_d) {
	resize();

}

*(dq + (size_d+f) % capacity_d) = T(std::forward<U>(x)...);
size_d += 1;


}

template<typename... U>
void emplace_front(U&& ...x) {


if(size_d == capacity_d) {
	resize();
}

f = (f + capacity_d - 1) % capacity_d;

*(dq + f) = T(std::forward<U>(x)...);

size_d += 1;
}




inline __attribute__ ((always_inline)) void pop_back() {
if(size_d == 0){
return;
}
*(dq + (f + size_d - 1) % capacity_d ) = T();

size_d--;

}

inline __attribute__ ((always_inline)) void pop_front() {

if(size_d == 0){
return;
}
*(dq + f) = T();
f = ((f + capacity_d + 1) % capacity_d);
size_d--;

}
inline __attribute__ ((always_inline)) T& at(int x) {
	return *(dq + (f + x) % capacity_d);
}


};

class demo {

};

int main() {

	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	dq.push_back(50);
	dq.push_back(60);
	dq.push_front(23);
	dq.push_front(354);
	dq.push_front(543);
	dq.push_front(564);
	dq.push_front(34);
	dq.push_front(34);
	dq.push_front(43);
	dq.push_front(32);

	dq.pop_front();
	dq.pop_back();
	dq.pop_front();
	dq.pop_back();
	dq.pop_front();
	dq.pop_back();
	dq.pop_front();
	dq.pop_back();


	deque<int>::iterator itr(&dq);
	deque<int>::iterator itr2(&dq);

	for(itr = dq.begin(); itr != dq.end(); ++itr ) {
		std::cout << *(itr) << std::endl;
	}
	return 0;
}
