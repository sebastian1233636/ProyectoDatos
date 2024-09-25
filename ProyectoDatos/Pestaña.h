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
	~Pestaña();
	bool getIcognito();
	void explorarHistorialIcognito();
	void cargarArchivoCSV(const string& archivoCVS);
	void guardarArchivoCSV(const string& archivoCSV);

	NodoPag* getTail();
	NodoPag* getHead();

	void insertarPrimero(PaginaWeb*);
	void explorarHistorial();
	void buscarFavorito();
	void activarModoIcognito(); 
	void desactivarModoIcognito(); 
	string mostrarPestaña();
	void timeFilter(int);
	void eliminarCadaTiempo(int);

};
#endif