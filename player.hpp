#include "ship.hpp"

class Player : public Ship
{
public:
    void turn(float amount)
    {
        rotate(amount);
    }

    void accelerate(double amount)
    {
        velocity = velocity + amount;
    }

    void update()
    {
        move(0.f, 0.f);
    }

};
