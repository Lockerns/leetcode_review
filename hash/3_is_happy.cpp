#include <iostream>
#include <unordered_set>

using namespace std;

bool is_happy(int num)
{
    unordered_set<int> record;
    int sum = num;
    int tmp = 0;

    while(record.find(sum) == record.end())
    {
        record.insert(sum);
        while(sum != 0)
        {
            tmp += (sum % 10) * (sum % 10);
            sum = sum / 10;
        }
        if (tmp == 1) return true;
        sum = tmp;
        tmp = 0;
    }
    return false;
}

int main()
{
    int num;
    cin >> num;
    if (is_happy(num))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
