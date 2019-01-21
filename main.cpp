#include <SFML/Graphics.hpp>
#include "helpers.hpp"
#include "player.hpp"
#include "texturemap.hpp"

int main()
{
    sf::View view(sf::Vector2f(0.f, 0.f), sf::Vector2f(2000.f, 2000.f));
    sf::RenderWindow window(sf::VideoMode(2000, 2000), "Kuiper", sf::Style::Fullscreen);

    TextureMap map;
    map.loadAll("image.png");

    Player player;
    player.setFillColor(sf::Color(100, 250, 50));
    player.setOrigin(sf::Vector2f(80.f, 80.f));
    //player.setTexture(map["image.png"]);
    
    sf::CircleShape start(10.f);
    start.setFillColor(sf::Color(255, 0, 0));

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
                    player.accelerate(1.f);
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    player.accelerate(-1.f);
                }
                if (event.key.code == sf::Keyboard::D)
                {
                    player.turn(.5f);
                }
                if (event.key.code == sf::Keyboard::A)
                {
                    player.turn(-.5f);
                }
                if (event.key.code == sf::Keyboard::C)
                {
                    player.stabilize_radial();
                }
                if (event.key.code == sf::Keyboard::X)
                {
                    player.stop();
                }
                if (event.key.code == sf::Keyboard::Z)
                {
                    player.slow();
                }
            }
        }

        player.update();

        window.setView(view);

        window.clear();
        window.draw(player);
        window.draw(start);
        window.display();
    }

    return 0;
}
