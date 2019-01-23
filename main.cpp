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

    std::shared_ptr<Registry> registry = std::make_shared<Registry>();

    TextureMap map;
    map.loadAll("image.png");

    registry->add(std::make_shared<Player>(map["image"]), "Player");
    
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
                print("Handling");
                registry->handle(event.key.code, registry);
                print("Handling Finished");
            }
        }

        print("Updating");
        registry->update();

        view.setCenter((*registry)["Player"]->getPosition());
        window.clear();

        print("Drawing");
        window.draw(*registry);
        window.draw(start);

        window.setView(view);
        print("Displaying");
        window.display();
    }

    return 0;
}
