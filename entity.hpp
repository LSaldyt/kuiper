#pragma once
#include <SFML/Graphics.hpp>
#include "helpers.hpp"
#include <math.h>
#include <algorithm>
#include <cstdlib>

class Registry;

class Entity : public sf::Sprite
{
public:
    unsigned int id;
    double velocity;
    double radial_velocity;
    double mass;

    bool inertia = true;

    Entity() : velocity(0.f), radial_velocity(0.f), mass(0.f)
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

    void update(Registry& registry)
    {
        float angle = getRotation() + 90.f;

        move(-velocity * cos(angle * 0.0174533), -velocity * sin(angle * 0.0174533));
        rotate(radial_velocity);
    }

};
