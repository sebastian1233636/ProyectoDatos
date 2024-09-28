#ifndef ADMINPESTAÑAS_H
#define ADMINPESTAÑAS_H

#include"Pestaña.h"

struct NodoPest {
	Pestaña* pestaña;
	NodoPest* siguiente;
	NodoPest* anterior;
};

class AdminPestañas {
private:
	NodoPest* tail;//Primero
	NodoPest* head;//Ultimo
	int tam;
public:
	//Construtor y Destructor
	AdminPestañas();
	~AdminPestañas();

	//Metodos de lista
	NodoPest* getTail();
	NodoPest* getHead();
	void iniciarNavegador();
	void InsertarPrimero(Pestaña*);
	void ExplorarHistorialPestañas();
	void BuscarFavorito();
	int contadorPestañas();
	void menuAdminPestañas(NodoPest* actual);
	PaginaWeb* buscaPaginaWeb(string);

	//archivos
	void guardarPestañaBinario();
	void leerPestañaBinario();
	void guardarHistorialPestaña();
	void leerHistorialPestaña();
};
#endif
