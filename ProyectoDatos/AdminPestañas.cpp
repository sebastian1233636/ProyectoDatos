#include "AdminPestañas.h"

AdminPestañas::AdminPestañas() {
	tail = nullptr;
	head = nullptr;
	tam = 0;
}

AdminPestañas::~AdminPestañas() {
	NodoPest* aux = tail;
	while (aux != nullptr) {
		tail = tail->siguiente;
		delete aux;
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}

NodoPest* AdminPestañas::getTail() { return tail; }

NodoPest* AdminPestañas::getHead() { return head; }

void AdminPestañas::InsertarPrimero(Pestaña* pes) {
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

void AdminPestañas::BuscarFavorito() {
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
		cout << "No hay historial todavia" << endl;
		return;
	}

	while (bandera) {
		system("cls");
		menuAdminPestañas(nodoActual);
		while (true) {
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				if (nodoActual->anterior == nullptr) {
					cout << "NO SE PUEDE RETROCEDER MAS" << endl;
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

int AdminPestañas::contadorPestañas() { return tam; }

void AdminPestañas::menuAdminPestañas(NodoPest* actual) {
	int op = 0;
	int op2 = 0;
	int op3 = 0;
	int op4 = 0;
	int op6 = 0;
	string nom = "";
	string palabraclave = "";
	bool incognito = false;
	bool control = true;
	bool control3 = true;
	bool control4 = true;
	bool control5 = true;
	bool control6 = true;
	while (control != false) {
		system("cls");
		if (actual->pestaña->getIcognito() == false) {

			cout << actual->pestaña->mostrarPestaña() << endl;
			actual->pestaña->explorarHistorial();
		}
		else { cout << actual->pestaña->mostrarPestañaIncognito() << endl; }
		cout << "---------------------------------------" << endl;
		cout << "1.Ir al sitio web" << endl;
		cout << "2.Nueva pestaña" << endl;
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
			else { actual->pestaña->insertarPrimero(*PagNueva); }
			system("pause");
			break;
		}
		case 2: {
			string nombrePestaña = "Pestana " + to_string(tam + 1);
			Pestaña* pes = new Pestaña(nombrePestaña);
			InsertarPrimero(pes);
			cout << "Se ha creado una nueva pestaña. Siga las instrucciones anteriores para navegar a ella." << endl;
			system("pause");
			break;
		}
		case 3: {
			control3 = true;
			while (control3 != false) {
				system("cls");
				cout << "1.Activar modo incognito" << endl;
				cout << "2.Desactivar modo incognito" << endl;
				cout << "3.Regresar" << endl;
				cout << "Digite la opcion" << endl;
				cin >> op3;
				switch (op3) {
				case 1:
					actual->pestaña->activarModoIncognito();
					if (actual->pestaña->getIcognito() == true) {
						cout << "Modo incognito activado" << endl;
					}
					system("pause");
					break;
				case 2:
					actual->pestaña->desactivarModoIncognito();
					if (actual->pestaña->getIcognito() == false) {
						cout << "Modo incognito desactivado" << endl;
					}
					system("pause");
					break;
				case 3: {
					control3 = false;
					break;
				}

				default:
					cout << "Opcion no valida" << endl;
					break;
				}

			}
			break;
		}
		case 4: {
			control4 = true;
			while (control4 != false) {
				cout << "---------------------------------------" << endl;
				cout << "1.Mostrar solo favoritos" << endl;
				cout << "2.Busqueda por palabra clave" << endl;
				cout << "3.Buscar una pagina especifica" << endl;
				cout << "4.regresar" << endl;
				cout << "---------------------------------------" << endl;
				cin >> op4;
				switch (op4) {

				case 1: {
					actual->pestaña->buscarFavorito();
					break;
				}

				case 2: {
					cout << "Digite la palabra clave para filtrar paginas" << endl;
					cin >> palabraclave;
					actual->pestaña->buscarPorPalabraClave(palabraclave);

					break;
				}

				case 3: {
					PaginaWeb* pag;
					cout << "Digite el URL o el titulo de la pagina web" << endl;
					cin >> nom;
					pag = actual->pestaña->buscarPaginaWeb(nom);
					if (pag == nullptr) {
						cout << "La pagina que busca no se encuentra" << endl;
					}
					else {
						pag->MostrarPaginaWeb();
					}
					break;
				}
				case 4: {
					control4 = false;
					break;
				}

				default:
					cout << "Opcion no valida" << endl;
					break;


				}
			}
			break;
		}
		case 5: {
			//--------------------------------------------------------------------------------------
			control5 = true;
			while (control5 != false) {
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
					actual->pestaña->timeFilter(min);
					system("pause");
					break;
				}
				case 2: {
					int mins = 0;
					cout << "En este opcion se elminarán las paginas que superen los minutos ingresados" << endl;
					cout << "Digite los minutos deseados" << endl;
					cin >> mins;
					cout << "Eliminando paginas que superen los " << mins << " minutos" << endl;
					actual->pestaña->eliminarCadaTiempo(mins);
					system("pause");
					break;
				}

				case 3: {
					control5 = false;
					break;
				}
				default:
					cout << "Opcion no valida" << endl;
					break;
				}
			}
			break;
		}
		case 6: {
			guardarPestañaBinario();
			guardarHistorialPestaña();
			cout << "Historial guardado" << endl;
			system("pause");
			break;
		}
		case 7:
			control = false;
			break;
		default:
			cout << "Opcion no valida" << endl;
			break;
		}
	}
}

PaginaWeb* AdminPestañas::buscaPaginaWeb(string urlBuscado) {
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

void AdminPestañas::guardarPestañaBinario() {
	ofstream file("Pestañas.bin", ios::binary);
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
	else {
		NodoPest* actual = tail;
		while (actual != nullptr) {
			actual->pestaña->guardarPestaña(file);
			actual = actual->siguiente;
		}
	}
	file.close();
}

void AdminPestañas::leerPestañaBinario() {
	ifstream file("Pestañas.bin", ios::binary);
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
	else {
		file.seekg(0, ios::end);
		std::streampos fileSize = file.tellg();
		file.seekg(0, ios::beg);
		while (file.tellg() < fileSize) {
			Pestaña* pestaña = new Pestaña();
			Pestaña* pes = pestaña->leerPestaña(file);
			if (pes != nullptr) { InsertarPrimero(pes); }
			else {
				cout << "Error al leer una pestaña del archivo." << endl;
				break;
			}
		}
	}
	file.close();
}

void AdminPestañas::guardarHistorialPestaña() {
	NodoPest* actual = tail;
	ofstream file;
	string nombre;
	while (actual != nullptr) {
		nombre = "Historial" + actual->pestaña->getNombre() + ".bin";
		file.open(nombre, ios::binary);
		if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
		actual->pestaña->guardarHistorialBinario(file);
		actual = actual->siguiente;
		file.close();
	}
}

void AdminPestañas::leerHistorialPestaña(){
	NodoPest* actual = tail;
	ifstream file;
	string nombre;
	while (actual != nullptr) {
		nombre = "Historial" + actual->pestaña->getNombre() + ".bin";
		file.open(nombre, ios::binary);
		if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
		actual->pestaña->leerHistorialBinario(file);
		actual = actual->siguiente;
		file.close();
	}
}
