#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>

// Msg1: 96+!9?-?P,'"$90-=X#?#91?96#>P0+8<=0L55B."=4
// Msg2: >U():2*%>U/$_="5309A:&? _%9$)<85>U; -4K 24%)>
/*1ª Mensagem: INIMIGOS TENTARAM ASSASSINAR HITLER EM BREVE
Chaves: Chave 1: 112  Chave 2: 120  Chave 3: 98  Chave 4: 108
Composição das chaves =  1886937708

2ª Mensagem: A CHEGADA DE HITLER ESTA PREVISTA PARA AMANHA
Chaves: Chave 1: 127  Chave 2: 117  Chave 3: 107  Chave 4: 97
Composição das chaves =   2138401633*/
using namespace std;

int main()
{
	string data = "";
	cout << "Note: Sometimes the application emits a beep, it's because of XOR, sometimes it can type \\a (make a beep) when prints to the screen" << endl;
	cout << "Type the data, (must be 32 bits): ";
	cin >> data;
	char c[45] = {};
	char toBeMatched[] = {"HITLER"};
	bool end = false;
	long longkey1, longkey2, longkey3, longkey4;

	while (end == false) {
		for (int key1 = 0; key1 < 256; key1++)
		for (int key2 = 0; key2 < 256; key2++)
		for (int key3 = 0; key3 < 256; key3++)
		for (int key4 = 0; key4 < 256; key4++) {
			for (int i = 0, j = 1, k = 2, l = 3; i < data.size() && j < data.size() && k < data.size() && l < data.size(); i = i + 4, j = j + 4, k = k + 4, l = l + 4) {
				c[i] = data[i];
				c[i] ^= key1;

				c[j] = data[j];
				c[j] ^= key2;

				c[k] = data[k];
				c[k] ^= key3;

				c[l] = data[l];
				c[l] ^= key4;
			}
			string msg(c);
			if (strstr(c, toBeMatched)) {
				cout << key1 << "-" << key2 << "-" << key3 << "-" << key4 << " = " << msg << endl;
				longkey1 = key1;
				longkey2 = key2;
				longkey3 = key3;
				longkey4 = key4;

				longkey1 <<= 24;
				longkey2 <<= 16;
				longkey3 <<= 8;
				longkey4 = longkey4;

				cout << endl << "As chaves sao: " << "Chave 1: " << key1 << "  Chave 2: " << key2 << "  Chave 3: " << key3 << "  Chave 4: " << key4;
				cout << endl << "A chave e: " << longkey1 + longkey2 + longkey3 + longkey4 << endl;
				system("pause");

			}
			else {
				cout << key1 << "-" << key2 << "-" << key3 << "-" << key4 << " = " << msg << endl;
			}
		}
	}
	system("pause");
	cout << endl;
	cin.get();
	return 0;
}