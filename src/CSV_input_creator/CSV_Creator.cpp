#include <iostream>
#include <string>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

string randomName(int i) {
    srand(i);
    int len = rand() % 10 + 5;
    string ret;
    for (int i = 0; i < len; ++i) {
        if (i == len / 2) ret += " ";
        else if (!i || i == len / 2 + 1) ret += char('A' + rand() % 26);
        else ret += char('a' + rand() % 26);
    }
    return ret;
}

string randomTel(int i) {
    srand(i);
    string ret;
    for (int i = 1; i <= 13; ++i) {
        if (i == 9 || i == 4) ret += '-';
        else ret += char(rand() % 10 + '0');
    }
    return ret;
}



void coustomerRecord(int n) {
    cout << "name,id,tel,merchandise number,merchandise id" << endl;
    for (int i = 1; i <= n; ++i) {
        int choose = 0;
        if (i < n / 10) choose = 10;
        else choose = 50;
        int j = rand() % choose + 1;
        cout << i << "," <<  randomName(i) << "," << randomTel(i) << ","; 
        cout << j << ",";
        for (int k = 0; k < j; ++k) {
            if (k) cout << ",";
            cout << rand() % 100 + 1;
        }
        cout << endl;
    }
}

int main()
{
    freopen("customerRecord.csv", "w", stdout);
    int n;
    cin >> n;
    coustomerRecord(n);
    return 0;
}
