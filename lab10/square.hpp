#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "twod.hpp"
// twod-гээс удамшсан Square class
class square : public twod
{
public:
    square(int _a) : twod(_a) // анхдагч байгуулагч
    {
        this -> set_name("Square"); // нэриийг Square болгон тохируулна
    }

    float area() override // area-г дахин тодорхойлно
    {
        return this -> a * this -> a; // квадратын талбайг буцаана
    }

    float perimeter() override // perimeter-г дахин тодорхойлно
    {
        return 4 * this -> a; // квадратын периметрийг буцаана
    }
};
#endif