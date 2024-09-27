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
class PaginaWeb {
private:
	string URL;
	string Titulo;
	string MarcadorPersonal;
	bool marcador;
	bool mostrada;
	time_t tiempoIngreso;
public:
	//CONSTRUCTORES
	PaginaWeb(string, string);
	PaginaWeb();

	//GETTERS
	string getURL();
	string getTitulo();
	string getMarcadorPersonal();
	bool getMarcador();
	time_t getTiempo();

	//SETTERS
	void setUrl(string u);
	void setTitulo(string);
	void setMarcadorPersonal(string);
	void setTiempo(time_t);

	//Metodos adicionales
	bool yaMostrada();
	void marcarComoMostrada();
	void MostrarPaginaWeb();
	void PonerMarcador();
	void QuitarMarcador();
	string mostrarTiempo();
	
	//archivos
	void guardarPaginaWeb(ofstream&);
	PaginaWeb* leerPaginaWeb(ifstream&);

};
#endif