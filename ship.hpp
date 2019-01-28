#include "entity.hpp"
#include "composite.hpp"
#include "weapon.hpp"

#include <cstdlib>

class Ship : public Composite
{
    std::vector<std::shared_ptr<Weapon>> weapons;

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

    void add_weapon(Weapon weapon, double x, double y)
    {
        auto weapon_ptr = std::make_shared<Weapon>(weapon);
        auto& position = getPosition();
        weapon_ptr->setPosition(position.x + x, position.y + y);
        double distance = sqrt(x * x + y * y);
        double angle = std::atan2(y, x) * 57.2958;
        children.push_back(std::make_tuple(distance, angle, weapon_ptr));
        weapons.push_back(weapon_ptr);
    }


    void shoot(std::shared_ptr<Registry> registry) 
    {
        for (auto& weapon : weapons)
        {
            weapon->shoot(registry);
        }
    }
};
