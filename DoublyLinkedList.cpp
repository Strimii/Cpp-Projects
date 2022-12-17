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

struct LinkedList {
    Node* head;
    Node* tail;

    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void init_list() {
        this->head = new Node("dummy");
        this->tail = new Node("dummy");
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    void add(string data) {
        Node* newNode = new Node(data);
        newNode->prev = this->tail->prev;
        newNode->next = this->tail;
        this->tail->prev->next = newNode;
        this->tail->prev = newNode;

    }

    void print() {
        cout << "[";
        for (Node* node = this->head->next; node != this->tail; node = node->next) {
            cout << node->data << ", ";
        }
        cout << "]" << endl;

    }

    bool search(string data) {
        for (Node* node = this->head->next; node != this->tail; node = node->next) {
            if (node->data == data) {
                cout << "True" << endl;
                return true;
            }
        }
        cout << "False" << endl;
        return false;
    }

    void remove(string data) {
        string testt = "n";
        for (Node* node = this->head->next; node != this->tail; node = node->next) {
            if (node->data == data) {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                delete node;
                testt = "y";
                break;
            }
        }
        if (testt == "n") {
            cout << ("Error remove") << endl;

        }
    }

    void clean() {
        Node* node = this->head->next;
        while (node != this->tail) {
            Node* next = node->next;
            delete node;
            node = next;
        }
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    void non_repeated() {
        for (Node* node = this->head->next; node != this->tail; node = node->next) {

            string data = node->data;
            Node* curr = node;
            while (curr->next != this->tail) {
                curr = curr->next;
                if (curr->data == data) {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    delete curr;
                    curr = curr->prev;
                }
            }
        }
    }

    /* void merge(LinkedList& other) {
         this->tail->prev->next = other.head->next;
         other.head->prev->next = this->tail;
         this->tail->prev = other.tail->prev;
         other.tail->prev = this->head;
     }*/
};


int main() {
    //try {
    LinkedList list;
    list.init_list();

    list.add("Ada");
    list.add("ma");
    list.add("kota");

    list.print();

    list.search("Ada");
    list.search("ma");
    list.search("szafe");

    list.remove("aluuus");
    list.remove("ma");
    list.print();

    list.add("test");
    list.add("test");
    list.add("test");
    list.add("test");
    list.print();
    list.non_repeated();
    list.print();

    LinkedList other;
    other.init_list();
    other.add("jeden");
    other.add("dwa");

    other.print();


    list.print();

    list.clean();
    list.print(); // 
    //} catch (exception &e) {
    //  cout << e.what() << endl;
   // }
    return 0;
}