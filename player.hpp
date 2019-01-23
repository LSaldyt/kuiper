#include "ship.hpp"
#include "registry.hpp"

class Player : public Ship
{
public:
    Player(sf::Texture& texture) : Ship()
    {
        Entity base;
        base.setTexture(texture);

        auto bounds = base.getGlobalBounds();
        base.setOrigin(sf::Vector2f(bounds.width / 2.f, bounds.height / 2.f));
        add(base, 0, 0);
    }

    void update(Registry& registry)
    {
        Ship::update(registry);
    }

    void handle(int code, Registry& registry)
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
