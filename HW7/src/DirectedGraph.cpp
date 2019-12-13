#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(Edge *edges, int size) {
    for (int i = 0; i < size; i++) {
        int src = edges[i].src, dest = edges[i].dest;
        if (nodes.count(src) == 0) {
            nodes[src] = new SingleLinkedList<int>();
        }
        nodes[src]->add(dest);
        if (nodes.count(dest) == 0) {
            nodes[dest] = new SingleLinkedList<int>();
        }
    }
}

DirectedGraph::~DirectedGraph() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        delete (*it).second;
    }
}

void DirectedGraph::printGraph() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        printf("node(%d) has edges: ", (*it).first);
        for (auto itl = (*it).second->begin(); itl != (*it).second->end(); itl++) {
            printf("%d ", (*itl));
        }
        printf("\n");
    }
}

void DirectedGraph::topologySort(int val, LinkedStack<int> &stack, set<int> &visited) {
    // add value to visited
    visited.insert(val);

    // iterate through the list of destinations for the given value
    for (auto it = nodes[val]->begin(); it != nodes[val]->end(); it++) {

        // if 'visited' does not contain destination
        if(!(visited.find((*it)) != visited.end())) {

            // recursive function to get to end of destinations
            topologySort((*it), stack, visited);
        }
    }

    // input on stack, destinations first then value
    stack.push(val);
}

vector<int> *DirectedGraph::topologySort() {
	// homework
	vector<int> *result = new vector<int>;
    LinkedStack<int> stack;

    // to keep track of which values have been visited
    set<int> visited;

    // iterate through each node
    for (auto it = nodes.begin(); it != nodes.end(); it++) {

        // if 'visited' does not contain node value
        if(!(visited.find((*it).first) != visited.end())) {

            // recursive function to get to end of destinations for given value
            topologySort((*it).first, stack, visited);
        }
    }

    // inputs the stack into the result
    while (!stack.isEmpty()) {
        result->push_back(stack.peek());
        stack.pop();
    }

	return result;
}