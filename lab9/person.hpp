#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>
using namespace std;

class person{
    protected:
        string name;
        string ssn;
        int age;
    public: 
        person(string n = "", string s = "", int a = 0);
        virtual ~person() {};
        virtual void PrintInfo() = 0;
        string getName;
        string getSSNum;
        int getAge();
        void setName(string n);
        void setSSNum(string s);
        void setAge(int a);
};
#endif