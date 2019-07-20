#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node {
    // int id;
    int degree;
    int *children;
    int parent;

    Node() {
        parent = -1; // default value
    }
};

int main() {
    int N; // number of nodes
    scanf("%d", &N);

    Node nodes[N];

    for (int i = 0; i < N; i++) {
        int id, degree;
        scanf("%d %d", &id, &degree);
        int *children = (int *)malloc(sizeof(int) * degree);
        for (int d = 0; d < degree; d++) {
            scanf("%d", &children[d]);
            nodes[children[d]].parent = id;
        }
        nodes[id].degree = degree;
        nodes[id].children = children;
    }

    for (int i = 0; i < N; i++) {
        int depth = 0;
        Node node = nodes[i];
        while (1) {
            if (node.parent == -1) {
                break;
            } else {
                node = nodes[node.parent];
                depth++;
            }
        }
        printf("node %d: parent = %d, depth = %d, ", i, nodes[i].parent, depth);
        if (nodes[i].parent == -1) {
            printf("root");
        } else if (nodes[i].degree == 0) {
            printf("leaf");
        } else {
            printf("internal node");
        }
        printf(", [");
        for (int d = 0; d < nodes[i].degree; d++) {
            printf("%d", nodes[i].children[d]);
            if (d != nodes[i].degree - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}