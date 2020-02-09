#ifndef LIST_H
#define LIST_H
#include <stdexcept>
using std::runtime_error;

template<class T> class list {
private:
    struct node {
        T key;
        node *prev;
        node *next;
        node() {
            prev = next = 0;
        }
    };

    node *head, *tail;
    unsigned int sz;

public:
    class OutOfBoundException : public runtime_error {
    public:
        OutOfBoundException() : runtime_error( "An attempt to access an undefined element." ) {
        }
    };

    // I restricted myself to the requested specs only except for the + & - & != operators which I implemented through laziness.
    class iterator {
    private:
        node* p_node;
        friend class list;

    public:
        iterator (node* iPNode) : p_node(iPNode) {
        }

        void operator++() {
            if (!(p_node = p_node->next)) {
                throw OutOfBoundException();
            }
        }

        void operator--() {
            if (!(p_node = p_node->prev)) {
                throw OutOfBoundException();
            };
        }

        T& operator*() {
            return p_node->key;
        }

        bool operator==(const iterator& rhs) {
            return p_node == rhs.p_node;
        }

        bool operator!=(const iterator& rhs) {
            return !(*this == rhs);
        }

        iterator& operator-(unsigned int i) {
            while (i --> 0) {
                --(*this);
            }
            return *this;
        }

        iterator& operator+(unsigned int i) {
            while (i --> 0) {
                ++(*this);
            }
            return *this;
        }
    };

    void init() {
        head = tail = new node();;
        sz = 0;
    }

    list() {
        init();
    }

    list(T val, unsigned int iSize) {
        init();
        while(iSize --> 0) {
            insert(val, list::end());
        }
    }

    void free() {
        node* curNode = head;
        while (curNode != 0) {
            node* tmp = curNode->next;
            delete curNode;
            curNode = tmp;
        }
    }

    ~list() {
       free();
    }

    unsigned int size() {
        return sz;
    }

    void insert(T val, iterator pos) {
        node* newNode = new node();
        newNode->key = val;
        if (pos.p_node == head) {
            newNode->next = head;
            pos.p_node->prev = newNode;
            head = newNode;
        }
        else {
            newNode->next = pos.p_node;
            newNode->prev = pos.p_node->prev;
            pos.p_node->prev->next = newNode;
            pos.p_node->prev = newNode;
        }
        ++sz;
    }

    iterator erase(iterator pos) {
        if (pos.p_node == tail) {
            throw OutOfBoundException();
        }

        if (pos.p_node == head) {
            node* tmp = head;
            head = tmp->next;
            delete tmp;
            return head;
        }
        else {
            pos.p_node->next->prev = pos.p_node->prev;

            node *tmp = pos.p_node->next;;
            pos.p_node->prev->next = tmp;

            delete pos.p_node;
            return tmp;
        }
        --sz;
    }

    // I don't like the fact that it's passed by value in the assign. specs.
    list& operator=(list rhs) {
        free();
        iterator it = rhs.begin();
        while (it != rhs.end()) {
            insert(*it, end());
            ++it;
        }
        return *this;
    }

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(tail);
    }
};

#endif // LIST_H
