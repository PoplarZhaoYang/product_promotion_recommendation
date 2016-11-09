#ifndef PERSONALIZED_PROMOTION_H
#define PERSONALIZED_PROMOTION_H 

#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdio>
#include <vector>
#include <ctime>
using namespace std;
#define bug cout << "Debug!" << endl; 

class personailzed_promotion
{
private:
    static const int customers = 401, merchandises = 101;
    bool G[customers][merchandises];
    string tel[customers], name[customers];
    vector<int> lists[customers];
    struct same_M {
        int id, dis;
        same_M(){}
        same_M(int a, int b): id(a), dis(b){}
    } same_Ms[merchandises], human[customers];
    int remainder;

public:
    void csv_read();
    void build_G();
    int distance_G(int a, int b);
    static bool cmp(const same_M &a, const same_M &b);
    static bool hcmp(const same_M &a, const same_M &b);
    void get_same_Ms(int aim);
    void get_human();
    void send_it(string mes, int x, int id);
    void shows(int x);
};


#endif /* PERSONALIZED_PROMOTION_H */
