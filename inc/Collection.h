//
// Created by phil on 8/1/20.
//

#ifndef COLLECTION_H
#define COLLECTION_H

#endif //COLLECTION_H

class Collection{

public:
    /**
     * Default Constructor creates and empty collection
     */
    Collection();

    /**
     * @Param takes and int and sets the initial capacity of the array
     */
    Collection(int size);

    /**
     * Returns the number of elements in an array
     * create a char to indicated the end of the array
     * @return integer indicating the size of the array
     */

    int getSize() const;

    /**
     * returns the max capacity of the array.
     * @return
     */

    int getCapacity();

    /**
     * adds to the collection
     * @param value
     */
    void add(double value);

    /**
     * adds to the front of the list if the new item exceeds the size throw runtime exception
     * @param value
     */
    void addFront(double value);

    /**
     * gets the value stored at the specified position. Throws an out_of_range exception if the index
     * is outside the bounds of the array.
     * @param ndx
     * @return
     */
    int get (int ndx);

    /**
     * returns the first value in the array.  Throws and out_of_range exception if the array is empty
     * @return
     */
    int getFront();

    /**
     * Returns the last value in the array.  Throws an out_of_range exception if the array is empty
     * @return
     */
    int getEnd();

    /**
     * Returns the needle in the list, returns -1 if not found
     * @param needle
     * @return
     */
    int find(double needle);

    /**
     * overload the extraction operator to display the list
     * @param out
     * @param c
     * @return
     */
    friend std::ostream& operator <<(std::ostream& out, const Collection& c);


private:
    double *arr; /** pointer to the underlying collection */
    double *temp;
    int size; /** maintain the length of the collection */
    int numElements;
    double *begin;
    double *end;
};