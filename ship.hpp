#include <SFML/Graphics.hpp>
#include "helpers.hpp"
#include <math.h>
#include <algorithm>
#include <cstdlib>

class Ship : public sf::CircleShape
{
public:
    double velocity;
    double radial_velocity;
    double inertial_damping = 0.1f;
    double radial_inertial_damping = 0.5f;

    bool inertia = true;

    Ship() : sf::CircleShape(80.f, 3)
    {
    }

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

    void slow()
    {
        accelerate(-sign(velocity) * std::min(abs(velocity), inertial_damping));
        turn(-sign(radial_velocity) * std::min(abs(radial_velocity), radial_inertial_damping));
    }

    void update()
    {
        float angle = getRotation() + 90.f;

        move(-velocity * cos(angle * 0.0174533), -velocity * sin(angle * 0.0174533));
        rotate(radial_velocity);
    }

};
