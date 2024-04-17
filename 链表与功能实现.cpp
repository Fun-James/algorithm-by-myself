#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Node class for each element in the linked list
class Node {
public:
    int num;
    Node* next;
    Node(int n) : num(n), next(nullptr) {}
};

// List class to manage the linked list
class List {
private:
    Node* head;
    Node* tail;
    int nodeCount;

public:
    List() : head(nullptr), tail(nullptr), nodeCount(0) {}

    // Function to insert a new node in the list
    void Insert(int n);

    // Function to remove a node from the list
    void Remove(int n);

    // Function to find a specific node in the list
    void Find(int n);

    // Function to print all nodes in the list
    void Print();
};

void List::Insert(int n) {
    Node* tmp = new Node(n);

    // Insert at the beginning if list is empty
    if (head == nullptr) {
        head = tail = tmp;
        nodeCount++;
    }
    else {
        // Insert at the beginning if num is smaller than head
        if (n < head->num) {
            tmp->next = head;
            head = tmp;
            nodeCount++;
            return;
        }
        // Insert at the end if num is larger than tail
        if (n > tail->num) {
            tail->next = tmp;
            tail = tmp;
            nodeCount++;
            return;
        }
        // Insert in between nodes based on num value
        Node* curr = head;
        while (curr->next != nullptr) {
            if ((curr->num <= n) && (curr->next->num > n)) {
                tmp->next = curr->next;
                curr->next = tmp;
                nodeCount++;
                return;
            }
            curr = curr->next;
        }
    }
}

void List::Remove(int n) {
    // Remove nodes with num equal to n
    while (head->num == n) {
        head = head->next;
        nodeCount--;
    }
    Node* curr = head;
    for (int i = 0; i < nodeCount - 1; i++) {
        if (curr->next->num == n) {
            if (curr->next->next != nullptr) {
                curr->next = curr->next->next;
                nodeCount--;
                continue;
            }
            else {
                curr->next = nullptr;
                nodeCount--;
                return;
            }
        }
        curr = curr->next;
    }
}

void List::Find(int n) {
    // Find the position of the node with num equal to n
    Node* curr = head;
    for (int i = 0; i < nodeCount; i++) {
        if (curr->num == n) {
            cout << "Find! n = " << i + 1 << " ";
            return;
        }
        curr = curr->next;
    }
    cout << "No such number!";
}

void List::Print() {
    // Print all nodes in the list
    Node* curr = head;
    for (int i = 0; i < nodeCount; i++) {
        cout << curr->num << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int count;
    List list;

    // Input the count of nodes for the list
    cout << "Please input the count of the node of the list: ";
    cin >> count;

    // Populate the list with random numbers
    srand(time(0));
    for (int i = 1; i <= count; i++) {
        int tmp = rand() % 100;
        list.Insert(tmp);
    }

    // Display the initial list
    cout << "Initial list: ";
    list.Print();

    int number;
    // Insert a node based on user input
    cout << "Please input the number of the node you want to insert: ";
    cin >> number;
    list.Insert(number);
    cout << "List after insertion: ";
    list.Print();

    // Remove a node based on user input
    cout << "Please input the number of the node you want to delete: ";
    cin >> number;
    list.Remove(number);
    cout << "List after deletion: ";
    list.Print();

    // Search for a node based on user input
    cout << "Please input the number of the node you want to search: ";
    cin >> number;
    list.Find(number);

    return 0;
}
