#include "tree.h"
#include <sstream>
#include <iostream>

using std::stringstream;
using std::endl;

Tree::Tree()
{
}

Tree::Tree(tNode _node)
{
    node = _node;
}

string Tree::printTree(unsigned level)
{
    stringstream ss;
    for(unsigned i = 0; i < level; i++)
        ss << " ";
    ss << "ptr=" << this << " value=" << node << " children (" << children.size() << "):" << endl;

    vector<Tree*>::iterator it;
    for(it = children.begin(); it != children.end(); it++)
        ss << (*it)->printTree(level + 1);
    return(ss.str());
}
