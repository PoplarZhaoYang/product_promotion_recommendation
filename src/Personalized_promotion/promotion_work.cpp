#include "personalized_promotion.h"

int main()
{
    personailzed_promotion now;
    int id = 20, n = 20;
    cout << "*************Hello! Wecome to use personalized promotion!*****************" << endl;
    cout << endl;
    cout << "Now, please scan the merchandise that you want to sell: "; 
    cin >> id;
    cout << "Please input the number of merchandise you want to sell: ";
    cin >> n;
    cout << "Please edit the promotion short message ending up with $" << endl;
    string strs;
    getline(cin, strs, '$');
    now.csv_read();
    now.build_G();
    now.get_same_Ms(id);
    now.get_human();
    cout << "Ok! The following people may be interested in this merchandise:" << endl;
    now.shows(2 * n);
    cout << endl;
    cout << "Please wait for several seconds, I am sending messages now...." << endl;
    sleep(4);
    cout << "Sending now...." << endl;
    sleep(4);
    cout << "now...." << endl;
    sleep(3);
    cout << endl;
    cout << "**************Successfully!********************" << endl;
    cout << "I have sent the short message to the " << 2 * n << " people!";
    cout << endl << endl;
    now.send_it(strs, 2 * n, id);
    return 0;
}
