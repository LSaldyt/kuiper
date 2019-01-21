#include "ship.hpp"

class Player : public Ship
{
public:
    Player() : Ship()
    {
        setFillColor(sf::Color(100, 250, 50));
        setOrigin(sf::Vector2f(80.f, 80.f));
    }

    void handle(auto code)
    {
        if (code == sf::Keyboard::W)
        {
            forward();
        }
        if (code == sf::Keyboard::S)
        {
            backward();
        }
        if (code == sf::Keyboard::D)
        {
            right();
        }
        if (code == sf::Keyboard::A)
        {
            left();
        }
        if (code == sf::Keyboard::C)
        {
            stabilize_radial();
        }
        if (code == sf::Keyboard::X)
        {
            stop();
        }
        if (code == sf::Keyboard::Z)
        {
            slow();
        }
    }
};
