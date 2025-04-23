#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include "person.hpp"
class employee : public person{
    protected:
        string companyID;
        string title;
        string startDate;
    public:
        string getCompanyID();
        string getTitle();
};
#endif