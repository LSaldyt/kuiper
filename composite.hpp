#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <tuple>

#include "entity.hpp"

class Registry;
class Composite;

using Component = std::tuple<double, double, std::shared_ptr<Entity>>;

class Composite : public Entity
{
public:

    std::vector<Component> children;
    sf::CircleShape marker;

    Composite() : Entity(), marker(30.f, 3)
    {
        marker.setOrigin(30.f, 30.f);
        marker.setFillColor(sf::Color(255, 255, 255));
    }

    void update(Registry& registry)
    {
        for (auto& child : children)
        {
            double distance = std::get<0>(child);
            double angle    = std::get<1>(child);
            auto& child_entity    = std::get<2>(child);
            child_entity->update(registry);
        }
        Entity::update(registry);
        marker.setPosition(getPosition());
        marker.setRotation(getRotation());
    }

    void move(float x, float y)
    {
        for (auto& child : children)
        {
            double child_x_offset = std::get<0>(child);
            double child_y_offset = std::get<1>(child);
            auto& child_entity    = std::get<2>(child);
            child_entity->move(x, y);
        }
        Entity::move(x, y);
    }

    void rotate(float amount)
    {
        for (auto& child : children)
        {
            double child_x_offset = std::get<0>(child);
            double child_y_offset = std::get<1>(child);
            auto& child_entity    = std::get<2>(child);
            child_entity->rotate(amount);
        }
        Entity::rotate(amount);
    }

    void accelerate(float amount)
    {
        for (auto& child : children)
        {
            double child_x_offset = std::get<0>(child);
            double child_y_offset = std::get<1>(child);
            auto& child_entity    = std::get<2>(child);
            child_entity->accelerate(amount);
        }
        Entity::accelerate(amount);
    }

    void radial_accelerate(float amount)
    {
        for (auto& child : children)
        {
            double child_x_offset = std::get<0>(child);
            double child_y_offset = std::get<1>(child);
            auto& child_entity    = std::get<2>(child);
            child_entity->radial_accelerate(amount);
        }
        Entity::radial_accelerate(amount);
    }

    void add(Composite composite, double x, double y)
    {
        add(std::make_shared<Composite>(composite), x, y);
    }

    void add(Entity entity, double x, double y)
    {
        add(std::make_shared<Entity>(entity), x, y);
    }

    void add(std::shared_ptr<Entity> entity_type, double x, double y)
    {
        auto& position = getPosition();
        entity_type->setPosition(position.x + x, position.y + y);
        double distance = sqrt(x * x + y * y);
        double angle = std::atan2(y, x) * 57.2958;
        children.push_back(std::make_tuple(distance, angle, entity_type));
    }

    virtual void handle(int code, std::shared_ptr<Registry> registry) 
    {
        print("Base handler");
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        auto& position = getPosition();
        auto& origin   = getOrigin();

        for (auto& child : children)
        {
            double distance = std::get<0>(child);
            double angle    = std::get<1>(child);
            double totalAngle = angle + getRotation();
            auto& child_entity    = std::get<2>(child);
            child_entity->setPosition(origin.x + position.x - distance * cos(totalAngle * 0.0174533), 
                                      origin.y + position.y - distance * sin(totalAngle * 0.0174533));
            target.draw(*child_entity);
        }
        target.draw(marker);
    }
};
