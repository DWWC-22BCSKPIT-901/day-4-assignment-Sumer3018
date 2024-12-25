#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int poisonousPlants(vector<int>& plants) {
    int days = 0;
    stack<pair<int, int>> st;
    for (int plant : plants) {
        int maxDays = 0;
        while (!st.empty() && st.top().first >= plant) {
            maxDays = max(maxDays, st.top().second);
            st.pop();
        }
        st.push({plant, st.empty() ? 0 : maxDays + 1});
        days = max(days, st.top().second);
    }
    return days;
}

int main() {
    int n;
    cin >> n;
    vector<int> plants(n);
    for (int i = 0; i < n; i++) cin >> plants[i];
    cout << poisonousPlants(plants) << endl;
    return 0;
}
