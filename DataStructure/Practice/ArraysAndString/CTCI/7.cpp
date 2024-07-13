#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void transpose(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix[0].size(); i++) {
            for (int j = i; j < matrix.size(); j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
}

void swap(vector<vector<int>>& matrix) {
    int k = matrix[0].size() - 1;
        int j = 0;
        while (j < k) {
            for (int i = 0; i < matrix.size(); i++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][k];
                matrix[i][k] = temp;
            }
            k--;
            j++;
        }
}

void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    swap(matrix);
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

    rotate(a);
    loop(i, n) { 
        loop(j, m) { 
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
