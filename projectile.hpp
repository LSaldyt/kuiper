#include "composite.hpp"

class Projectile : public Composite
{
    Projectile(double initial, double heading)
    {
        accelerate(initial);
        setRotation(heading);
    }
};
