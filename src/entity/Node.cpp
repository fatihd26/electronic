
#include "Node.h"

size_t NodeManager::id = 0;


size_t NodeManager::createNode(){
    return id++;
}