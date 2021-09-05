#include <iostream>

using namespace std;

template <class T>
class myVector
{
private:
    T* mass;
    size_t len;
    size_t reserveLen;
public:
    myVector();
    myVector(size_t s);
    myVector(size_t s, T data);
    void push_back(T data);
    void pop_back();
    void reserve(size_t s);
    size_t size(){return len;};
    T& operator [](size_t c);

};

template <class T>
myVector<T>::myVector()
{
    mass = nullptr;
    len = 0;
    reserveLen = 0;
}


template <class T>
myVector<T>::myVector(size_t s)
{
    len = s;
    reserveLen = s;
    mass = new T[reserveLen];
}

template <class T>
myVector<T>::myVector(size_t s, T data)
{
    len = s;
    reserveLen = s;
    mass = new T[reserveLen];
    for(size_t i = 0; i < s; i++)
    {
        mass[i] = data;
    }
}

template <class T>
T& myVector<T>::operator [](size_t c)
{
    if(c >= len)
    {
        throw " c >= len";
    }
    return mass[c];
}

template <class T>
void myVector<T>::push_back(T data)
{
    if(len < reserveLen)
    {
        ++len;
        mass[len- 1] = data;
    }
    else
    {
        T* newMass = new T[reserveLen + 1];
        reserveLen++;
        for(size_t i = 0; i < len; i++)
        {
            newMass[i] = mass[i];
        }
        newMass[len] = data;
        len++;
        delete mass;
        mass = newMass;
    }
    return;
}

template <class T>
void myVector<T>::pop_back()
{
    len--;
    return;
}

template <class T>
void myVector<T>::reserve(size_t s)
{
    if(s < len)
    {
        throw "error reserve < size";
    }
    else
    {
        T* newMass = new T[s];
        reserveLen = s;
        for(size_t i = 0; i < len; i++)
        {
            newMass[i] = mass[i];
        }
        delete mass;
        mass = newMass;
    }
    return;
}

int main()
{
    myVector<double> vect;
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.pop_back();
    vect[1] = 54;
    cout << vect[1] << " " << vect.size();

    return 0;
}
