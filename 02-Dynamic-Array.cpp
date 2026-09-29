#include <bits/stdc++.h>
using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<vector<int>> seq(n);
    vector<int> result;
    int lastAnswer = 0;

    for (int i = 0; i < queries.size(); i++) {
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];

        int index = (x ^ lastAnswer) % n;

        if (type == 1)
            seq[index].push_back(y);
        else if (type == 2) {
            lastAnswer = seq[index][y % seq[index].size()];
            result.push_back(lastAnswer);
        }
    }

    return result;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> queries(q, vector<int>(3));

    for (int i = 0; i < q; i++)
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];

    vector<int> result = dynamicArray(n, queries);

    for (int x : result)
        cout << x << endl;

    return 0;
}
