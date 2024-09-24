#include "AdminPesta�as.h"

AdminPesta�as::AdminPesta�as(){
	tail = nullptr;
	head = nullptr;
	tam = 0;
}

AdminPesta�as::~AdminPesta�as(){
	NodoPest* aux = tail;
	while (aux != nullptr) {
		tail = tail->siguiente;
		delete aux;
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}

NodoPest* AdminPesta�as::getTail() {return tail;}

NodoPest* AdminPesta�as::getHead() {return head;}

void AdminPesta�as::InsertarPrimero(Pesta�a* pes){
	NodoPest* nuevo = new NodoPest();
	nuevo->pesta�a = pes;
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

void AdminPesta�as::BuscarFavorito(){
	NodoPest* nodoActual = tail;
	while (nodoActual != nullptr) {
		nodoActual->pesta�a->buscarFavorito();
		nodoActual = nodoActual->siguiente;
	}
}

void AdminPesta�as::ExplorarHistorialPesta�as() {
	bool bandera = true;
	NodoPest* nodoActual = tail;

	if (nodoActual == nullptr) {
		cout << "No hay historial todav�a" << endl;
		return;
	}

	while (bandera) {
		system("cls");
		menuAdminPesta�as(nodoActual);


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

int AdminPesta�as::contadorPesta�as()
{

	return tam;
}

void AdminPesta�as::menuAdminPesta�as(NodoPest* actual)
{
	int op = 0;
	bool control = true;
	while (control != false) {

		cout << actual->pesta�a->mostrarPesta�a() << endl;
		cout << "punto de control" << endl;
		actual->pesta�a->explorarHistorial();

		cout << "---------------------------------------" << endl;
		cout << "1.Ir al sitio web" << endl;
		cout << "2.Nueva pesta�a" << endl;
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
			actual->pesta�a->insertarPrimero(pag1);
			break;
		}
		case 2: {
			string nombrePesta�a = "Pesta�a " + to_string(tam + 1);
			Pesta�a* pes = new Pesta�a(nombrePesta�a);
			InsertarPrimero(pes);
			break;
		}

		case 3: {

			PaginaWeb* pag2 = new PaginaWeb("https://onlyfans.com", "OnlyFans");
			actual->pesta�a->insertarPrimero(pag2);


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