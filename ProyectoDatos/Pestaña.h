#ifndef PESTA�A_H
#define PESTA�A_H

#include"PaginaWeb.h"
#include <fstream>
#include <wincrypt.h>
using namespace std;
// NodoPag representa un nodo de la lista doblemente enlazada que contiene p�ginas web.
struct NodoPag {
	PaginaWeb* paginaWeb;// Puntero a la p�gina web.
	NodoPag* siguiente;// Puntero al siguiente nodo de la lista.
	NodoPag* anterior; // Puntero al nodo anterior de la lista.
};
<<<<<<< HEAD

// Clase Pesta�a gestiona una lista de p�ginas web navegadas, incluyendo soporte para modo incognito.
class Pesta�a{
>>>>>>> documentacion interna
private:
	NodoPag* tail;//Primero
	NodoPag* head;//Ultimo
	bool modoIcognito;// Indica si el modo inc�gnito est� activado.
	string nombre;// Nombre de la pesta�a.
public:
<<<<<<< HEAD
	//Constructores y Destructor
=======
	// Constructores y destructor.
>>>>>>> documentacion interna
	Pesta�a(string);
	Pesta�a();
	~Pesta�a();
<<<<<<< HEAD
=======
	
	bool getIcognito();
	// M�todos para gestionar la lista de p�ginas.
	void explorarHistorialIcognito();// Explora el historial sin guardar nada (modo inc�gnito).
	void cargarArchivoCSV(const string& archivoCVS);// Lee los datos de una pesta�a desde un archivo.
	void guardarArchivoCSV(const string& archivoCSV); // Guarda los datos de la pesta�a en un archivo.
>>>>>>> documentacion interna


	//GETTERS
	NodoPag* getTail();
	NodoPag* getHead();
<<<<<<< HEAD
	string getNombre();
	bool getIcognito();
	//SETTERS
	void setNombre(string nom);
	//Metodos de lista
	void explorarHistorialIncognito();
	void insertarPrimero(PaginaWeb&); // Inserta una nueva p�gina en la primera posici�n.
	void explorarHistorial(); // Explora el historial permitiendo navegaci�n y marcadores.
	void buscarFavorito();// Busca p�ginas marcadas como favoritas.
	void activarModoIncognito();// Activa el modo inc�gnito.
	void desactivarModoIncognito();// Desactiva el modo inc�gnito.
	string mostrarPesta�a();// Muestra la informaci�n b�sica de la pesta�a
	string mostrarPesta�aIncognito();
	PaginaWeb* buscarPaginaWeb(string);
	void buscarPorPalabraClave(string&);
	void timeFilter(int);;// Filtra p�ginas por tiempo (en minutos).
	void eliminarCadaTiempo(int);

	//Archivos
	void guardarPesta�a(ofstream&);
	static Pesta�a* leerPesta�a(ifstream&);
=======


>>>>>>> documentacion interna

//Guarda el historial de la pesta�a en un archivo binario
	void guardarHistorialBinario(ofstream&);
//Lee el historial de la pesta�a desde un archivo binario.
	void leerHistorialBinario(ifstream&);
};
#endif