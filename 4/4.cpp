#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("chaos.in");
  ofstream fout("chaos.out");

  int a, b, c, d;
    long long int k;
    fin >> a >> b >> c >> d >> k;

    int ans = -1;
    for (int i = 0; i < k; i++){
        a = a * b - c;
        if (a <= 0){
            ans = 0;
            break;
        }
        if (a > d){
            a = d;
        }
        if (a == ans) break;
        ans = a;
    }
    fout << ans;
  fin.close();
  fout.close();
    return 0;
}
