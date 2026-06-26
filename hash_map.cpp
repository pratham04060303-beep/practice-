#include<iostream>


template<typename T,typename U>
class bucket {
public :
T key;
U value;
bucket<T,U>* next;

public :
bucket() {
this->key = T();
this->value = U();
this->next = NULL;
}

void operator=(const U& x) {
this->value = x;
}
	
};


template<typename T,typename U>
class hash_map {
public :
size_t capacity_h;
size_t size_h;
bucket<T,U>** buctable;

public :

hash_map() {
capacity_h = 11;
size_h = 0;
this->buctable = new bucket<T,U>*[capacity_h];

for(int x = 0; x < capacity_h ; x++) {
	this->buctable[x] = NULL;
}
}

void resize() {
size_t old_capacity_h = capacity_h;
this->capacity_h = capacity_h*2;
bucket<T,U>** buc = new bucket<T,U>*[capacity_h];
for(int x = 0; x < old_capacity_h ; x++) {
	buc[x] = this->buctable[x];
}
delete [] buctable;
this->buctable = new bucket<T,U>*[capacity_h];
this->buctable = buc;

}
// key = k mod capacity 

bucket<T,U>& operator[](T x){
if(this->load_factor() > 0.75 ) {
		this->resize();
	}
bucket<T,U>* temp = find(x);
if(temp != NULL && temp->key == x ) {
	return temp;
}	
bucket<T,U>* buc = new bucket<T,U>();
buc->key = x;
buc->next = this->buctable[x%capacity_h];
this->buctable[x%capacity_h] = buc;
size_h++;
return *buc;
}

void push(T x,U y) {
	if(this->load_factor() > 0.75 ) {
		this->resize();
	}
bucket<T,U>* temp = find(x);
if(temp != NULL && temp->key == x ) {
	temp->value = y;
	return;
}
bucket<T,U>* buc = new bucket<T,U>();
buc->key = x;
buc->next = this->buctable[x%capacity_h];
this->buctable[x%capacity_h] = buc;
buc->value = y;
size_h++;
}

void erase(const T& x) {
bucket<T,U>* temp = buctable[x%capacity_h];
bucket<T,U>* temp1 = buctable[x%capacity_h];
while(temp != NULL ) {
	if(temp->key == x) {
		break;
	}
	temp1 = temp;
	temp = temp->next;
} 
if(temp == NULL ) {
return;
}
if(temp == buctable[x%capacity_h] ) {
buctable[x%capacity_h] = temp->next;
delete temp;
size_h--;
return;
}
temp1->next = temp->next;
delete temp;
size_h--;
return;

}

void display() {
	int x = 0;
while(x != capacity_h) {
	bucket<T,U>* temp = buctable[x];
	std::cout << "Bucket " << x << ": "; 
	while(temp != NULL ) {
		std::cout << "(" << temp->key << "," << temp->value << ") -> ";
		temp = temp->next;
	}
	x++;
	std::cout << "NULL " ;
	std::cout<< std::endl;
}
}

bucket<T,U>* find(const T& x) {
bucket<T,U>* temp = buctable[x%capacity_h];
while(temp != NULL ) {
	if(temp->key == x) {
		return temp;
	}
	temp = temp->next;
}

return NULL;

}
void clear () {
bucket<T,U>* temp = buctable[0];
bucket<T,U>* temp1 = NULL;

int x = 0;
while(x != capacity_h ) {
	temp = buctable[x];
if(temp == NULL ) {
buctable[x] = NULL;
x++;
continue;
}

while(temp != NULL ) {
temp1 = temp->next;
delete temp;
size_h--;
temp = temp1;
}
buctable[x] = NULL;
x++;
}

}

inline __attribute__ ((always_inline)) bool contains(const T& x) {
return find(x) != NULL;
}
/*inline __attribute__ ((always_inline)) bool empty() {
	int x = 0;
	bucket<T,U>* temp = buctable[0];
	while( temp == NULL && x != capacity_h) {
		temp = buctable[x];
		x++;
	}
return temp == NULL;
}*/

inline __attribute__ ((always_inline)) bool empty() {
	return size_h == 0;
}
/*inline __attribute__ ((always_inline)) size_t size() {
size_t size_m = 0;
int x = 0;
bucket<T,U>* temp = NULL;
while(x != capacity_h ) {
	temp = buctable[x];
while(temp != NULL ) {
temp = temp->next;
size_m++;
}
x++;
}

return size_m;

}*/
inline __attribute__ ((always_inline)) size_t size() {
	return size_h;
}
inline __attribute__ ((always_inline)) float load_factor() {
	return (float)size_h/capacity_h;
}
inline __attribute__ ((always_inline)) size_t bucket_count() {
	return capacity_h;
}
// iterator 
class iterator {

public :
bucket<T,U>* buck =  NULL;
hash_map<T,U>* hash = NULL;
size_t index;

iterator() {
this->buck = NULL;
this->hash = NULL;
this->index = 0;
}

void operator=(const hash_map::iterator& itr) {
this->buck = itr.buck;
this->hash = itr.hash;
this->index = itr.index;
}

bucket<T,U>& operator*() {
return *(this->buck);
}
bucket<T,U>* operator->() {
return this->buck;
}


// T operator->()

bool operator!=(const hash_map<T,U>::iterator& itr) {
return this->index <= itr.index;
}
bool operator==(const hash_map<T,U>::iterator& itr) {
//	std::cout << this->buck << " " << itr.buck << std::endl;
return this->buck == itr.buck && this->index == itr.index;
}
hash_map<T,U>::iterator operator++(int) {
bucket<T,U>* buc = this->buck->next;
while(buc == NULL && this->index < this->hash->capacity_h ) {
	this->index++;
	buc = this->hash->buctable[this->index];
}

this->buck = buc;
return *this;
}
hash_map<T,U>::iterator operator++() {
bucket<T,U>* buc = this->buck->next;
while(buc == NULL && this->index < this->hash->capacity_h ) {
	this->index++;
	buc = this->hash->buctable[this->index];
}

this->buck = buc;
return *this;
}

};




hash_map<T,U>::iterator begin() {
hash_map<T,U>::iterator itr;
int x = 0;
while(itr.buck == NULL && x < this->capacity_h) {
itr.buck = this->buctable[x];
itr.index = x++;
}
itr.hash = this;
// std::cout << itr.index << std::endl;
return itr;
}
hash_map<T,U>::iterator end() {
hash_map<T,U>::iterator itr;
itr.buck = NULL;
itr.hash = this;
itr.index = this->capacity_h - 1;

return itr;
}



};
int main() {

    hash_map<int,int> h;

    for(int i=0;i<10000;i++)
        h.push(i,i*5);

    int count = 0;

    for(auto it = h.begin(); it != h.end(); ++it)
    {
        if(it->value != it->key * 5)
        {
            std::cout << "FAIL\n";
            return 0;
        }

        count++;
    }

    if(count == h.size())
        std::cout << "PASS\n";

	return 0;
}
