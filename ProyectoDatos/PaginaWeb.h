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
<<<<<<< HEAD
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
=======
//Representa una página web con atributos como URL, título, estado de marcador, y tiempo de ingreso.
class PaginaWeb{
private:
	string URL;// Almacena la URL de la página web.
	string Titulo; // Almacena el título de la página web.
	bool marcador;// Indica si la página está marcada como favorita.
	bool mostrada;// Indica si la página ya ha sido mostrada (para evitar mostrarla repetidamente en ciertas operaciones).
	time_t tiempoIngreso;// Almacena el tiempo de ingreso (creación) de la página web.
public:
	// Constructores y destructor.
	PaginaWeb(string, string);
	PaginaWeb();
	// GETTERS
>>>>>>> documentacion interna
	string getURL();
	string getTitulo();
	string getMarcadorPersonal();
	bool getMarcador();
<<<<<<< HEAD
	time_t getTiempo();

	//SETTERS
	void setUrl(string u);
	void setTitulo(string);
	void setMarcadorPersonal(string);
	void setTiempo(time_t);

	//Metodos adicionales
=======
	// Método que indica si la página ya ha sido mostrada (para evitar mostrar duplicados).
>>>>>>> documentacion interna
	bool yaMostrada();
	// Marca la página como mostrada.
	void marcarComoMostrada();
	// Muestra la información de la página web (URL y título).
	void MostrarPaginaWeb();
	// Marca la página como favorita.
	void PonerMarcador();
	// Quita el marcador de la página (la desmarca como favorita).
	void QuitarMarcador();
<<<<<<< HEAD
	string mostrarTiempo();
	
	//archivos
	void guardarPaginaWeb(ofstream&);
	PaginaWeb* leerPaginaWeb(ifstream&);

=======
	// Devuelve el tiempo de ingreso de la página web.

	time_t getTiempo();
	// Devuelve el tiempo de ingreso de la página en formato legible.
	string mostrarTiempo();
	// Asigna un tiempo de ingreso específico a la página web.
	void setTiempo(time_t);
>>>>>>> documentacion interna
};
#endif