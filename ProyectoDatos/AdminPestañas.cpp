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
		cout << "No hay historial todavia" << endl;
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
				system("cls");
				break;
			}
			Sleep(100);
		}
	} 
}

int AdminPesta�as::contadorPesta�as() { return tam; }

void AdminPesta�as::menuAdminPesta�as(NodoPest* actual){
	int op = 0;
	int op2 = 0;
	int op4 = 0;
	bool incognito = false;
	bool control = true;
	bool control6 = true;
	bool control4 = true;
	while (control != false) {
		system("cls");
		if (actual->pesta�a->getIcognito() == false) {
		
			cout << actual->pesta�a->mostrarPesta�a() << endl;
			actual->pesta�a->explorarHistorial();
		}
		else { cout << actual->pesta�a->mostrarPesta�aIncognito() << endl; }
		cout << "---------------------------------------" << endl;
		cout << "1.Ir al sitio web" << endl;
		cout << "2.Nueva pesta�a" << endl;
		cout << "3.Modo incognito" << endl;
		cout << "4.Busquedas y filtros" << endl;
		cout << "5.Configuracion" << endl;
		cout << "6.Importacion y exportacion" << endl;
		cout << "7.Regresar" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Digite una opcion:";
		cin >> op;
		cout << endl;
		switch (op) {
		case 1: {
			string url;
			cout << "Digite el URL de la pagina:";
			cin >> url;
			cout << endl;
			PaginaWeb* PagNueva = buscaPaginaWeb(url);
			if (PagNueva == nullptr) { cout << "ERROR 404 NOT FOUND" << endl; }
			else { actual->pesta�a->insertarPrimero(*PagNueva);}
			system("pause");
			break;
		}
		case 2: {
			string nombrePesta�a = "Pestana " + to_string(tam + 1);
			Pesta�a* pes = new Pesta�a(nombrePesta�a);
			InsertarPrimero(pes);
            cout << "Se ha creado una nueva pesta�a. Siga las instrucciones anteriores para navegar a ella." << endl;
            system("pause");
			break;
		}
		case 3: {
			control4 = true;
			while (control4 != false) {
				system("cls");
				cout << "1.Activar modo incognito" << endl;
				cout << "2.Desactivar modo incognito" << endl;
				cout << "3.Regresar" << endl;
				cout << "Digite la opcion" << endl;
				cin >> op4;
				switch (op4) {
				case 1:
					actual->pesta�a->activarModoIncognito();
					if (actual->pesta�a->getIcognito() == true) {
						cout << "Modo incognito activado" << endl;
					}
					system("pause");
					break;
				case 2:
					actual->pesta�a->desactivarModoIncognito();
					if (actual->pesta�a->getIcognito() == false) {
						cout << "Modo incognito desactivado" << endl;
					}
					system("pause");
					break;
				case 3:
					control4 = false;
					break;
				}
			}
			break;
		}
		case 4:
			break;
		case 5:{
			//--------------------------------------------------------------------------------------
			control6 = true;
			while (control6 != false) {
				system("cls");
				cout << "---------------------------------------" << endl;
				cout << "1.Limitar cantidad de entradas" << endl;
				cout << "2.Eliminar historial cada cierto tiempo" << endl;
				cout << "3.Regresar" << endl;
				cout << "---------------------------------------" << endl;
				cin >> op2;
				switch (op2) {
				case 1: {
					int min = 0;
					cout << "Digite el numero de minutos" << endl;
					cin >> min;
					actual->pesta�a->timeFilter(min);
					system("pause");
					break;
				}
				case 2: {
					int mins = 0;
					cout << "En este opcion se elminar�n las paginas que superen los minutos ingresados" << endl;
					cout << "Digite los minutos deseados" << endl;
					cin >> mins;
					cout << "Eliminando paginas que superen los " << mins << " minutos" << endl;
					actual->pesta�a->eliminarCadaTiempo(mins);
					system("pause");
					break;
				}

				case 3: {
					control6 = false;
					break;
				}
				default:
					cout << "Opcion no valida" << endl;
					break;
				}
			}
			break;
		}
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

PaginaWeb* AdminPesta�as::buscaPaginaWeb(string urlBuscado){
	string archivo("Prueba.csv");
	ifstream file(archivo);
	PaginaWeb* pagAr = new PaginaWeb();
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
	else {
		string linea;
		while (getline(file, linea)) {
			stringstream ss(linea);
			string url;
			string titulo;
			if (getline(ss, url, ',') && getline(ss, titulo)) {
				if (url == urlBuscado) {
					 pagAr = new PaginaWeb(url, titulo);
					 return pagAr;
				}
				else { pagAr = nullptr; }
			}
		}
		file.close();
	}
	return nullptr;
}
