#ifndef PAGINAWEB_H
#define PAGINAWEB_H
#include <string>
#include <vector>
#include<iostream>
#include<Windows.h>
#include<sstream>
#include<ctime>
#include<fstream>

using namespace std;
class PaginaWeb{
private:
	string URL;
	string Titulo;
	string MarcadorPersonal;
	bool marcador;
	bool mostrada;
	time_t tiempoIngreso;
public:
	PaginaWeb(string, string);
	PaginaWeb();
	
	string getURL();
	string getTitulo();
	string getMarcadorPersonal();
	void setUrl(string u);
	bool getMarcador();

	void setMarcadorPersonal(string);

	bool yaMostrada();
	void marcarComoMostrada();
	void MostrarPaginaWeb();
	void PonerMarcador();
	void QuitarMarcador();

	time_t getTiempo();
	string mostrarTiempo();
	void setTiempo(time_t);

	void guardarPaginaWeb(ofstream&);
	PaginaWeb* leerPaginaWeb(ifstream&);

};
#endif
