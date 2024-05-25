#include <bits/stdc++.h>
using namespace std;
int main()
{
  int i, j, n, a[50], frame[10], no, k, avail, count = 0;
  cout << "Enter the length of the Reference string: ";
  cin >> n;

  cout << "Enter the reference string: ";
  for (i = 1; i <= n; i++)
    cin >> a[i];

  cout << "Enter the number of Frames: ";
  cin >> no;

  for (i = 0; i < no; i++)
    frame[i] = -1;

  j = 0;
  // cout << "\tRef String\t Page Frames\n";
  for (i = 1; i <= n; i++)
  {
    // cout << a[i] << "\t\t";
    avail = 0;

    for (k = 0; k < no; k++)
    {
      if (frame[k] == a[i])
        avail = 1;
    }

    if (avail == 0)
    {
      frame[j] = a[i];
      j = (j + 1) % no;
      count++;

      // for (k = 0; k < no; k++)
      // cout << frame[k] << "\t";
    };
    // cout << "\n\n";
  }

  cout << "Page Fault is " << count;
  return 0;
}
// 13
// 7,0,1,2,0,3,0,4,2,3,0,3,2
// 4