#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::merge;

class myClass
{
private:
    int data;
public:
    myClass()
    {
    }

    myClass(int x)
    {
        data = x;
    }

    bool operator<(myClass b)
    {
        return(data < b.data);
    }

    void print()
    {
        cout << data;
    }
};

bool comp(myClass a, myClass b)
{
    return(a < b);
}

void vMyClassPrint(vector<myClass> &a)
{
    vector<myClass>::iterator it;
    for(it = a.begin(); it != a.end(); it++)
    {
        (*it).print();
        cout << " ";
    }
    cout << endl;
}

vector<myClass> a, b, c;

//int main()
//{
//    a.push_back(0);
////    a.push_back(2);
////    a.push_back(4);
////    a.push_back(6);

//    b.push_back(1);
////    b.push_back(3);
////    b.push_back(5);
////    b.push_back(7);

//    vMyClassPrint(a);
//    vMyClassPrint(b);

//    c.reserve(a.size() + b.size());

//    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());

//    cout << "c size = " << c.size() << endl;

//    vMyClassPrint(c);

//    return(0);
//}

// merge algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::merge, std::sort
#include <vector>       // std::vector

int main () {
        a.push_back(0);
    //    a.push_back(2);
    //    a.push_back(4);
    //    a.push_back(6);

        b.push_back(1);
    //    b.push_back(3);
    //    b.push_back(5);
    //    b.push_back(7);
  std::vector<myClass> v(10);

  //std::sort(a.begin(), a.end(), comp);
  //std::sort(b.begin(), b.end(), comp);
  std::merge(a.begin(), a.end(),b.begin(),b.end(),v.begin());

  std::cout << "The resulting vector contains:";
  for (std::vector<myClass>::iterator it=v.begin(); it!=v.end(); ++it)
  {
    std::cout << ' ';
    (*it).print();
  }
  std::cout << '\n';

  return 0;
}
