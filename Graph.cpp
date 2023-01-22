#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Vertex {
    vector<Vertex> edge;
    string name = "";
    T val = NULL;
    Vertex(string name_c) : name(name_c) {};
};

template<typename T>
struct Graph {
public:
    vector<Vertex<T>> vertices;

    void add_vertex(string name) {
        Vertex<T> ver(name);
        ver.edge.push_back(ver);
        vertices.push_back(ver);
    }

    void add_edge(string name1, string name2) {
        if (name1 == name2) {
            return;
        }

        bool exist1 = false, exist2 = false;
        int pos1 = 0, pos2 = 0;

        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i].name == name1) {
                exist1 = true;
                pos1 = i;
            }
            if (vertices[i].name == name2) {
                exist2 = true;
                pos2 = i;
            }
        }

        vertices[pos1].edge.push_back(vertices[pos2]);
        vertices[pos2].edge.push_back(vertices[pos1]);
    }

    void show_graph(int type) {
        if (type == 0) {
            for (int i = 0; i < vertices.size(); i++) {
                cout << vertices[i].name << ": ";
                for (int j = 0; j < vertices[i].edge.size(); j++) {
                    cout << vertices[i].edge[j].name;
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    Graph<int> graph;
    graph.add_vertex("A");
    graph.add_vertex("B");
    graph.add_vertex("C");
    graph.add_edge("A", "B");
    graph.add_edge("B", "C");
    graph.show_graph(0);
}

