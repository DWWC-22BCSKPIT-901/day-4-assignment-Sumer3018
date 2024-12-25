#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q) {
    if (q.empty()) return;
    int front = q.front();
    q.pop();
    reverseQueue(q);
    q.push(front);
}

int main() {
    queue<int> q;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }
    reverseQueue(q);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
