#ifndef PESTAnA_H
#define PESTAnA_H

#include"PaginaWeb.h"
#include <fstream>
#include <wincrypt.h>
using namespace std;

struct NodoPag {
	PaginaWeb* paginaWeb;
	NodoPag* siguiente;
	NodoPag* anterior;
};

class Pestana {
private:
	NodoPag* tail;//Primero
	NodoPag* head;//Ultimo
	bool modoIcognito;
	string nombre;
public:
	//Constructores y Destructor
	Pestana(string);
	Pestana();
	~Pestana();


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
	string mostrarPestana();
	string mostrarPestanaIncognito();
	PaginaWeb* buscarPaginaWeb(string);
	void buscarPorPalabraClave(string);
	void mostrarFavoritos();
	void mostrarPorPalabraClave(string);
	void timeFilter(int);
	void eliminarCadaTiempo(int);
	void desactivarFiltros();
	void desactivarFiltroTiempo();

	//Archivos de Texto
	void guardarPestana(ofstream&);
	static Pestana* leerPestana(ifstream&);
	void guardarHistorial(ofstream&);
	void guardarHistorialParalelo(ofstream&);
	void leerHistorial(ifstream&);
	void leerHistorialParalelo(ifstream&);
};
#endif