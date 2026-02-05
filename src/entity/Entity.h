#ifndef ENTITY_H
#define ENTITY_H

class EntityManager{
    private:
        static size_t id;
    public:
        size_t createEntity();
        size_t getID();
};

#endif