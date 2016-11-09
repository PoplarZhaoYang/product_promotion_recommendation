#include "personalized_promotion.h"

void personailzed_promotion::csv_read() {
    freopen("../../files/customerRecord.csv", "r", stdin);
    string r;
    while (getline(cin, r)) {
        r += ',';
        if (isdigit(r[0])) {
            int id = 0;
            string Tel, Name;
            int p = 0;
            while (r[p] != ',') {
                id = id * 10 + (r[p] - '0'), ++p;
            }
            ++p;
            while (r[p] != ',') {
                Name += r[p], ++p;
            }
            ++p;
            while (r[p] != ',') {
                Tel += r[p], ++p;
            }
            int numbers = 0;
            ++p;
            while (r[p] != ',') {
                numbers = numbers * 10 + (r[p] - '0'), ++p;
            }
            tel[id] = Tel, name[id] = Name;
            while (numbers--) {
                ++p;
                int x = 0;
                while (r[p] != ',') {
                    x = x * 10 + (r[p] - '0'), ++p;
                }
                lists[id].push_back(x);
            }
        }
    }
    fclose(stdin);
}

bool personailzed_promotion::cmp(const same_M &a, const same_M &b) {
    return a.dis > b.dis;
}

bool personailzed_promotion::hcmp(const same_M &a, const same_M &b) {
    return a.dis > b.dis;
}

void personailzed_promotion::send_it(string mes, int x, int id) {
    freopen("../../output/promotion_record.CSV", "a", stdout);
    time_t tt = time(NULL);
    tm* t = localtime(&tt);
    cout << "" << (t->tm_year + 1900) << "/" << (t -> tm_mon + 1) << "/" << (t -> tm_mday)<< " " <<  t -> tm_hour << ":" << t -> tm_min << ","; 
    cout << "" << x << ",";
    cout << id << ",";
    mes += " ";
    for (int i = 1; i <= x; ++i) {
        if (i != 1) cout << ",";
        cout << human[i].id;
    }
    cout << endl;
    fclose(stdout);
}

void personailzed_promotion::get_human() {
    for (int i = 1; i < customers; ++i) {
        int x = 0;
        for (int j = 1; j <= 5; ++j) {
            if (G[i][same_Ms[j].id]) ++x;
        }
        human[i] = same_M(i, x);
    }
    sort(human + 1, human + customers, hcmp);
}


void personailzed_promotion::shows(int x) {
    for (int i = 1; i <= x; ++i) {
        cout << human[i].id << " " << name[human[i].id] << " " << tel[human[i].id];
        cout << endl;
    }
}

void personailzed_promotion::get_same_Ms(int aim) {
    for (int i = 1; i < merchandises; ++i) {
        same_Ms[i] = same_M(i, distance_G(i, aim));
    }
    sort(same_Ms + 1, same_Ms + merchandises, cmp);
}

int personailzed_promotion::distance_G(int a, int b) {
    int d = 0;
    for (int i = 1; i <= 100; ++i) {
        if (G[a][i] == G[b][i]) ++d;
        if (G[a][i] != G[b][i]) --d;
    }
    return d;
}

void personailzed_promotion::build_G() {
    for (int i = 1; i < customers; ++i) {
        for (vector<int>::iterator c = lists[i].begin(); c != lists[i].end(); ++c) {
            G[i][*c] = true;
        }
    }
} 
