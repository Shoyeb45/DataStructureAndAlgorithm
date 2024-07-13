// Set Zeroes

#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void setZeros(vector<vector<int>>& a) {
    priority_queue<pair<int, int>> pq;

        int n = a.size();
        int m = a[0].size();

        loop(i, n) {
            loop(j, m) {
                if(a[i][j] == 0) {
                    pq.push({i, j});
                }
            }
        }

        while(!pq.empty()) {
            int i = pq.top().first;
            int j = pq.top().second;
            
            while(j < m) {
                a[i][j] = 0;
                j++;
            }
            j = pq.top().second;

            while(j >= 0) {
                a[i][j] = 0;
                j--;
            }
            j = pq.top().second;

            while(i < n) {
                a[i][j] = 0;
                i++;
            }
            i = pq.top().first;

            while(i >= 0) {
                a[i][j] = 0;
                i--;
            }
            pq.pop();
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    loop(i, n)
        loop(j, m)
            cin >> a[i][j]; 

    setZeros(a);
    
    loop(i, n) { 
        loop(j, m) { 
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
