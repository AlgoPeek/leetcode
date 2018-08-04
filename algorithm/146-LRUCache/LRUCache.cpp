// Source: https://leetcode.com/problems/lru-cache/description/
// Author: Diego Lee
// Date: 2018-08-04
//
// Description:
// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
// Follow up:
// Could you do both operations in O(1) time complexity?
//
// Example:
//
// LRUCache cache = new LRUCache( 2 /* capacity */ );
//
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

#include <iostream>
#include <cassert>
#include <map>

struct Node
{
    int key;
    int value;
    Node* pre;
    Node* next;
    Node(int key, int value)
        : key(key), value(value), pre(NULL), next(NULL)
    {}
};

class LRUCache
{
    public:
        LRUCache(int capacity)
        {
            m_capacity = capacity;
            m_head = NULL;
            m_end = NULL;
        }

        int get(int key)
        {
            std::map<int, Node*>::iterator it = m_cache.find(key);
            if (it == m_cache.end())
            {
                return -1;
            }

            Node* node = it->second;
            assert(node != NULL);
            moveFront(node);
            return node->value;
        }

        void set(int key, int value)
        {
            std::map<int, Node*>::iterator it = m_cache.find(key);
            if (it != m_cache.end())
            {
                Node* node = it->second;
                node->value = value;
                moveFront(node);
            }
            else
            {
                if (m_cache.size() >= m_capacity)
                {
                    int key = m_end->key;
                    m_cache.erase(key);
                    popBack();
                }

                Node* node = new Node(key, value);
                assert(node != NULL);
                pushFront(node);
                m_cache[key] = node;
            }
        }

    private:
        void moveFront(Node* node)
        {
            assert(node != NULL);
            remove(node);
            pushFront(node);
        }

        void remove(Node* node)
        {
            if (NULL == m_head || NULL == node)
            {
                return ;
            }

            if (m_head == m_end && node == m_head)
            {
                m_head = NULL;
                m_end = NULL;
            }
            else if (node == m_head)
            {
                m_head->next->pre = NULL;
                m_head = m_head->next;
            }
            else if (node == m_end)
            {
                m_end->pre->next = NULL;
                m_end = m_end->pre;
            }
            else
            {
                node->pre->next = node->next;
                node->next->pre = node->pre;
            }
        }

        void pushFront(Node* node)
        {
            assert(node != NULL);

            if (NULL == m_head)
            {
                assert(NULL == m_end);
                m_head = node;
                m_end = node;
            }
            else
            {
                m_head->pre = node;
                node->next = m_head;
                m_head = node;
            }
        }

        void popBack()
        {
            Node* node = m_end;
            remove(node);
            if (node != NULL)
            {
                delete node;
            }
        }

    private:
        int m_capacity;
        std::map<int, Node*> m_cache;
        Node* m_head;
        Node* m_end;
};

void testLRUCache()
{
    LRUCache lru(3);
    for (int i = 0; i < 3; ++i)
    {
        int key = i + 1;
        int value = i + 1;
        lru.set(key, value);
        assert(value == lru.get(key));
    }

    lru.set(4, 4);
    assert(4 == lru.get(4));
    assert(-1 == lru.get(1));

    int value = lru.get(2);
    assert(2 == value);

    lru.set(5, 5);
    assert(5 == lru.get(5));
    assert(-1 == lru.get(3));
}

int main()
{
    testLRUCache();
    return 0;
}
