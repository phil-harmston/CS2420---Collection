#include <iostream>
#include <Collection.h>
#include <stdexcept>
#include <string>

using std::out_of_range;
using std::ostream;
using std::cout;
using std::endl;
using std::runtime_error;

Collection::Collection(){

arr = new double[0];
size = 0;
this->numElements = 0;
}


Collection::Collection(int size) {

    arr = new double[size];
    this->size = size;
    this->numElements = 0;

}

int Collection::getSize() const {
    return this->numElements;

}

int Collection::getCapacity(){
    return this->size;
}

void Collection::add(double value) {
    char *error = "List is full";
    try {
    if (this->size >= this->numElements) {
        this->arr[this->numElements] = value;
        this->numElements++;
    } else {
        throw std::runtime_error("List is Full\n");
    }

}
    catch(...){

    }
    }



void Collection::addFront(double value){
    temp = new double[size+1];
    try {
        if (this->size >= this->numElements) {
            for (int i = 0; i <= this->numElements; i++) {
                temp[i + 1] = this->arr[i];
            }
            temp[0] = value;
            this->numElements++;
            delete arr;
            arr = temp;

        } else {
            throw std::runtime_error("List is Full\n");
        }
    }
   catch(...){

   }
}


int Collection::get(int ndx) {
    return this->arr[ndx];
}

int Collection::getFront(){
return this->arr[0];
}

int Collection::getEnd(){

 return this->arr[this->numElements-1];
}

int Collection::find(double needle){
for(int i=0; i <= numElements; i++){
    if(this->arr[i]==needle){
        return this->arr[i];
    }else{
        return -1;
    }
}
}
std::ostream& operator<<(std::ostream& out, const Collection& c) {
int size = c.size;
int i= 0;

    while(i < size ) {
        if (i < size - 1) {
            out << c.arr[i] << " ";
        } else {
            out << c.arr[i];
        }
        i++;
    }
    return out;
}

