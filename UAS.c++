#include <iostream>

using namespace std;

// Kelas untuk merepresentasikan node dari adjacency list
class AdjListNode {
public:
    int dest;
    AdjListNode* next;

    AdjListNode(int dest) {
        this->dest = dest;
        this->next = nullptr;
    }
};

// Kelas untuk merepresentasikan adjacency list
class AdjList {
public:
    AdjListNode* head;

    AdjList() {
        this->head = nullptr;
    }
};

// Kelas untuk merepresentasikan graph
class Graph {
    int V;
    AdjList* array;

public:
    Graph(int V);
    void tambahEdge(int src, int dest);
    void cetakGraph();
    ~Graph();
};

Graph::Graph(int V) {
    this->V = V;
    array = new AdjList[V];
}

void Graph::tambahEdge(int src, int dest) {
    // Menambahkan edge dari src ke dest
    AdjListNode* newNode = new AdjListNode(dest);
    newNode->next = array[src].head;
    array[src].head = newNode;

    // Karena graph tidak berarah, tambahkan juga edge dari dest ke src
    newNode = new AdjListNode(src);
    newNode->next = array[dest].head;
    array[dest].head = newNode;
}

void Graph::cetakGraph() {
    for (int v = 0; v < V; ++v) {
        AdjListNode* pCrawl = array[v].head;
        cout << "\n Daftar adjacency dari vertex " << v << "\n head ";
        while (pCrawl) {
            cout << "-> " << pCrawl->dest;
            pCrawl = pCrawl->next;
        }
        cout << endl;
    }
}

Graph::~Graph() {
    for (int v = 0; v < V; ++v) {
        AdjListNode* current = array[v].head;
        while (current) {
            AdjListNode* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] array;
}

int main() {
    Graph g(5);

    g.tambahEdge(0, 1);
    g.tambahEdge(0, 4);
    g.tambahEdge(1, 2);
    g.tambahEdge(1, 3);
    g.tambahEdge(1, 4);
    g.tambahEdge(2, 3);
    g.tambahEdge(3, 4);

    g.cetakGraph();

    return 0;
}
