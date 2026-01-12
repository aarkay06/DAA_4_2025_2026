
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

std::vector<int> complexRec(int n)
{
    vector<int> data = {0, 1};
    if (n <= 2)
    {

        return data;
    }

    // 1
    int p = n;

    // OVERALL - nlogn times
    // log n times
    while (p > 0)
    {
        vector<int> temp(n);
        // n times
        for (int i = 0; i < n; i++)
        {
            temp[i] = i ^ p;
            data[0] += 1;
        }
        p >>= 1;
        data[0] += 1;
    }

    vector<int> small(n);
    // n times
    for (int i = 0; i < n; i++)
    {
        small[i] = i * i;
        data[0] += 1;
    }

    // n operataions
    if (n % 3 == 0)
    {
        reverse(small.begin(), small.end());
        data[0] += n;
    }
    else
    {
        reverse(small.begin(), small.end());
        data[0] += n;
    }

    vector<int> data1 = complexRec(n / 2);
    vector<int> data2 = complexRec(n / 2);
    vector<int> data3 = complexRec(n / 2);

    data[0] += data1[0];
    data[0] += data2[0];
    data[0] += data3[0];
    data[1] += data1[1];

    return data;
}

int main()
{
    auto start = high_resolution_clock::now();
    vector<int> data = complexRec(16);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "No. of operations in this code is: " << data[0] << endl;
    cout << "Depth is : " << data[1] << endl;
    cout << "Time to run all operations: " << duration.count();
}