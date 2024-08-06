// Nuva Shrestha
// Vaibhavi Patel
#ifndef DEQUEDLL_H
#define DEQUEDLL_H
#include <string>

class DequeDLL
{
private:
    struct Node // each node has a string data, previous pointer, next pointer
    {
        std::string data;
        Node *prev;
        Node *next;
        Node(const std::string &value) : data(value), prev(nullptr), next(nullptr) {}
    };
    Node *head;
    Node *tail;
    size_t DequeSize;

public:
    DequeDLL();
    ~DequeDLL();
    bool empty() const;
    size_t size() const;
    void pushFront(const std::string &value);
    void pushBack(const std::string &value);
    void popFront();
    void popBack();
    std::string &front() const;
    std::string &back() const;
};

#endif /* DEQUEDLL_H */