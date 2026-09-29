#include <bits/stdc++.h>
using namespace std;

vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    vector<int> result;

    for (int i = 0; i < queries.size(); i++) {
        int count = 0;

        for (int j = 0; j < stringList.size(); j++) {
            if (queries[i] == stringList[j])
                count++;
        }

        result.push_back(count);
    }

    return result;
}

int main() {
    int stringList_count;
    cin >> stringList_count;

    vector<string> stringList(stringList_count);

    for (int i = 0; i < stringList_count; i++)
        cin >> stringList[i];

    int queries_count;
    cin >> queries_count;

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++)
        cin >> queries[i];

    vector<int> result = matchingStrings(stringList, queries);

    for (int x : result)
        cout << x << endl;

    return 0;
}
