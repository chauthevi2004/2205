#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> randomN(990000, 1000000);
    uniform_int_distribution<int> randomNumber(1, 10000000);
    ofstream fo("baseValue.txt"); // This file contains logN and 1.45logN values of 10 tests
    for (int i = 1; i <= 10; ++i)
    {
        string fileName = "Test" + to_string(i) + ".txt";
        ofstream file(fileName);
        int N = randomN(gen);
        file << N << '\n';

        if (i < 3)
        {
            set<int> numbers;
            while (numbers.size() < N)
            {
                numbers.insert(randomNumber(gen));
            }
            if (i == 1) // Test1.txt has acsending elements
            {
                for (const int &num : numbers)
                    file << num << " ";
            }
            else if (i == 2) // Test2.txt had descending elements
            {
                set<int>::reverse_iterator rit;
                for (rit = numbers.rbegin(); rit != numbers.rend(); rit++)
                    file << *rit << " ";
            }
        }
        else // Test3...Test 10 has random ordered elements
        {
            unordered_set<int> numbers;
            while (numbers.size() < N)
            {
                numbers.insert(randomNumber(gen));
            }
            for (const int &num : numbers)
                file << num << " ";
        }
        fo << log2(N) << " " << 1.45 * log2(N) << '\n';
        file.close();
    }
    fo.close();
    return 0;
}
