#include "Deque.hpp"
#include <string>
#include <stdexcept>

DequeDLL::DequeDLL() : head(nullptr), tail(nullptr), DequeSize(0) {}
DequeDLL::~DequeDLL()
{
    while (!empty())
    {
        popFront();
    }
}

bool DequeDLL::empty() const
{
    return DequeSize == 0;
}

size_t DequeDLL::size() const
{
    return DequeSize;
}

void DequeDLL::pushFront(const std::string &value)
{
    Node *newNode = new Node(value);
    if (empty())
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    DequeSize++;
}

void DequeDLL::pushBack(const std::string &value)
{
    Node *newNode = new Node(value);
    if (empty())
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    DequeSize++;
}

void DequeDLL::popFront()
{
    if (empty())
    {
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    else
        tail = nullptr;
    delete temp;
    DequeSize--;
}

void DequeDLL::popBack()
{
    if (empty())
    {
        return;
    }
    Node *temp = tail;
    tail = tail->prev;
    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;
    delete temp;
    DequeSize--;
}

std::string &DequeDLL::front() const
{
    if (empty())
    {
        throw std::out_of_range("Deque is empty. Cannot access front element.");
    }
    return head->data;
}

std::string &DequeDLL::back() const
{
    if (empty())
    {
        throw std::out_of_range("Deque is empty. Cannot access back element.");
    }
    return tail->data;
}