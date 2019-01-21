#include <SFML/Graphics.hpp>
#include "helpers.hpp"
#include <math.h>
#include <algorithm>
#include <cstdlib>

class Entity : public sf::CircleShape
{
public:
    double velocity;
    double radial_velocity;
    double mass;

    bool inertia = true;

    Entity() : sf::CircleShape(80.f, 3), velocity(0.f), radial_velocity(0.f), mass(0.f)
    {
    }

    void radial_accelerate(float amount)
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

    void inertiate(double inertial_damping, double radial_inertial_damping)
    {
        accelerate(-sign(velocity) * std::min(abs(velocity), inertial_damping));
        radial_accelerate(-sign(radial_velocity) * std::min(abs(radial_velocity), radial_inertial_damping));
    }

    void update()
    {
        float angle = getRotation() + 90.f;

        move(-velocity * cos(angle * 0.0174533), -velocity * sin(angle * 0.0174533));
        rotate(radial_velocity);
    }

};
