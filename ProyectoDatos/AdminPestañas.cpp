#include "AdminPestañas.h"

AdminPestañas::AdminPestañas(){
	tail = nullptr;
	head = nullptr;
	tam = 0;
}

AdminPestañas::~AdminPestañas(){
	NodoPest* aux = tail;
	while (aux != nullptr) {
		tail = tail->siguiente;
		delete aux;
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}

NodoPest* AdminPestañas::getTail() {return tail;}

NodoPest* AdminPestañas::getHead() {return head;}

void AdminPestañas::InsertarPrimero(Pestaña* pes){
	NodoPest* nuevo = new NodoPest();
	nuevo->pestaña = pes;
	if (tail == nullptr) {
		tail = head = nuevo;
		nuevo->siguiente;
		nuevo->anterior;
	}
	else {
		nuevo->siguiente = tail;
		tail->anterior = nuevo;
		tail = nuevo;
	}
	tam++;
}

void AdminPestañas::BuscarFavorito(){
	NodoPest* nodoActual = tail;
	while (nodoActual != nullptr) {
		nodoActual->pestaña->buscarFavorito();
		nodoActual = nodoActual->siguiente;
	}
}

void AdminPestañas::ExplorarHistorialPestañas() {
	bool bandera = true;
	NodoPest* nodoActual = tail;

	if (nodoActual == nullptr) {
		cout << "No hay historial todavía" << endl;
		return;
	}

	while (bandera) {
		system("cls");
		menuAdminPestañas(nodoActual);


		while (true) {
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				if (nodoActual->anterior == nullptr) {
					cout << "NO SE PUEDE AVANZAR MAS" << endl;
					system("pause");
				}
				else {
					nodoActual = nodoActual->anterior;
				}
				Sleep(200);
				break;
			}

			if (GetAsyncKeyState(VK_UP) & 0x8000) {
				if (nodoActual->siguiente == nullptr) {
					cout << "NO SE PUEDE AVANZAR MAS" << endl;
					system("pause");
				}
				else {
					nodoActual = nodoActual->siguiente;
				}
				Sleep(200);
				break;
			}

			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
				bandera = false;
				break;
			}
			Sleep(100);
		}
	}


}

int AdminPestañas::contadorPestañas()
{

	return tam;
}

void AdminPestañas::menuAdminPestañas(NodoPest* actual)
{
	int op = 0;
	bool control = true;
	while (control != false) {

		cout << actual->pestaña->mostrarPestaña() << endl;
		cout << "punto de control" << endl;
		actual->pestaña->explorarHistorial();

		cout << "---------------------------------------" << endl;
		cout << "1.Ir al sitio web" << endl;
		cout << "2.Nueva pestaña" << endl;
		cout << "3.Colocar Marcador" << endl;
		cout << "4.Modo incognito" << endl;
		cout << "5.Busquedas y filtros" << endl;
		cout << "6.Configuracion" << endl;
		cout << "7.Regresar" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Digite una opcion" << endl;
		cin >> op;
		switch (op) {
		case 1: {
			//hacer la busqueda en el excel y agregar la pagina web segun corresponda
			//si no esta lanzar 404 not found
			PaginaWeb* pag1 = new PaginaWeb("https://store.steampowered.com", "Steam");
			actual->pestaña->insertarPrimero(pag1);
			break;
		}
		case 2: {
			string nombrePestaña = "Pestaña " + to_string(tam + 1);
			Pestaña* pes = new Pestaña(nombrePestaña);
			InsertarPrimero(pes);
			break;
		}

		case 3: {

			PaginaWeb* pag2 = new PaginaWeb("https://onlyfans.com", "OnlyFans");
			actual->pestaña->insertarPrimero(pag2);


			break;
		}

		case 4:

			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			control = false;
			break;

		default:
			cout << "Opcion no valida" << endl;
			break;
		}
	}
}