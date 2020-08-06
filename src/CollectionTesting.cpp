#include <iostream>
#include <sstream>
#include "../inc/Collection.h"

using namespace std;

void TestCollection();
void TestExceedSize();
void TestAddBeginning();
void TestgetFront();
void TestgetEnd();
void TestFind();
void TestExtractionOperator();
bool checkCase(std::string name, bool condition);

int main()
{
    TestCollection();
    TestExceedSize();
    TestAddBeginning();
    TestgetFront();
    TestgetEnd();
    TestFind();
    TestExtractionOperator();
    return 0;
}
void TestCollection(){
    Collection one(2);
    one.add(2.2);
    one.add(4.5);

    checkCase("Adding 1", one.get(0) == 2.2);
    checkCase("Adding 2", one.get(1) == 4.5);
    checkCase("Check Size", one.getSize()== 2);
}
void TestExceedSize(){
    Collection one(5);
    for(int i = 0; i < 5; i++){
        one.add(i);
    }

    checkCase("Exceed Size 1", one.get(0) == 0);
    checkCase("Exceed Size 2", one.get(one.getCapacity()-1) == one.getCapacity()-1);


}
void TestAddBeginning(){
    Collection one(6);

    for(int i = 0; i < 5; i++){
        one.add(i);
    }
    one.addFront(2);
    checkCase("Add to Front Check 1", one.get(0) == 2);
    checkCase("Add to Front Check 2", one.get(5) == 4);
    checkCase("Add to Front Check 3", one.getSize() == 6);


}

void TestgetFront(){
    Collection one(5);
    one.addFront(9);
    checkCase("Get front Value", one.getFront()==9);
}

void TestgetEnd(){
    Collection two(6);
    for(int i = 0; i < 5; i++){
        two.add(i);
    }

    checkCase("Get end Value: ", two.getEnd()==4);
}

void TestFind(){
    Collection one(2);
    one.add(10);
    one.add(4);
    checkCase("Find value: ", one.find(7)==-1);
    checkCase("Find value: ", one.find(4)==1);
}
void TestExtractionOperator(){
    Collection one(2);
    one.add(1);
    one.add(2);
    stringstream sout;
    sout << one;
    checkCase("Overloaded Extraction Operator", sout.str() == "1 2");
}

bool checkCase(string name, bool condition){
    if(!condition){
            cout << "Failed: " << name << endl;
    }
    else{
            cout << name << ": passed" << endl;
    }
    return condition;
}
