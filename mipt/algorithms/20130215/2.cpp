#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::min;
using std::endl;

int zf[100];

int main()
{
    string s;
    cin>>s;

    //Здесь мы будем хранить
    //координаты самого длинного
    //отрезка, который совпадает с
    //началом нашей строки
    int r=-1,l=-1;

    //Запускаем цикл для прохождения по строке
    for(int i=1; i<s.size(); ++i)
    {
            //Проверяем, если ячейка для
            //которой мы ищем ответ
            //находится в отрезке между
            //l и r
            if(i<=r)
            {
                    /*
                    Это означает, что у нас уже есть
                    такая же ячейка для которой мы искали ответ
                    */
                    zf[i]=min(r-i+1,zf[i-l]);
            }
            //Теперь пользуемся тривиальным алгоритмом
            while(s[zf[i]]==s[zf[i]+i])
            zf[i]++;
            //И обновляем границы нашей подстроки
            if(i+zf[i]-1>r)
            {
                          l=i;
                          r=i+zf[i]-1;
            }
    }

    int x = 0;
    //Выводим ответ на экран
    for(int i = 0; i < s.size(); i++) cout << i << "\t";
    cout << endl;
    for(int i=0; i<s.size(); ++i)
    {
        cout << zf[i] << "\t";
        if(zf[i] == (s.size() - i) && x == 0)
            x = i;
    }

    cout << endl;

    cout << "period: (" << x << ") " << s.substr(0, x) << endl;

    return(0);
}
