#include "AdminPestañas.h"
<<<<<<< HEAD

AdminPestañas::AdminPestañas() {
=======
// Constructor de la clase AdminPestañas.
// Inicializa los apuntadores 'tail' y 'head' en nullptr y el tamaño 'tam' en 0, indicando que la lista está vacía.
AdminPestañas::AdminPestañas(){
>>>>>>> documentacion interna
	tail = nullptr;
	head = nullptr;
	tam = 0;
}
<<<<<<< HEAD

AdminPestañas::~AdminPestañas() {
=======
// Destructor de la clase AdminPestañas.
// Libera la memoria de todos los nodos en la lista, eliminando todas las pestañas.
// Recorre desde 'tail' hacia adelante, eliminando los nodos uno por uno.
AdminPestañas::~AdminPestañas(){
>>>>>>> documentacion interna
	NodoPest* aux = tail;
	while (aux != nullptr) {
		tail = tail->siguiente;
		delete aux;
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}
<<<<<<< HEAD

NodoPest* AdminPestañas::getTail() { return tail; }

NodoPest* AdminPestañas::getHead() { return head; }

void AdminPestañas::InsertarPrimero(Pestaña* pes) {
=======
// Retorna el apuntador al nodo 'tail', que representa la pestaña más reciente.
NodoPest* AdminPestañas::getTail() {return tail;}
// Retorna el apuntador al nodo 'head', que representa la pestaña más antigua.
NodoPest* AdminPestañas::getHead() {return head;}
// Inserta una nueva pestaña al principio de la lista.
// Si la lista está vacía, 'tail' y 'head' apuntan al mismo nodo nuevo.
// Si no está vacía, el nuevo nodo se coloca antes del nodo actual de 'tail' y se actualiza el puntero.
void AdminPestañas::InsertarPrimero(Pestaña* pes){
>>>>>>> documentacion interna
	NodoPest* nuevo = new NodoPest();
	nuevo->pestaña = pes;
	if (tail == nullptr) {
		// Si la lista está vacía
		tail = head = nuevo;
		nuevo->siguiente;
		nuevo->anterior;
	}
	else {
		// Inserta el nodo antes de 'tail'
		nuevo->siguiente = tail;
		tail->anterior = nuevo;
		tail = nuevo;
	}
	tam++;
}
// Recorre la lista de pestañas desde 'tail' y busca aquellas que están marcadas como favoritas.
// Llama a la función buscarFavorito() de cada pestaña.

void AdminPestañas::BuscarFavorito() {
	NodoPest* nodoActual = tail;
	while (nodoActual != nullptr) {
		nodoActual->pestaña->buscarFavorito();
		nodoActual = nodoActual->siguiente;
	}
}
// Explora el historial de pestañas permitiendo al usuario navegar por las pestañas con las teclas de dirección.
// Se detiene cuando se llega a los extremos de la lista o cuando el usuario presiona 'ESC' para salir.

void AdminPestañas::ExplorarHistorialPestañas() {
	bool bandera = true;
	NodoPest* nodoActual = tail;
	// Si no hay historial, mostrar mensaje y terminar

	if (nodoActual == nullptr) {
		cout << "No hay historial todavia" << endl;
		return;
	}
	// Mientras el usuario no presione 'ESC', seguir explorando
	while (bandera) {
<<<<<<< HEAD
		system("cls");
		menuAdminPestañas(nodoActual);
=======
		system("cls");// Limpia la pantalla
		menuAdminPestañas(nodoActual);// Muestra el menú de administración de pestañas

		// Esperar a que el usuario presione una tecla para navegar o salir
>>>>>>> documentacion interna
		while (true) {
			// Navegar hacia la pestaña anterior con tecla abajo
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				if (nodoActual->anterior == nullptr) {
					cout << "NO SE PUEDE RETROCEDER MAS" << endl;
					system("pause");
				}
				else {
					nodoActual = nodoActual->anterior;
				}
				Sleep(200); // Pausa para evitar múltiples lecturas
				break;
			}
			// Navegar hacia la pestaña siguiente con tecla arriba

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
			// Salir del historial con tecla ESC

			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
				bandera = false;
				system("cls");
				break;
			}
			Sleep(100);
		}
	}
}

<<<<<<< HEAD
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
=======
// Devuelve el número total de pestañas en la lista.

int AdminPestañas::contadorPestañas()
{

	return tam;
}
// Muestra el menú de administración de pestañas para la pestaña actual.
// Permite al usuario realizar varias operaciones como ir al sitio web, crear una nueva pestaña, colocar un marcador, activar modo incógnito, etc.

void AdminPestañas::menuAdminPestañas(NodoPest* actual)
{
	int op = 0; // Opción seleccionada por el usuario
	bool incognito;// Indica si el modo incógnito está activado
	bool control = true; // Control para seguir mostrando el menú
	bool control6 = true;// Control para la opción 6 (configuración)
	// Control para la opción 6 (configuración)
>>>>>>> documentacion interna
	while (control != false) {
		system("cls");
		cout << "----------------" << actual->pestaña->getNombre() <<  "----------------" << endl;
		cout << "---------------------------------------" << endl;
		cout << "1.Ver historial" << endl;
		cout << "2.Ir al sitio web" << endl;
		cout << "3.Nueva pestaña" << endl;
		cout << "4.Modo incognito" << endl;
		cout << "5.Busquedas y filtros" << endl;
		cout << "6.Configuracion" << endl;
		cout << "7.Importacion y exportacion" << endl;
		cout << "8.Regresar" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Digite una opcion:";
		cin >> op;
<<<<<<< HEAD
		cout << endl;
=======
		// Switch para procesar la opción seleccionada
>>>>>>> documentacion interna
		switch (op) {

		case 1: {
			if (actual->pestaña->getIcognito() == false) {

				cout << actual->pestaña->mostrarPestaña() << endl;
				actual->pestaña->explorarHistorial();
			}
			else { cout << actual->pestaña->mostrarPestañaIncognito() << endl; }
			break;
			
		}

		case 2: {
<<<<<<< HEAD
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
		case 3: {
			string nombrePestaña = "Pestana " + to_string(tam + 1);
			Pestaña* pes = new Pestaña(nombrePestaña);
			InsertarPrimero(pes);
			cout << "Se ha creado una nueva pestaña. Siga las instrucciones anteriores para navegar a ella." << endl;
			system("pause");
=======
			// Crear una nueva pestaña
			string nombrePestaña = "Pestaña " + to_string(tam + 1);
			Pestaña* pes = new Pestaña(nombrePestaña);
			InsertarPrimero(pes);
			break;
		}

		
		case 3:{
			// Colocar un marcador, si no está en modo incógnito
			if (!incognito) {
				string marcador;
				cout << "Ingrese el nombre del marcador: ";
				cin >> marcador;
				NodoPag().paginaWeb->getMarcador();
				cout << "Marcador agregado: " << marcador << endl;
			}
			else {
				cout << "La opción de marcadores no está disponible en modo incógnito." << endl;
			}


>>>>>>> documentacion interna
			break;
		}
		case 4: {
<<<<<<< HEAD
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
=======
			// Activar/desactivar modo incógnito
>>>>>>> documentacion interna

				default:
					cout << "Opcion no valida" << endl;
					break;
				}

			}
			break;
		}
		case 5: {
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
		case 6: {
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
		case 7: {
			guardarPestañaBinario();
			guardarHistorialPestaña();
			cout << "Historial guardado" << endl;
			system("pause");
			break;
		}
		case 8:
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
