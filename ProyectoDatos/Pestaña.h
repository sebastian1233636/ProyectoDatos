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

class Pesta�a {
private:
	NodoPag* tail;//Primero
	NodoPag* head;//Ultimo
	bool modoIcognito;
	string nombre;
public:
	//Constructores y Destructor
	Pesta�a(string);
	Pesta�a();
	~Pesta�a();


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
	string mostrarPesta�a();
	string mostrarPesta�aIncognito();
	PaginaWeb* buscarPaginaWeb(string);
	void buscarPorPalabraClave(string&);
	void timeFilter(int);
	void eliminarCadaTiempo(int);

	//Archivos
	void guardarPesta�a(ofstream&);
	static Pesta�a* leerPesta�a(ifstream&);

	void guardarHistorialBinario(ofstream&);
	void leerHistorialBinario(ifstream&);
};
#endif