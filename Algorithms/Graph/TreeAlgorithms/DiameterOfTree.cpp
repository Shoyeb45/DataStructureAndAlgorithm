#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


// Link to the blog : https://codeforces.com/blog/entry/101271

/*  
    --------------------------------------------------------------------------- Incomplete code -----------------------------------------------------------------------------
     
    vector<int> calcMaxLengthToLeaf(vector<int> adj[], int n) {
        vector<int> toLeaf(n + 1, 0);

        std:: function<void(int, int)>  dfs = [&](int start, int prev) {
            for(auto node: adj[start]) {
                if(node != prev) {
                    toLeaf[start] += toLeaf[node] + 1;
                    dfs(node, start);
                }
            }
        };

        dfs(1, -1);
        return toLeaf;
    }

    int findDiameter(vector<int> adj[], int n) {
        vector<int> toLeaf = calcMaxLengthToLeaf(adj, n);
        for(int i = 1; i <= n; i++) {
            cout << toLeaf[i] << " ";
        }

        return 0;
    }
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

int mxDistance = 0, farthestNode = 0;
void dfs(vector<int> adj[], int start, int prev, int dist = 0) {
    // Update distance and node
    if(dist > mxDistance) {
        mxDistance = dist;
        farthestNode = start;
    }

    for(auto node: adj[start]) {
        if(node != prev) {
            dfs(adj, node, start, dist + 1);
        }
    }
}

int findDiameter(vector<int> adj[], int n) {
    dfs(adj, 1, -1);
    int distA = mxDistance, a = farthestNode;
    mxDistance = 0, farthestNode = 0;
    dfs(adj, a, -1);
    return mxDistance;
}

int main() {
    NFS
    int n;
    cin >> n;

    vector<int> adj[n + 1];

    for(int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b); 
        adj[b].push_back(a); 
    }

    cout << findDiameter(adj, n) << "\n";
    return 0;
}