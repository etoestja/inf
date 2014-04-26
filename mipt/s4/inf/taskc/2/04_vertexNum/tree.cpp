#include "tree.h"
#include <sstream>
#include <iostream>

using std::stringstream;
using std::endl;
using std::cin;
using std::cerr;

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
    //ss << "ptr=" << this << " value=" << node << " children (" << children.size() << "):" << endl;
    ss << node << " " << children.size() << endl;

    vector<Tree*>::iterator it;
    for(it = children.begin(); it != children.end(); it++)
        ss << (*it)->printTree(level + 1);
    return(ss.str());
}

Tree::~Tree()
{
    vector<Tree*>::iterator it;
    for(it = children.begin(); it != children.end(); it++)
    {
        if((*it) != NULL)
        {
            //(*it)->~Tree();
            delete (*it);
        }
    }
}

void Tree::addChild(Tree *x)
{
    children.push_back(x);
}

Tree* Tree::readCin()
{
    cin >> node;

    unsigned N;
    cin >> N;

    for(unsigned i = 0; i < N; i++)
    {
        Tree* t = new Tree;
        t->readCin();
        addChild(t);
    }
    return(this);
}
