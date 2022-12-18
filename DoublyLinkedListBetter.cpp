#include <iostream>
#include <string>

using namespace std;

struct Node {
  string data;
  Node* next;
  Node* prev;

  Node(string data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class List {
 private:
  Node* sentinel;

 public:
  List() {
    sentinel = new Node("");
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
  }

  ~List() {
    clean();
    delete sentinel;
  }

  void init_list() {
    // Lista jest już zainicjalizowana w konstruktorze, więc ta operacja nie jest potrzebna
  }

  void add(string data) {
    Node* newNode = new Node(data);
    newNode->prev = sentinel->prev;
    newNode->next = sentinel;
    sentinel->prev->next = newNode;
    sentinel->prev = newNode;
  }

  void print() {
    cout << "[";
    for (Node* current = sentinel->next; current != sentinel; current = current->next) {
      cout << current->data << ", ";
    }
    cout << "]" << endl;
  }

  bool search(string data) {
    for (Node* current = sentinel->next; current != sentinel; current = current->next) {
      if (current->data == data) {
        cout << "True" << endl;
        return true;
      }
    }
    cout << "False" << endl;
    return false;
  }

  void remove(string data) {
    string testt = "n";
    for (Node* current = sentinel->next; current != sentinel; current = current->next) {
      if (current->data == data) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        testt = "y";
        return;
      }
    }
    if (testt == "n") {
        cout << ("Error remove") << endl;

  }

  void clean() {
    Node* current = sentinel->next;
    while (current != sentinel) {
      Node* next = current->next;
      delete current;
      current = next;
    }
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
  }

  void non_repeated() {
    for (Node* current = sentinel->next; current != sentinel; current = current->next) {
      string data = current->data;
      Node* next = current->next;
      while (next != sentinel) {
        if (next->data == data) {
          next->prev->next = next->next;
          next->next->prev = next->prev;
          delete next;
          next = current->next;
        } else {
          next = next->next;
        }
      }
    }
  }

  void merge(List& other) {
    for (Node* current = other.sentinel->next; current != other.sentinel; current = current->next) {
      add(current->data);
    }
    other.clean();
}
};

int main() {
List list;
list.add("ala");
list.add("ma");
list.add("kota");
list.add("a");
list.add("kot");
list.add("ma");
list.add("ale");

list.print();

list.search("kota");
list.search("pies");

list.remove("ma");
list.print();

list.non_repeated();
list.print();

List list2;
list2.add("jest");
list2.add("piękny");
list2.add("dzień");

list.merge(list2);
list.print();

list.clean();
list.print();

return 0;
}
