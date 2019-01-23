#include <SFML/Graphics.hpp>
#include "helpers.hpp"
#include "player.hpp"
#include "texturemap.hpp"
#include "registry.hpp"
#include <memory>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Kuiper", sf::Style::Fullscreen);
    sf::View view = window.getDefaultView();

    Registry registry;

    TextureMap map;
    map.loadAll("image.png");

    Player player(map["image"]);
    registry.add(player);
    
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
                registry.handle(event.key.code);
            }
        }

        registry.update();

        view.setCenter(player.getPosition());
        window.clear();

        window.draw(registry);
        window.draw(start);

        window.setView(view);
        window.display();
    }

    return 0;
}
