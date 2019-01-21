#include "entity.hpp"

class Ship : public Entity
{
    double inertial_damping = 0.1f;
    double radial_inertial_damping = 0.5f;
    double acceleration = 1.f;
    double radial_acceleration = .5f;

public:

    void forward()
    {
        accelerate(1.f);
    }

    void backward()
    {
        accelerate(-1.f);
    }

    void right()
    {
        radial_accelerate(radial_acceleration);
    }

    void left()
    {
        radial_accelerate(-radial_acceleration);
    }

    void slow()
    {
        inertiate(inertial_damping, radial_inertial_damping);
    }
};
