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

    cin >> N;

    for(unsigned i = 0; i < N; i++)
    {
        cin >> t;
        myTrie->insert((unsigned char*) t.c_str());
    }
    myTrie->update();
    qDebug() << myTrie->print().c_str();

    t = "";
    while(cin >> t1)
    {
        t += " ";
        t += t1;
    }

    vector< pair<unsigned, string> > resVec;
    resVec = myTrie->find(t);

    cout << t << endl;

    vector< pair<unsigned, string> >::iterator it;
    for(it = resVec.begin(); it != resVec.end(); it++)
        cout << "pattern [" << (*it).second << "]" << " at " << (*it).first << endl;


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
