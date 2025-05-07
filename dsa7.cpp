#include <iostream>
using namespace std;

class snode{ // data structure for sparse matrix
 public:
    char n1, n2;
    int wt;
};

class test {
    int n, m, x; // edges,vertices,edg in mst
    snode input_graph[10], res[10];

public:
    test() {
        n = 0;
        m = 1;
    }

    void inputsparse();
    void displaysparse();
    void bsort();
    void prims();
    void dispmst();
};

void test::dispmst() {
    for (int i = 0; i < m; i++) {
        cout << res[i].n1 << " - " << res[i].n2 << " : " << res[i].wt << endl;
    }
}

void test::prims() {
    int cnt = 0;
    int flag1, flag2, i;
    res[0] = input_graph[0];
    m = 1;
    cnt = 1;

    do {
        for (i = 1; i < n; i++) {
            flag1 = 0;
            flag2 = 0;
            for (int j = 0; j < m; j++) {
                if ((input_graph[i].n1 == res[j].n1 || input_graph[i].n1 == res[j].n2) && flag1 == 0) {
                    flag1++;
                }
                if ((input_graph[i].n2 == res[j].n1 || input_graph[i].n2 == res[j].n2) && flag2 == 0) {
                    flag2++;
                }
            }

            if (flag1 ^ flag2) {
                res[m++] = input_graph[i];
            }
        }

        cnt = x - 1;
    } while (m != cnt);
}

void test::inputsparse() {
    cout << "Enter no of edges: ";
    cin >> n;
    cout << "Enter no of vertices: ";
    cin >> x;

    for (int i = 0; i < n; i++) {
        cout << " Enter 1st vertex: ";
        cin >> input_graph[i].n1;
        cout << " Enter 2nd vertex: ";
        cin >> input_graph[i].n2;
        cout << "Enter weight: ";
        cin >> input_graph[i].wt;
        cout << endl;
    }
    bsort();
}

void test::displaysparse() {
    for (int i = 0; i < n; i++) {
        cout << input_graph[i].n1 << " " << input_graph[i].n2 << " " << input_graph[i].wt << endl;
    }
}

void test::bsort() {
    snode temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (input_graph[j].wt > input_graph[j + 1].wt) {
                temp = input_graph[j];
                input_graph[j] = input_graph[j + 1];
                input_graph[j + 1] = temp;
            }
        }
    }
}

int main() {
    test obj;
    obj.inputsparse();
    obj.displaysparse();
    obj.prims();
    cout << "RESULT: Minimum Spanning Tree Edges " << endl;
    obj.dispmst();
    return 0;
}
