#include "ship.hpp"
#include "helpers.hpp"
#include <math.h>

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
        float angle = getRotation() + 90.f;
        print(angle);
        move(-velocity * cos(angle * 0.0174533), -velocity * sin(angle * 0.0174533));
    }

};
