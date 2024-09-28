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

class Pestaña {
private:
	NodoPag* tail;//Primero
	NodoPag* head;//Ultimo
	bool modoIcognito;
	string nombre;
public:
	//Constructores y Destructor
	Pestaña(string);
	Pestaña();
	~Pestaña();


	//GETTERS
	NodoPag* getTail();
	NodoPag* getHead();
	string getNombre();
	bool getIcognito();
	//SETTERS
	void setNombre(string nom);
	//Metodos de lista
	void explorarHistorialIncognito();
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

	//Archivos
	void guardarPestaña(ofstream&);
	static Pestaña* leerPestaña(ifstream&);

	void guardarHistorialBinario(ofstream&);
	void leerHistorialBinario(ifstream&);
};
#endif