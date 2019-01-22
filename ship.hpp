#include "entity.hpp"
#include "composite.hpp"

#include <cstdlib>

class Ship : public Composite
{
    double inertial_damping = 0.1f;
    double radial_inertial_damping = 0.5f;
    double acceleration = 1.f;
    double radial_acceleration = .1f;

    double max_velocity = 3.f;
    double max_radial_velocity = .4f;

public:

    void forward()
    {
        if (velocity < max_velocity)
        {
            accelerate(1.f);
        }
    }

    void backward()
    {
        if (velocity > -max_velocity)
        {
            accelerate(-1.f);
        }
    }

    void right()
    {
        if (radial_velocity < max_radial_velocity)
        {
            radial_accelerate(radial_acceleration);
        }
    }

    void left()
    {
        if (radial_velocity > -max_radial_velocity)
        {
            radial_accelerate(-radial_acceleration);
        }
    }

    void slow()
    {
        inertiate(inertial_damping, radial_inertial_damping);
    }
};
