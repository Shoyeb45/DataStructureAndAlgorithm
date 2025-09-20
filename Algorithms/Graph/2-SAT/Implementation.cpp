# include<bits/stdc++.h>
using namespace std;


int n; // number of variables
int m; // number of conditions
vector<vector<int>> adj, adj_t;
vector<bool> vis;
stack<int> order;
vector<int> compo;

int _negate(int a) {
    return a <= n? a + n: a - n;
}


/// function to add the edge in adj and adj^T
/// if a = x, then (not a) = x + n
void add_disjunction(int a, bool is_na, int b, bool is_nb) {
    a = is_na? _negate(a): a, b = is_nb? _negate(b): b;
    int n_a = _negate(a), n_b = _negate(b);

    adj[n_b].push_back(a);    // not b => a
    adj[n_a].push_back(b);    // not a -> b

    // transposed edges
    adj_t[b].push_back(n_a);  
    adj_t[a].push_back(n_b); 
}

void input_graph() {
    cout << m << "\n";
    for (int i = 0; i < m; i++) {
        // a V b -> in input + a + b
        // not a V not b -> in input - a - b
        char ch;
        int x;  // x between 1 to n
        cin >> ch >> x;
        int is_na = ch == '-'; // is negation of a
        int a = x;
        cin >> ch >> x;
        int is_nb = ch == '-';    // is negation of b
        int b = x;
        add_disjunction(a, is_na, b, is_nb);
    }
}


void dfs_1(int u) {
    vis[u] = true;
    for (int &v: adj[u]) {
        if (!vis[v]) {
            dfs_1(v);
        }
    }
    order.push(u);
}

void dfs_2(int u, int scc) {
    compo[u] = scc;
    vis[u] = true;     
    for (int &v: adj_t[u]) {
        if (!vis[v]) {
            dfs_2(v, scc);
        }
    }
}

void solve() {
    vis.resize(2 * n + 1, false);

    for (int i = 1; i <= 2 * n; i++) {
        if (!vis[i]) {
            dfs_1(i);
        }
    }

    int scc = 0;

    vis.assign(2 * n + 1, false);
    while (!order.empty()) {
        int x = order.top();
        order.pop();

        if (!vis[x]) {
            dfs_2(x, scc++);
        }
    }

    vector<bool> ans(n + 1, false);

    for (int x = 1; x <= n; x++) {
        if (compo[x] == compo[_negate(x)]) {
            cout << "No Possible Solution\n";
            return;
        }
        ans[x] = compo[x] > compo[_negate(x)];
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}


int main() {
    cin >> n >> m;

    adj.resize(2 * n + 1), adj_t.resize(2 * n + 1);
    compo.resize(2 * n + 1);
    input_graph();
    solve();

}