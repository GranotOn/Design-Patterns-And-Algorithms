#include "Composite.cpp"
#include "iostream"


void clientCode(Box *simple) {
    std::cout << "(CLIENT)" << std::endl;
    std::cout << simple->Operation() << std::endl;
}

int main() {
    Box *simple = new Leaf;
    clientCode(simple);

    Box *tree = new Composite();
    Box *branch_1 = new Composite();
    Box *branch_2 = new Composite();

    tree->add(branch_1);
    tree->add(branch_2);

    clientCode(tree);

    Box *leaf_1 = new Leaf();
    Box *leaf_2 = new Leaf();
    Box *leaf_3 = new Leaf();

    branch_1->add(leaf_1);

    branch_2->add(leaf_1);
    branch_2->add(leaf_2);
    branch_2->add(leaf_3);

    clientCode(branch_1);

    delete simple;
    delete tree;
    delete branch_1;
    delete branch_2;
    delete leaf_1;
    delete leaf_2;
    delete leaf_3;
    return 0;
}