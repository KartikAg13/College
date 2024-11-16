#include <iostream>
using namespace std;

class hashMap{
    int capacity;
    int* mapp;
    public:
    hashMap(int cap){
        this->capacity = cap;
        this->mapp = new int[cap];
    }
    int hashFunction(int num)
    {
        return num % capacity;
    }
    void insertInto(int num){
        int key = hashFunction(num);
        int probe = 0;
        while(mapp[key] != 0)
        {
            probe++;
            key = hashFunction(num + probe);
        }
        mapp[key] = num;
    }
    void display(){
        for(int i = 0; i < capacity; i++)
        {
            cout << mapp[i] << endl;
        }
    }
    bool val(int value){
        int probe = -1;
        int index = -1;
        while(value != mapp[index] || index == -1)
        {
            probe++;
            if(probe == capacity)
                return false;
            index = hashFunction(value + probe);
            if(mapp[index] == value)
                return true;
        }
        return false;
    }
};

int main()
{
    hashMap *map = new hashMap(10);
    map->insertInto(10);
    map->insertInto(100);
    map->display();
    cout << "Found: " << map->val(100) << endl;
    return 0;
}
