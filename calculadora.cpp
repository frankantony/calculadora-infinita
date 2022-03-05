#include <iostream>
#include<string>
#include "calculadora.h"

using namespace std;

int main() {
	string a, b;
	int caso;
	do {
		cout << "----------------------------------\n";
		cout << "Digite a opcao desejada:\n";
		cout << "1 - Soma;\n";
		cout << "2 - Produto;\n";
		cout << "3 - Fatorial;\n";
		cout << "4 - Sair\n";
		cin >> caso;
		if (caso == 1) {
			cout << "Digite o primeiro numero: ";
			cin >> a;
			cout << "Digite o segundo numero: ";
			cin >> b;
			cout << "Resultado: " << soma(a,b) << endl;
		}
		else if (caso == 2) {
			cout << "Digite o primeiro numero: ";
			cin >> a;
			cout << "Digite o segundo numero: ";
			cin >> b;
			cout << "Resultado: " << multiplicacao(a,b) << endl;
		}
		else if (caso == 3) {
			cin >> a;
			cout << "Fatorial (" << a << ") = " << fatorial(a) << endl;
		}	
		else {
			cout << "Menu finalizado!\n";
			break;
		}
	} while (caso >= 1 && caso <= 3);

    return 0;
}
