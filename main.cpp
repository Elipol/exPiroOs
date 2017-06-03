#include <iostream>
#include <fstream>

using namespace std;
int main() {
    cin.unsetf(ios::skipws);

    srand(time(NULL));
    char *word = new char[10];
    short key[10];

    for (int i = 0; i < 10; i++) {
        key[i] = rand() % 128 - 127;
        cin >> word[i];
        word[i] = word[i] ^ key[i];
    }

    for (int i = 0; i < 10; i++)
        cout << word[i];
    cout << endl;

    for (int i = 0; i < 10; i++) {
        word[i] = word[i] ^ key[i];
        cout << word[i];
    }
    cout << endl;

    return 0;
}