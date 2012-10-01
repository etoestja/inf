#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::stringstream;
using std::string;

using std::vector;
using std::deque;
using std::queue;

unsigned int base = 10;
typedef unsigned short d_t;
typedef unsigned long long int n_t;

n_t pow_int(n_t a, n_t b)
{
    n_t r = 1, i;
    for(i = 0; i < b; i++) r *= a;
    return(r);
}

class long_
{
    private:
    deque<d_t> number;

    public:
    long_()
    {
        number.clear();
    }

    void append(d_t d)
    {
        number.push_back(d);
    }

    string print()
    {
        stringstream ss;
        deque<d_t>::iterator it;
        for(it = number.begin(); it != number.end(); it++) ss << (*it);
        return(ss.str());
    }

    n_t regular()
    {
        n_t res = 0;
        n_t position = 0;

        deque<d_t>::reverse_iterator rit;
        for(rit = number.rbegin(); rit != number.rend(); rit++)
            res += (*rit) * pow_int(base, position++);

        return(res);

    }

    bool operator>=(n_t a)
    {
        if(number.size() > 15) return(1);
        else return(this->regular() >= a);
    }

    bool operator<(n_t a)
    {
        if(number.size() > 15) return(0);
        else return(this->regular() < a);
    }

    bool operator==(n_t a)
    {
        if(number.size() > 15) return(0);
        else return(this->regular() == a);
    }

    unsigned int size()
    {
        return(number.size());
    }

    bool operator%(n_t a)
    {
        if((*this) < a) return(1);
        else if((*this) == a) return(0);
        long_ t_num = *this, t_num1, res;
        n_t r = 0, l = 0;

        while(t_num >= a)
        {
            //cerr << "dividing " << t_num.print() << " by " << a << endl;
            for(t_num1.number.clear(); t_num1 < a; t_num.number.pop_front())
                t_num1.number.push_back(t_num.number.front());
            //cerr << "got " << t_num1.print() << endl;

            r = t_num1.regular() / a;
            l = t_num1.regular() % a;

            //cerr << "r=" << r << " l=" << l << endl;

            if(l) t_num.number.push_front(l);
            res.number.push_back(r);
        }

        //cout << res.print() << endl;
        //cout << t_num.print();
        return(t_num.number.size());
    }
};

const unsigned int DIG = 10;
bool allowed[DIG];

int main()
{
    long_ X;
    n_t k, D, i, t;
    for(i = 0; i < DIG; i++) allowed[i] = 0;

    char c;
    for(c = cin.get(); c >= '0' && c <= '9'; c = cin.get()) X.append(c - '0');

    cin >> k >> D;

    for(i = 0; i < D; i++)
    {
        cin >> t;
        allowed[t] = 1;
    }

    queue<long_> q;
    long_ t_long = X, t_long_;
    q.push(t_long);

    unsigned int max_size = X.size();

    bool found = false;

    while(!q.empty())
    {
        t_long = q.front();
        q.pop();

        if(t_long % k == 0)
        {
            found = 1;
            cout << t_long.print() << endl;
            break;
        }

        if(t_long.size() + 1 > max_size)
        {
            max_size = t_long.size() + 1;
            cout << max_size << endl;
        }

        for(i = 0; i < DIG; i++)
        {
            if(allowed[i])
            {
                t_long_ = t_long;
                t_long_.append(i);
                q.push(t_long_);
            }
        }
    }

    if(!found) cout << "-1" << endl;

    return 0;
}
