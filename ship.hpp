#include <SFML/Graphics.hpp>

class Ship : public sf::CircleShape
{
public:
    double velocity;
    double radial_velocity;

    Ship() : sf::CircleShape(80.f, 3)
    {
    }
};
