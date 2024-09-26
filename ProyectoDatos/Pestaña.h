#ifndef PESTAÑA_H
#define PESTAÑA_H

#include"PaginaWeb.h"
#include <fstream>
#include <wincrypt.h>
using namespace std;

struct NodoPag {
	PaginaWeb* paginaWeb;
	NodoPag* siguiente;
	NodoPag* anterior;
};

class Pestaña{
private:
	NodoPag* tail;//Primero
	NodoPag* head;//Ultimo
	bool modoIcognito;
	string nombre;
public:
	Pestaña(string);
	Pestaña();
	~Pestaña();
	void setNombre(string nom);
	bool getIcognito();
	string getNombre();
	void explorarHistorialIncognito();

	NodoPag* getTail();
	NodoPag* getHead();

	void insertarPrimero(PaginaWeb&);
	void explorarHistorial();
	void buscarFavorito();
	void activarModoIncognito(); 
	void desactivarModoIncognito(); 
	string mostrarPestaña();
	string mostrarPestañaIncognito();
	PaginaWeb* buscarPaginaWeb(string);
	void buscarPorPalabraClave(string&);
	void timeFilter(int);
	void eliminarCadaTiempo(int);

	void guardarPestaña(ofstream&);
	Pestaña* leerPestaña(ifstream&);

	void guardarHistorialBinario(ofstream&);
	void leerHistorialBinario(ifstream&);
};
#endif
