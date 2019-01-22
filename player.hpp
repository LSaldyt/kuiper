#include "ship.hpp"

class Player : public Ship
{
public:
    Player(sf::Texture& texture) : Ship()
    {
        setOrigin(sf::Vector2f(5.f, 5.f));

        Entity other;
        other.setTexture(texture);
        add(other, -10.f, -10.f);

        Entity other2;
        other2.setTexture(texture);
        add(other2, 0, 0);
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
