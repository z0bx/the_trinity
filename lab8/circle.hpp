#ifndef CIRCLE_HPP
#define CIRCLE_HPP
// twod-гээс удамшсан Circle class
#include "twod.hpp"
class circle : public twod
{
public:
    circle(int _a) : twod(_a) // анхдагч байгуулагч
    {
        this->set_name("Circle"); // нэрийг Circle болгон тохируулна
    }

    float area() override // area-г дахин тодорхойлно
    {
        return M_PI * this->a * this->a; // дугуйн талбайг буцаана
    }
    float perimeter() override // perimeter-г дахин тодорхойлно
    {
        return M_PI * 2 * this->a; // дугуйн периметрийг буцаана
    }
};
#endif