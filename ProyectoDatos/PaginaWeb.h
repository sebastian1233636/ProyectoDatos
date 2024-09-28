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
//Representa una p�gina web con atributos como URL, t�tulo, estado de marcador, y tiempo de ingreso.
class PaginaWeb{
private:
	string URL;// Almacena la URL de la p�gina web.
	string Titulo; // Almacena el t�tulo de la p�gina web.
	bool marcador;// Indica si la p�gina est� marcada como favorita.
	bool mostrada;// Indica si la p�gina ya ha sido mostrada (para evitar mostrarla repetidamente en ciertas operaciones).
	time_t tiempoIngreso;// Almacena el tiempo de ingreso (creaci�n) de la p�gina web.
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
	// M�todo que indica si la p�gina ya ha sido mostrada (para evitar mostrar duplicados).
>>>>>>> documentacion interna
	bool yaMostrada();
	// Marca la p�gina como mostrada.
	void marcarComoMostrada();
	// Muestra la informaci�n de la p�gina web (URL y t�tulo).
	void MostrarPaginaWeb();
	// Marca la p�gina como favorita.
	void PonerMarcador();
	// Quita el marcador de la p�gina (la desmarca como favorita).
	void QuitarMarcador();
<<<<<<< HEAD
	string mostrarTiempo();
	
	//archivos
	void guardarPaginaWeb(ofstream&);
	PaginaWeb* leerPaginaWeb(ifstream&);

=======
	// Devuelve el tiempo de ingreso de la p�gina web.

	time_t getTiempo();
	// Devuelve el tiempo de ingreso de la p�gina en formato legible.
	string mostrarTiempo();
	// Asigna un tiempo de ingreso espec�fico a la p�gina web.
	void setTiempo(time_t);
>>>>>>> documentacion interna
};
#endif