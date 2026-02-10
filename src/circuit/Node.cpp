#include "Node.h"

NodeManager::NodeManager(){
    node_id = 0;
}

size_t NodeManager::createNode(){
    return node_id++;

}