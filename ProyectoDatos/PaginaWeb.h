#pragma once
#include<iostream>
using namespace std;
class PaginaWeb
{
public:
	string URL;
	string Titulo;
	bool marcador;
private:
	PaginaWeb(string, string);
	PaginaWeb();
	PaginaWeb(PaginaWeb&);

	string getURL();
	string getTitulo();

	void MostrarPaginaWeb();
	void PonerMarcador();
};

