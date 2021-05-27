#include "Graph.h"
#include "Vertex.h"
#include <iostream>
#include <ostream>
using namespace std;

Graph::Graph() : vertices(0)
{}

Graph::Graph(ifstream& inFS) {
    // Initalize and set N (max vertices) and M (max edges) passed
    int N = 0;
    int M = 0;
    inFS >> N; 
    inFS >> M;

    // Set all vertices' labels and store into the vector
    for (int i = 0; i < N; i++) {
        string vertexLabel = "";
        inFS >> vertexLabel;
        Vertex vertex;
        vertex.label = vertexLabel;
        vertices.push_back(vertex);
    }

    // Set the edges between vertices
    for (int i = 0; i < M; i++) {
        // Search for u (first vertex's index) in vector
        string vertexOne = "";
        int u = 0;
        inFS >> vertexOne;
        for(int j = 0; j < vertices.size(); j++) {
            if(vertices.at(j).label == vertexOne) {
                u = j;
                break;
            }
        }

        // Search for v (second index) in vector
        string vertexTwo = "";
        int v = 0;
        inFS >> vertexTwo;
        for(int j = 0; j < vertices.size(); j++) {
            if(vertices.at(j).label == vertexTwo) {
                v = j;
                break;
            }
        }

        // Set c (weight) and v into a pair and push back into u, where e = (u, v, c)
        int c = 0;
        inFS >> c;
        pair<int, int> e(v, c);
        vertices.at(u).neighbors.push_back(e);
    }
}

void Graph::output_graph(const string &outputFilename) {
    ofstream outFS(outputFilename.c_str());
	if(!outFS.is_open()){
		cout<<"Error"<<endl;
		return;
	}
	outFS<<"digraph G {"<<endl;
	output_graph(outFS);
	outFS<<"}";
	outFS.close();
	string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
	string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
	system(command.c_str());
}

void Graph::bfs(){ 
    queue<Vertex> q;
    vertices.at(0).color = "GRAY";
    vertices.at(0).distance = 0;
    vertices.at(0).prev = nullptr;
    q.push(vertices.at(0));
    while (!q.empty()) {
        Vertex u = q.front();
        q.pop();
        for (auto v : u.neighbors) {
            if (vertices.at(v.first).color == "WHITE") {
                vertices.at(v.first).color = "GRAY";
                vertices.at(v.first).distance = u.distance + 1;
                vertices.at(v.first).prev = &u;
                q.push(vertices.at(v.first));
            }
            u.color = "BLACK";
        }
    }
}

void Graph::output_graph(ofstream &s) {
    for(unsigned i = 0; i < vertices.size(); i++) {
        s << vertices.at(i).label << " [label=\"" << vertices.at(i).label << ", distance = " << vertices.at(i).distance << "\", color=\"" << vertices.at(i).color << "\"];" << endl;
        Vertex v = vertices.at(i);
            for (auto edge : v.neighbors) {
                int vertexOne = i;
                int vertexTwo = edge.first;
                s << vertices.at(vertexOne).label << " -> " << vertices.at(vertexTwo).label << ";" << endl;
            }
    }
}