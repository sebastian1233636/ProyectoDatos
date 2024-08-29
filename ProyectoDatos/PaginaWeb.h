#ifndef PAGINAWEB_H
#define PAGINAWEB_H

#include<iostream>
#include<Windows.h>
#include<sstream>

using namespace std;

class PaginaWeb{
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
#endif