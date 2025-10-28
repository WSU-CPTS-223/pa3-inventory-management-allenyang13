#pragma once
#include <functional>


template<typename Key, typename Value>
class HashTable 
{
private:
    struct Node
    {
        Key _key;
        Value _value;

        Node *pNext;
        Node(const Key &key, const Value &value) : _key(key), _value(value), pNext(nullptr) {};
    };

    Node **hashTable;
    size_t max;

    size_t hashFunction(const Key& key) const
    {
        return std::hash<Key>()(key) % max;
    }

public:
    HashTable(size_t size = 10007) : max(size)
    {
        hashTable = new Node *[max];
        for (size_t i = 0; i < max; i++)
        {
            hashTable[i] = nullptr;
        }
    }

    ~HashTable()
    {
        for (size_t i = 0; i < max; i++)
        {
            Node *pCur = hashTable[i];

            while(pCur)
            {
                Node *pTemp = pCur;
                pCur = pCur->pNext;
                delete pTemp;
            }
        }

        delete[] hashTable;
    }

    void insert(const Key& key, const Value& value)
    {
        size_t index = hashFunction(key);
        Node *pCur = hashTable[index];

        while (pCur)
        {
            if (pCur->_key == key)
            {
                pCur->_value = value;
                return;
            }

            pCur = pCur->pNext;
        }

        Node *newNode = new Node(key, value);
        newNode->pNext = hashTable[index];
        hashTable[index] = newNode;
    }

    Value* find(const Key& key)
    {
        size_t index = hashFunction(key);
        Node *pCur = hashTable[index];

        while(pCur)
        {
            if (pCur->_key == key)
            {
                return &pCur->_value;
            }
            pCur = pCur->pNext;
        }

        return nullptr;
    }

    template <typename Function>
    void functionCallAll(Function function) 
    {
        for (size_t i = 0; i < max; i++)
        {
            Node *pCur = hashTable[i];
            while (pCur)
            {
                function(pCur->_key, pCur->_value);
                pCur = pCur->pNext;
            }
        }
    }
};