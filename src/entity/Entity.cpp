
#include "Entity.h"

size_t EntityManager::id = 0;


size_t EntityManager::createEntity(){
    return id++;
}

size_t EntityManager::getID(){
    return id;
}