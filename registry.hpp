#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <unordered_map>
#include <string>

#include "composite.hpp"
#include "entity.hpp"

class Registry : public sf::Drawable
{
public:
    std::vector<std::shared_ptr<Composite>> queue;
    std::vector<std::shared_ptr<Composite>> items;
    std::unordered_map<std::string, int> map;
    std::unordered_map<int, std::string> names;

    std::shared_ptr<Composite> operator[] (std::string s) 
    {
        return items[map[s]];
    }

    void update()
    {
        if (queue.size() > 0)
        {
            items.insert(items.end(), queue.begin(), queue.end());
            queue.clear();
        }
        for (auto& item : items)
        {
            item->update(*this);
        }
    }

    void add(std::shared_ptr<Composite> entity)
    {
        queue.push_back(entity);
        print("Added");
    }

    void add(std::shared_ptr<Composite> entity, std::string name)
    {
        map.insert(std::make_pair(name, items.size()));
        names.insert(std::make_pair(items.size(), name));
        add(entity);
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        for (auto& item : items)
        {
            item->draw(target, states);
        }
    }

    void handle(int code, std::shared_ptr<Registry> registry)
    {
        int i = 0;
        for (auto& item : items)
        {
            print("Began Item Handling", i);
            if (names.find(i) != names.end())
            {
                print(names[i]);
            }
            print("Item location:");
            print(item.get());
            print("End Item Location");
            item->handle(code, registry);
            print("Finished Item Handling");
            i++;
        }
        print("Finished Registry Handling");
    }
};
