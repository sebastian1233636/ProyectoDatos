#ifndef PESTAÑA_H
#define PESTAÑA_H

#include"PaginaWeb.h"
#include <fstream>
#include <wincrypt.h>
using namespace std;
// NodoPag representa un nodo de la lista doblemente enlazada que contiene páginas web.
struct NodoPag {
	PaginaWeb* paginaWeb;// Puntero a la página web.
	NodoPag* siguiente;// Puntero al siguiente nodo de la lista.
	NodoPag* anterior; // Puntero al nodo anterior de la lista.
};
<<<<<<< HEAD

// Clase Pestaña gestiona una lista de páginas web navegadas, incluyendo soporte para modo incognito.
class Pestaña{
>>>>>>> documentacion interna
private:
	NodoPag* tail;//Primero
	NodoPag* head;//Ultimo
	bool modoIcognito;// Indica si el modo incógnito está activado.
	string nombre;// Nombre de la pestaña.
public:
<<<<<<< HEAD
	//Constructores y Destructor
=======
	// Constructores y destructor.
>>>>>>> documentacion interna
	Pestaña(string);
	Pestaña();
	~Pestaña();
<<<<<<< HEAD
=======
	
	bool getIcognito();
	// Métodos para gestionar la lista de páginas.
	void explorarHistorialIcognito();// Explora el historial sin guardar nada (modo incógnito).
	void cargarArchivoCSV(const string& archivoCVS);// Lee los datos de una pestaña desde un archivo.
	void guardarArchivoCSV(const string& archivoCSV); // Guarda los datos de la pestaña en un archivo.
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
	void insertarPrimero(PaginaWeb&); // Inserta una nueva página en la primera posición.
	void explorarHistorial(); // Explora el historial permitiendo navegación y marcadores.
	void buscarFavorito();// Busca páginas marcadas como favoritas.
	void activarModoIncognito();// Activa el modo incógnito.
	void desactivarModoIncognito();// Desactiva el modo incógnito.
	string mostrarPestaña();// Muestra la información básica de la pestaña
	string mostrarPestañaIncognito();
	PaginaWeb* buscarPaginaWeb(string);
	void buscarPorPalabraClave(string&);
	void timeFilter(int);;// Filtra páginas por tiempo (en minutos).
	void eliminarCadaTiempo(int);

	//Archivos
	void guardarPestaña(ofstream&);
	static Pestaña* leerPestaña(ifstream&);
=======


>>>>>>> documentacion interna

//Guarda el historial de la pestaña en un archivo binario
	void guardarHistorialBinario(ofstream&);
//Lee el historial de la pestaña desde un archivo binario.
	void leerHistorialBinario(ifstream&);
};
#endif