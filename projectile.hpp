#include <SFML/Graphics.hpp>
#include "composite.hpp"

class Projectile : public Composite
{
public:
    Projectile(sf::Vector2f position, double initial, double heading)
    {
        setPosition(position);
        accelerate(initial);
        setRotation(heading);
    }

    virtual void handle(int code, std::shared_ptr<Registry> registry) 
    {
        print("Projectile handler");
    }
};
