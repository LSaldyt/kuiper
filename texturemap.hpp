#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include "helpers.hpp"

class TextureMap
{
public:
    std::unordered_map<std::string, sf::Texture> map;

    template <typename T, typename... Args>
    void loadAll(T first, Args... args) 
    {
        loadAll(first);
        loadAll(args...);
    }

    template <typename T>
    void loadAll(T t) 
    {
        map.insert(std::make_pair(t, sf::Texture()));
        map[t].loadFromFile(std::string("resources/") + t);
    }

    sf::Texture& operator[] (std::string s) 
    {
        return map[s];
    }
};
