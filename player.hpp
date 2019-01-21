#include "ship.hpp"
#include "helpers.hpp"
#include <math.h>

class Player : public Ship
{
public:
    void turn(float amount)
    {
        radial_velocity = radial_velocity + amount;
    }

    void accelerate(double amount)
    {
        velocity = velocity + amount;
    }

    void stabilize_radial()
    {
        radial_velocity = 0.f;
    }

    void stop()
    {
        velocity = 0.f;
    }

    void update()
    {
        float angle = getRotation() + 90.f;
        move(-velocity * cos(angle * 0.0174533), -velocity * sin(angle * 0.0174533));
        rotate(radial_velocity);
    }

};
