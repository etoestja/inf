#ifndef TREE_H
#define TREE_H

#include <vector>
#include <string>

using std::vector;
using std::string;

typedef int tNode;

class treeStupidCounter;
class treeThreadCounter;
class randomTree;

class Tree
{
friend class treeStupidCounter;
friend class treeThreadCounter;
friend class randomTree;

private:
    static const int maxChildren = 10;
    tNode node;
    vector<Tree*> children;
public:
    Tree();
    Tree(tNode);
    string printTree(unsigned level = 0);
};

#endif // TREE_H
