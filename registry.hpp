#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "composite.hpp"
#include "entity.hpp"

class Registry : public sf::Drawable
{
public:
    std::vector<std::shared_ptr<Composite>> items;

    void update()
    {
        for (auto& item : items)
        {
            item->update(*this);
        }
    }

    template <typename T>
    void add(T entity)
    {
        items.push_back(std::make_shared<T>(entity));
    }

    void add(std::shared_ptr<Composite> entity)
    {
        items.push_back(entity);
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        for (auto& item : items)
        {
            item->draw(target, states);
        }
    }

    void handle(int code)
    {
        for (auto& item : items)
        {
            item->handle(code, *this);
        }
    }
};
