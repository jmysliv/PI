
#include <iostream>
#include <climits>
#include <vector>
#include <utility>

using namespace std;

const int INF = INT_MAX;

typedef struct Node {
    vector <pair<Node *, int>> neighbours;
    int val, dist;
} Node;

Node *newNode(int val) {
    Node *n = new Node;
    n->val = val;
    n->dist = INF;
    return n;
}

void addEdge(Node *u, Node *v, int w) {
    pair <Node *, int> edge(v, w);
    u->neighbours.push_back(edge);
}

bool relax(Node *u, Node *v, int weight) {
    // put your code here
    if(v->dist > u->dist + weight){
        v->dist = u->dist + weight;
        return true;
    }
    return false;
}

bool bellmann_ford(Node **nodes, int n, Node *start) {
    // put your code here
    start ->dist =0;
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            int j=0;
            while(j<nodes[i]->neighbours.size()){
                Node *tmp=nodes[i]->neighbours[j].first;
                relax(nodes[i], tmp, nodes[i]->neighbours[j].second);
                j++;
            }

        }
    }

    for(int i=0; i<n; i++){
        int j=0;
        while(j<nodes[i]->neighbours.size()){
            Node *tmp=nodes[i]->neighbours[j].first;
            if(relax(nodes[i], tmp, nodes[i]->neighbours[j].second)){
                return false;
            };
            j++;
        }

    }
    return true;
}

int main() {
    int N, k, start, end;
    cin >> N >> k;
    Node **nodes= new Node*[N];
    for (int i = 0; i < N; i++) nodes[i] = newNode(i);

    for (int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(nodes[u], nodes[v], w);
    }

    cin >> start >> end;
    if (!bellmann_ford(nodes, N, nodes[start])) cout << "CYKL" << endl;
    else if (nodes[end]->dist < INF) cout << nodes[end]->dist << endl;
    else cout << "NIE" << endl;

    for(int i=0; i<N; i++) delete nodes[i];
}
