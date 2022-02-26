#include <algorithm>
#include <iostream>
#include<string>

using namespace std;

//calcula soma
string soma (string a, string b) {
	string resultado = "";
	int tam_a = a.length()-1, tam_b = b.length()-1, unidade, dezena = 0, soma, i;
	while (tam_a >= 0 && tam_b >= 0) {
		int c_1 = a[tam_a] - '0', c_2 = b[tam_b] - '0';
		soma = c_1 + c_2 + dezena;
		dezena = soma / 10;
		unidade = soma % 10;
		resultado += (unidade + '0');
		tam_a--;
		tam_b--;
	}
	//caso em que foi subido algum valor e nao existe mais parcelas a ser calculado. 
	//Neste caso é necessário armazena este valor que subiu.

	//caso em que string b é a maior.
	while(tam_b >= 0) {
		soma = dezena + (b[tam_b]-'0');
		dezena = soma / 10;
		unidade = soma % 10;
		resultado += (unidade + '0');
		tam_b--;
	}

	//caso em que a string a é a maior.
	while (tam_a >= 0) {
		soma = dezena + (a[tam_a]-'0');
		dezena = soma / 10;
		unidade = soma % 10;
		resultado += (unidade + '0');
		tam_a--;
	}
	if (dezena > 0)
		resultado += (dezena + '0');

	reverse(resultado.begin(), resultado.end());
	return resultado;
}

//calcula multiplicacao
string multiplicacao (string a, string b) {
	string zeros = "", resultado = "0", parcela = "";
	int tam_a = a.length(), tam_b = b.length(), produto, unidade, dezena = 0;
	for (int i = tam_a-1;i >= 0;i--) {
		parcela += zeros;
		for (int j = tam_b-1; j >= 0;j--) {
			produto = (a[i]-'0') * (b[j]-'0') + dezena;
			dezena = produto / 10;
			unidade = produto % 10;
			parcela += (unidade + '0');
		}
		if (dezena > 0)
			parcela += (dezena + '0');

		reverse (parcela.begin(), parcela.end());
		resultado = soma(resultado, parcela);
		zeros += "0";
		parcela = "";
		dezena = 0;
	}
	return resultado;
}

//calcula fatorial
string fatorial (string a) {
	string resultado = "1", valor = "1";
	while (valor != a) {
		resultado = multiplicacao (resultado, valor);
		valor = soma(valor, "1");
	}
	resultado = multiplicacao(resultado, valor);
	return resultado;
}

