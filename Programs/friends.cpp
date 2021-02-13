#include "iostream"

class Node
{
private:
    int key;
    Node *next;

public:
    Node(int key) : key(key) {}
    friend class NodeFriend;
};

class NodeFriend
{
private:
    int key;

public:
    NodeFriend(int key) : key(key) {}
    void showNodeKey(Node &node)
    {
        std::cout << "Node::key = " << node.key << std::endl;
    }
    friend void showFriendNodeKey(NodeFriend &nodeFriend);
};

void showFriendNodeKey(NodeFriend &nodeFriend)
{
    std::cout << "NodeFriend::key = " << nodeFriend.key << std::endl;
}

int main()
{
    Node *node = new Node(50);
    NodeFriend *nodeFriend = new NodeFriend(60);

    nodeFriend->showNodeKey(*node); // Should display node's key (50)

    showFriendNodeKey(*nodeFriend); // Should display nodeFriend's key (60);
    return 0;
}