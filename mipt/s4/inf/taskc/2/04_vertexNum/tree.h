/*
 * Tree class
 */

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
    tNode node; // value in current vertex
    vector<Tree*> children; // children of current vertex
public:
    Tree();
    Tree(tNode); // set current value
    string printTree(unsigned level = 0); // prints tree (values & ptrs)
    ~Tree();
    void addChild(Tree* x);
    Tree* readCin();
};

#endif // TREE_H
