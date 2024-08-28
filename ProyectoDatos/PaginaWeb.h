#pragma once
#include<iostream>
using namespace std;
class PaginaWeb
{
private:
	string URL;
	string Titulo;
	bool marcador;
public:
	PaginaWeb(string, string);
	PaginaWeb();
	

	string getURL();
	string getTitulo();

	void MostrarPaginaWeb();
	void PonerMarcador();
};

