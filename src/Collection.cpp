#include <iostream>
#include <Collection.h>
#include <stdexcept>
#include <string>

using std::out_of_range;
using std::ostream;
using std::cout;
using std::endl;
using std::runtime_error;
using std::out_of_range;


/*
 *  Create a new collection
 */
Collection::Collection(){

arr = new double[0];
size = 0;
this->numElements = 0;
}

/*
 *  Create a collection of a certain size.
 */
Collection::Collection(int size) {

    arr = new double[size];
    this->size = size;
    this->numElements = 0;

}

/*
 *  Returns the number of elements in the Collection
 */
int Collection::getSize() const {
    return this->numElements;

}
/*
 *  Returns the size of the Collection
 */
int Collection::getCapacity(){
    return this->size;
}

/*
 *  Adds a value to the collection as long as there is room
 */
void Collection::add(double value) {
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

/*
 *  Adds a value to the front of the collection
 */
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

/*
 *  Gets the value at a certain index
 */
double Collection::get(int ndx) {
    try{
        if(this->size > ndx){
            return this->arr[ndx];
    }
        throw std::out_of_range("out of range");
    }
    catch(...){

    }

}

/*
 * Get the value of the front position and return it
 */
int Collection::getFront(){
    try{
        if (this->size >= 0){
            return this->arr[0];
        }
        throw out_of_range("out of range");

    }
    catch(...){

    }

}
/*
 * Returns the last position throws error if out of range.
 */
int Collection::getEnd(){
    try{
        if(this->size > 0){
            return this->arr[this->numElements-1];
        }
    throw out_of_range("out of range");
    }

    catch (...){

    }
}
/*
 * Returns the position of the needle if found.
 */
double Collection::find(double needle) {
    for (int i = 0; i <= this->numElements-1; i++) {
        if(this->arr[i]==needle){
            return i;
        }
    }
    return -1;
}

/*
 * Overload the output stream for printing
 */
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

