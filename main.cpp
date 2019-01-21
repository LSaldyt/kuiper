#include <SFML/Graphics.hpp>
#include "helpers.hpp"
#include "player.hpp"
#include "texturemap.hpp"

int main()
{
    TextureMap map;
    map.loadAll("image.png");
    sf::View view2(sf::Vector2f(0.f, 0.f), sf::Vector2f(2000.f, 2000.f));

    Player player;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Kuiper", sf::Style::Fullscreen);
    player.setTexture(map["image.png"]);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::W)
                {
                    player.accelerate(5.f);
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    player.accelerate(-5.f);
                }
                if (event.key.code == sf::Keyboard::D)
                {
                    player.turn(5.f);
                }
                if (event.key.code == sf::Keyboard::A)
                {
                    player.turn(-5.f);
                }
            }
        }

        //view2.setCenter(player.getPosition());
        window.setView(view2);

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}
