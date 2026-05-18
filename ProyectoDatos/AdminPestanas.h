#ifndef ADMINPESTAnAS_H
#define ADMINPESTAnAS_H

#include"Pestana.h"
struct NodoPest {
	Pestana* pestana;
	NodoPest* siguiente;
	NodoPest* anterior;
};


//Clase encargada de administrar las pestanas del navegador, permitiendo crear nuevas pestanas, navegar entre ellas, 
//explorar su historial, buscar favoritos, y guardar/cargar la informacion en archivos de texto.
class AdminPestanas {
private:
	NodoPest* tail;//Primero
	NodoPest* head;//Ultimo
	int tam;
public:
	//Construtor y Destructor
	AdminPestanas();
	~AdminPestanas();

	//Metodos de lista
	NodoPest* getTail();
	NodoPest* getHead();
	void iniciarNavegador();
	void InsertarPrimero(Pestana*);
	void ExplorarHistorialPestanas();
	void BuscarFavorito();
	int contadorPestanas();
	void menuAdminPestanas(NodoPest* actual);
	PaginaWeb* buscaPaginaWeb(string);
	int obtenerOpcion();

	//Archivos
	void guardarPestanaTexto();
	void leerPestanaTexto();
	void guardarHistorialPestanaTexto();
	void leerHistorialPestanaTexto();

	//Metodos de Benchmark
	PaginaWeb* buscaPaginaWebEnArchivo(string urlBuscado, string nombreArchivo);

};
#endif
