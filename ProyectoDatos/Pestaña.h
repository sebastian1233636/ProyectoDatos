#ifndef PESTA�A_H
#define PESTA�A_H

#include"PaginaWeb.h"
#include <fstream>
#include <wincrypt.h>
using namespace std;

struct NodoPag {
	PaginaWeb* paginaWeb;
	NodoPag* siguiente;
	NodoPag* anterior;
};

class Pesta�a{
private:
	NodoPag* tail;//Primero
	NodoPag* head;//Ultimo
	bool modoIcognito;
	string nombre;
public:
	Pesta�a(string);
	~Pesta�a();
	bool getIcognito();
	void explorarHistorialIncognito();
	void cargarArchivoCSV(const string& archivoCVS);
	void guardarArchivoCSV(const string& archivoCSV);

	NodoPag* getTail();
	NodoPag* getHead();

	void insertarPrimero(PaginaWeb&);
	void explorarHistorial();
	void buscarFavorito();
	void activarModoIncognito(); 
	void desactivarModoIncognito(); 
	string mostrarPesta�a();
	string mostrarPesta�aIncognito();
	PaginaWeb* buscarPaginaWeb(string);
	void buscarPorPalabraClave(string&);
	void timeFilter(int);
	void eliminarCadaTiempo(int);

	void guardarHistorialBinario();
	void leerHistorialBinario();




};
#endif