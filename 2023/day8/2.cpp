#include <bits/stdc++.h>

using namespace std;

typedef priority_queue<pair<long, string>, vector<pair<long, string>>, 
    greater<pair<long, string>>> heap;

bool checkHeap(heap nodeHeap)
{
    int n = nodeHeap.top().first;
    while (!nodeHeap.empty()) {
        if (nodeHeap.top().first != n) return false;
        nodeHeap.pop();
    }
    return true;
}

int main()
{
    string s;
    char c;
    getline(cin, s);
    vector<int> path;
    stringstream ss(s);
    while ((ss >> c)) {
        path.push_back((c == 'L') ? 0 : 1);
    }

    unordered_map<string, vector<string>> graph;
    vector<string> nodes, zNodes;

    getline(cin, s); // blank line
    while (getline(cin, s))
    {
        stringstream ss(s);
        string src, l, r;
        ss >> src;
        ss >> c >> c; // = (
        ss >> l;
        ss >> r;
        l = l.substr(0, l.size() - 1);
        r = r.substr(0, r.size() - 1);

        graph[src] = {l, r};
        if (src[2] == 'A') nodes.push_back(src);
        if (src[2] == 'Z') zNodes.push_back(src);
    }

    unordered_map<string, pair<long, string>> dp;
    heap nodeHeap;
    for (int i = 0; i < nodes.size(); i++) {
        int count = 0;
        string node = nodes[i];
        while (node[2] != 'Z') {
            for (int j = 0; j < path.size(); j++) {
                node = graph[node][path[j]];
                count++;
            }
        }
        nodeHeap.push({count, node});
        cout << node << " " << count << endl;

        count = 0;
        string zNode = zNodes[i];
        do {
            for (int j = 0; j < path.size(); j++) {
                zNode = graph[zNode][path[j]];
                count++;
            }
        } while (zNode[2] != 'Z');
        dp[zNodes[i]] = {count, zNode};
    }
    // Noticed path start and z cycle are the same
    // so we can just get the lcm of all z cycles
    // https://www.calculatorsoup.com/calculators/math/lcm.php

/*
    while (!checkHeap(nodeHeap)) {
        pair<long, string> node = nodeHeap.top();
        nodeHeap.pop();
        node.first += dp[node.second].first;
        node.second = dp[node.second].second;
        if (node.second != nodeHeap.top().second) nodeHeap.push(node);
        cout << node.first << endl;
    }
    */

    //cout << nodeHeap.top().first << endl;
    return 0;
}
