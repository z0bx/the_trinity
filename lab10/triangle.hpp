#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "twod.hpp"
// twod-гээс удамшсан Traingle class
class triangle : public twod
{
public:
    triangle(int _a) : twod(_a) // анхдагч байгуулагч
    {
        this -> set_name("Triangle"); // нэриийг Triangle болгон тохируулна
    }

    float area() override // area-г дахин тодорхойлно
    {
        return (sqrt(3) / 4) * this -> a * this -> a; // зөв гурвалжингийн талбайг буцаана
    }

    float perimeter() override // perimeter-г дахин тодорхойлно
    {
        return 3 * this -> a; // зөв гурвалжингийн периметрийг буцаана
    }
};
#endif