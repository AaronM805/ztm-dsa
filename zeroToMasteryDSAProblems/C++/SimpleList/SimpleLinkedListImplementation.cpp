// DS_alg_course_linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node* next;
  Node(int value) : value{ value }, next{ nullptr } {}
};
struct LinkedList
{
  int length;
  Node* head;
  Node* tail;
  LinkedList(int x) : length{ 1 }
  {
    // at first head will be this
    // tail will be head because we will have only one element
    head = new Node(x);
    tail = head;
  }

  void append(int value)
  {
    Node* newItem = new Node(value);
    tail->next = newItem;
    tail = tail->next;
    length++;
  }

  void prepend(int value)
  {
    Node* newItem = new Node(value);
    newItem->next = head;
    head = newItem;
    length++;
  }

  Node* getNodeByPos(int index)
  {
    Node* node = head;
    int counter = 0;
    while (counter < index)
    {
      node = node->next;
      counter++;
      if (node == nullptr)
      {
        break;
      }
    }
    return node;
  }

  void insert(int pos, int value)
  {
    if (pos == 0)
    {
      prepend(value);
    }
    // if position is >= length then insert as tail
    else if (pos >= length)
    {
      append(value);
    }
    else
    {
      Node* beforeNode = getNodeByPos(pos - 1);
      Node* afterNode = beforeNode->next;
      Node* newItem = new Node(value);
      beforeNode->next = newItem;
      newItem->next = afterNode;
      length++;
    }
  }

  void popHead()
  {
    Node* temp = head;
    head = head->next;
    delete temp;
    length--;
  }

  void popTail()
  {
    // length - 1 last elemet
    // length - 2 penultimate element
    Node* beforeNode = getNodeByPos(length - 2);
    Node* temp = tail;
    tail = beforeNode;
    tail->next = nullptr;
    delete temp;
    length--;
  }

  void remove(int pos)
  {
    if (pos == 0)
    {
      popHead();
    }
    else if (pos >= length)
    {
      popTail();
    }
    else
    {
      Node* beforeNode = getNodeByPos(pos - 1);
      Node* removeNode = beforeNode->next;
      Node* afterNode = removeNode->next;
      beforeNode->next = afterNode;
      delete removeNode;
      length--;
    }
  }

  void printList()
  {
    Node* node = head;
    while (node)
    {
      cout << node->value << " ";
      node = node->next;
    }
    cout << endl;
    cout << "List length: " << length << endl;
  }

};

int main()
{
  LinkedList* myLinkedList = new LinkedList(10);
  myLinkedList->append(5);
  myLinkedList->append(16);
  myLinkedList->prepend(30);
  myLinkedList->prepend(45);
  myLinkedList->insert(2, 500);
  myLinkedList->insert(myLinkedList->length, 501);
  myLinkedList->insert(0, 502);
  myLinkedList->insert(4, 540);
  myLinkedList->printList();
  myLinkedList->remove(2);
  myLinkedList->printList();
  myLinkedList->remove(myLinkedList->length);
  myLinkedList->printList();
}