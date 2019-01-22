#include <vector>
#include <memory>

class Registry
{
public:
    std::vector<shared_ptr<Entity>> entities;

    Registry()
    {
    }

    void update()
    {
        for (auto& item : entities)
        {
            item->update();
        }
    }

    void add(shared_ptr<Entity> entity)
    {
        entities.push_back(entity);
    }

    void add(Entity entity)
    {
        add(std::make_shared(entity));
    }
}
