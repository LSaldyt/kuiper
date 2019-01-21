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
        std::string full(t);
        std::string name = full.substr(0, full.find("."));
        map.insert(std::make_pair(name, sf::Texture()));
        map[name].loadFromFile(std::string("resources/") + full);
    }

    sf::Texture& operator[] (std::string s) 
    {
        return map[s];
    }
};
