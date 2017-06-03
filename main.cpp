#include <iostream>
#include <fstream>

using namespace std;
int main() {
    cin.unsetf(ios::skipws);
    short key;
    char dchar;
    srand(time(NULL));

    ofstream outData;
    ofstream outKey;

    outData.open("enData.txt");
    outKey.open("Key.txt");

    do
    {
        key = rand() % 128 - 127;
        cin >> dchar;

        outData.put(dchar^key);
        outKey.put(key);

    }while(dchar != '~');

    outData.close();
    outKey.close();

    ifstream inData;
    ifstream inKey;

    inData.open("enData.txt");
    inKey.open("Key.txt");

   // cout << inData.rdbuf();

    char chd, chk;
    while (inData.get(chd))
    {
        inKey.get(chk);
        chd = chd ^ chk;
        cout << chd;
    }
    return 0;
}