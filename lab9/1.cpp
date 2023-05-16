// 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template <class K,class V>
class Map
{
private:
    struct elements
    {
        K key;
        V value;
        int index;
        V operator=(const V& v)
        {
            value = v;
            return value;
        }
    };
    elements* e = new elements[3];
    int count=0;
    int nr = 2;
public:
    elements& operator[](const K& key)
    {
        for (int i = 0;i < count;i++)
            if (e[i].key == key)
                return e[i];
        V* aux = new V();
        Set(key, *aux);
            return e[count - 1];
    }
    void Set(const K& key, const V& value)
    {
        for (int i = 0;i < count;i++)
        {
            if (e[i].key == key)
            {
                e[i].value = value;
                return;
            }
        }
        if (nr == count)
        {
            nr = 2 * nr;
            elements* newE = new elements[nr + 1];
            for (int i = 0;i < count;i++)
                newE[i] = e[i];
            delete[] e;
            e = newE;
        }
        e[count++] = { key,value,count };
    }
    bool Get(const K& key, V& value)
    {
        for (int i = 0;i < count;i++)
        {
            if(e[i].key==key)
            {
                value = e[i].value;
                return true;
            }
        }
        return false;
    }
    int Count()
    {
        return count;
    }
    void Clear()
    {
        delete[] e;
        count = 0;
        nr = 2;
        elements* e = new elements[nr + 1];
    }
    bool Delete(const K& key)
    {
        for (int i = 0;i < count;i++)
        {
            if (e[i].key == key)
                delete e[i];
            return true;
        }
        return false;
    }
    bool Includes(const Map<K, V>& map)
    {
        
        for (int i = 0;i < this->count;i++)
        {
            int ok = 0;
          
            for (int j = 0;j < map.count;j++)
            if (ok == 0)
                return false;
        
        }
        return true;
       
    }
    elements* begin() const
    {
        return &e[0];
    }

    elements* end() const
    {
        return &e[count];
    }
};
int main()

{

    Map<int, const char*> m,a;

    m[10] = "C++";

    m[20] = "test";

    m[30] = "Poo";

    for (auto [key, value, index] : m)

    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }

    m[20] = "result";

    for (auto [key, value, index] : m)

    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }

    return 0;

}

