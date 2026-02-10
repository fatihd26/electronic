#ifndef NODE_H
#define NODE_H

class NodeManager{
    public:
        NodeManager();
        size_t createNode();

    private:
        static size_t node_id;

};

#endif