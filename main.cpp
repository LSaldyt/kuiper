#include <SFML/Graphics.hpp>
#include "helpers.hpp"
#include "player.hpp"
#include "texturemap.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Kuiper", sf::Style::Fullscreen);
    sf::View view = window.getDefaultView();

    TextureMap map;
    map.loadAll("image.png");

    Player player(map["image"]);
    //map["image"];
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
                player.handle(event.key.code);
            }
            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
                view = sf::View(visibleArea);
            }
        }

        player.update();

        view.setCenter(player.getPosition());
        window.setView(view);

        window.clear();
        window.draw(player);
        window.draw(start);
        window.display();
    }

    return 0;
}
