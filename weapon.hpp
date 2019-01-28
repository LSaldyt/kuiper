#pragma once
#include "projectile.hpp"
#include "composite.hpp"
#include "registry.hpp"

class Weapon : public Composite
{
    public:
    void shoot(std::shared_ptr<Registry> registry) 
    {
        registry->add(std::make_shared<Projectile>(getPosition(), 5, getRotation()), "Projectile");
    }
};
