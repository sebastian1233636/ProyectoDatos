#ifndef PAGINAWEB_H
#define PAGINAWEB_H

#include<iostream>
#include<Windows.h>

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
	bool getFavorito();

	void MostrarPaginaWeb();
	void PonerMarcador();
};
#endif