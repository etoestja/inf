#include <iostream>
#include <trie.h>
#include <string>
#include <QDebug>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main()
{
    unsigned int N;
    Trie* myTrie = new Trie(NULL); // root
    string t, t1;

    N = 100;
    string a;

	char aa[2];

    for(unsigned i = 0; i < N; i++)
    {
	aa[0] = 'a' + (i % 10);
	aa[1] = 0;
	a.append(aa);
        //cin >> t;
        myTrie->insert((unsigned char*) a.c_str());
    }
    myTrie->update();
    qDebug() << myTrie->print().c_str();

    myTrie->find(t);


//    myTrie->insert((char *) "abacaba");
//    myTrie->insert((char *) "ba");
//    myTrie->insert((char *) "aba");
//    myTrie->insert((char *) "a");
//    //myTrie->insert((char *) "bacaba");
//    //myTrie->insert((char *) "abcdefghijklmnopqrs");
//    //myTrie->insert((char *) "bcdefghijklmnopqrs");
//    myTrie->calcPi();
//    cout << myTrie->print();

//    myTrie->find("abacaba");
    return 0;
}
