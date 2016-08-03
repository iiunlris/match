#include <bits/stdc++.h>
using namespace std;

const int N = 5050;
char A[N], B[N];
int aa[N][N], bb[N][N];

int main() {
  scanf("%s%s", A, B);
  int lenA = strlen(A);
  int lenB = strlen(B);
  for (int i = lenA - 1; i >= 0; i--) {
    for (int j = lenB - 1; j >= 0; j--) {
      if (A[i] == B[j]) {
        aa[i][j] = max(aa[i][j], aa[i + 1][j + 1] + 1);
      }
      aa[i][j] = max(aa[i][j], max(aa[i][j + 1], aa[i + 1][j]));
    }
  }
  for (int i = 0; i <= lenA; i++) {
    for (int j = 0; j <= lenB; j++) {
      if (A[i] == B[j]) {
        bb[i + 1][j + 1] = max(bb[i][j] + 1, bb[i + 1][j + 1]);
      }
      bb[i + 1][j] = max(bb[i + 1][j], bb[i][j]);
      bb[i][j + 1] = max(bb[i][j + 1], bb[i][j]);
    }
  }
  int mx = aa[0][0];
  int ret = 0;
  for (int i = 0; i <= lenA; i++) {
    bool vis[256];
    memset(vis, 0, sizeof(vis));
    for (int k = 0; k < lenB; k++) {
      if (aa[i][k + 1] + bb[i][k] == mx && !vis[B[k]]) {
        vis[B[k]] = true;
        ret++;
      }
    }
  }
  cout << ret << endl;
  return 0;
}