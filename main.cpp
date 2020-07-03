#include <iostream>
#include "cstring"
#include <cmath>

using namespace std;

int modexp(int k, int e, int n)
{
    if (e == 0)
        return 1;
    int z = modexp(k, e / 2, n);
    if (e % 2 == 0)
        return (z * z) % n;
    else
        return (k * z * z) % n;
}

int main()
{
    int m = 0, p = 0, q = 0, n, f, d = 0, max, min, k;
    double e = 0;
    char *text = new char[m], al[] = "abcdefghijklmnopqrstuvwxyz0123456789 ,.?;:!";
    bool exit = true;
    cout << "Enter your text: ";
    gets(text);
    strlwr(text);
    int z[strlen(text)], x[strlen(text)];
    cout << "Enter your first simple number: ";
    while (exit)
    {
        cin >> p;
        cout << "Enter your second simple number: ";
        cin >> q;
        max = p;
        min = p;
        if (q > p) max = q;
        else min = q;
        for (int i = 2; i < max; i++)
        {
            if (((p % i != 0 || q % i != 0) && p != q) || (i == min && i != 2) || p > 1 || q > 1)
            {
                exit = false;
            } else
            {
                cout << "Error, please enter simple numbers: ";
                exit = true;
                break;
            }
        }
    }
    exit = true;
    n = p * q;
    f = (p - 1) * (q - 1);
    while (exit)
    {
        for (; d < f; d++)
        {
            if (d % 2 != 0 && f % d != 0)break;
        }
        for (int a = 1; a < f; a++)
        {
            e = double((a * f + 1)) / d;
            if ((e - floor(e)) == 0 && e != 0)
            {
                exit = false;
                break;
            }
        }
    }
    cout << "It is your open key (" << e << ", " << n << ").\nIt is your secret key (" << d << ", " << n
         << ").\nOpen text\n";
    for (unsigned int i = 0; i < strlen(text); i++)
    {
        for (unsigned int j = 0; j < strlen(al); j++)
        {
            if (text[i] == al[j])
            {
                cout << int(j) + 1 << " ";
            }
        }
    }
    cout << "\nEncrypt text\n";
    for (unsigned int i = 0; i < strlen(text); i++)
    {
        for (unsigned int j = 0; j < strlen(al); j++)
        {
            if (text[i] == al[j])
            {
                k = int(j) + 1;
                z[i] = modexp(k, int(e), n);
                cout << z[i] << " ";
                break;
            }
        }
    }
    cout << "\nDecrypt text\n";
    for (unsigned int i = 0; i < strlen(text); i++)
    {
        x[i] = modexp(z[i], d, n);
        cout << x[i] << " ";
    }
    cout << endl;
    for (unsigned int i = 0; i < strlen(text); i++)
    {
        k = x[i];
        cout << al[k - 1];
    }
    cout << endl;
    delete[] text;
    return 0;
}

