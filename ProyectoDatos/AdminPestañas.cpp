#include "AdminPestañas.h"
#include<limits>
#include<ios>
#include<clocale>

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


void AdminPestañas::iniciarNavegador() {
	setlocale(LC_ALL, "spanish");

	cout << "\x1B[36m\n  ***************************************************" << endl;
	cout << "  *                                                 *" << endl;
	cout << "  *       BIENVENIDO AL NAVEGADOR DE PESTAÑAS       *" << endl;
	cout << "  *                                                 *" << endl;
	cout << "  ***************************************************\x1B[0m\n" << endl;

	if (tail == nullptr) {
		cout << "  > No hay pestañas todavia, agregando la primera...\n" << endl;
		string nombrePestaña = "Pestana " + to_string(tam + 1);
		Pestaña* pes = new Pestaña(nombrePestaña);
		system("pause");
		InsertarPrimero(pes);
		ExplorarHistorialPestañas();
	}
	else {
		ExplorarHistorialPestañas();
	}
}

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
	//Metodo que recorre la lista y llama al metodo "buscarFavorito" para obtener las paginas con marcador
	while (nodoActual != nullptr) {
		nodoActual->pestaña->buscarFavorito();
		nodoActual = nodoActual->siguiente;
	}
}

void AdminPestañas::ExplorarHistorialPestañas() {
	bool bandera = true;  // Controla si el modo de exploración sigue activo
	NodoPest* nodoActual = tail;  // Comienza desde la primera pestaña (tail)

	if (nodoActual == nullptr) {
		// Si no hay historial de pestañas, mostrar mensaje y salir
		cout << "No hay historial todavia" << endl;
		return;
	}

	while (bandera) {
		// Limpiar pantalla y mostrar el menú de administración de pestañas
		cout << "\x1B[2J\x1B[H";
		menuAdminPestañas(nodoActual);

		cout << "\x1B[2J\x1B[H";
		cout << "\x1B[36m\n  ===================================================\x1B[0m" << endl;
		cout << "\x1B[36m  ||          MODO NAVEGACION DE PESTAÑAS          ||\x1B[0m" << endl;
		cout << "\x1B[36m  ===================================================\x1B[0m" << endl;
		if (nodoActual != nullptr && nodoActual->pestaña != nullptr) {
			if (!nodoActual->pestaña->getIcognito()) {
				cout << "  :: Pestaña actual : \x1B[32m" << nodoActual->pestaña->getNombre() << "\x1B[0m | (Total: " << tam << ")" << endl;
			} else {
				cout << "  :: Pestaña actual : \x1B[35m[Modo Incognito Activo]\x1B[0m | (Total: " << tam << ")" << endl;
			}
		}
		cout << "\x1B[36m  ---------------------------------------------------\x1B[0m" << endl;
		cout << "    [ ^ ] FLECHA ARRIBA -> Siguiente pestaña" << endl;
		cout << "    [ v ] FLECHA ABAJO  -> Pestaña anterior" << endl;
		cout << "    [ N ] Letra N       -> Crear una nueva pestaña" << endl;
		cout << "    [ESC]               -> Finalizar y salir" << endl;
		cout << "  ===================================================" << endl;
		cout << "\n  > Esperando accion de navegacion..." << endl;

		while (true) {
			// Moverse a la pestaña anterior si se presiona flecha abajo
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				if (nodoActual->anterior == nullptr) {
					cout << "NO SE PUEDE RETROCEDER MAS" << endl;
					system("pause");
				}
				else {
					nodoActual = nodoActual->anterior;
				}
				Sleep(200);  // Evitar detección continua de la tecla
				break;
			}

			// Moverse a la pestaña siguiente si se presiona flecha arriba
			if (GetAsyncKeyState(VK_UP) & 0x8000) {
				if (nodoActual->siguiente == nullptr) {
					cout << "NO SE PUEDE AVANZAR MAS" << endl;
					system("pause");
				}
				else {
					nodoActual = nodoActual->siguiente;
				}
				Sleep(200);  // Evitar detección continua de la tecla
				break;
			}

			// Salir si se presiona ESC
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
				bandera = false;  // Finalizar el bucle principal
				cout << "\x1B[2J\x1B[H";  // Limpiar pantalla al salir
				break;
			}

			// Crear nueva pestaña si se presiona N
			if (GetAsyncKeyState('N') & 0x8000) {
				string nombrePestaña = "Pestana " + to_string(tam + 1);
				Pestaña* pes = new Pestaña(nombrePestaña);
				InsertarPrimero(pes);
				nodoActual = tail; // Se mueve automáticamente a la nueva pestaña
				cout << "\x1B[32m\n  > Se ha creado una nueva pestaña con exito.\x1B[0m" << endl;
				Sleep(500);  // Darle un breve tiempo para evitar registrarlo multiples veces
				break;
			}

			Sleep(100);  // Reducir la carga del sistema mientras se espera entrada
		}
	}
}

int AdminPestañas::contadorPestañas() { return tam; }

void AdminPestañas::menuAdminPestañas(NodoPest* actual) {

	if (actual == nullptr) {
		cout << "No hay pestañas todavia." << endl;
		return; 
	}

	bool control = true;
	bool control3 = true;
	bool control4 = true;
	bool control5 = true;
	bool controlAr = true;
	string estadoFiltroTiempo = "INACTIVO";
	string detalleFiltro = "";
	string nom = "";
	string palabraclave = "";
	while (control != false) {
		cout << "\x1B[2J\x1B[H";
		//Menu principal del programa
		cout << "\x1B[36m\n  =============================================\x1B[0m" << endl;
		if (actual->pestaña->getIcognito() == false) {
			cout << "\x1B[36m  ||\x1B[0m   PESTAÑA: \x1B[32m" << actual->pestaña->getNombre() << "\x1B[0m" << endl;
		}
		else {
			cout << "\x1B[36m  ||\x1B[0m   \x1B[35m" << actual->pestaña->mostrarPestañaIncognito() << "\x1B[0m" << endl;
		}
		cout << "\x1B[36m  =============================================\x1B[0m" << endl;

		cout << "    [1] Ver el historial de esta pestaña" << endl;
		cout << "    [2] Ir a un sitio web (Escribir URL)" << endl;
		cout << "    [3] Opciones de modo incognito" << endl;
		cout << "    [4] Busquedas y filtros en la pestaña" << endl;
		cout << "    [5] Configuracion del historial" << endl;
		cout << "    [6] Guardar / Cargar sesion" << endl;
		cout << "  ---------------------------------------------" << endl;
		cout << "    [7] <--- Navegar a otra pestaña o Salir" << endl;
		cout << "  =============================================" << endl;
		cout << "  > ";
		int op = obtenerOpcion();
		cout << endl;
		switch (op) {

		case 1: {//Permite meterse al historial de cada pestaña, a menos que sea incognito
			if (actual->pestaña->getIcognito() == false) {

				actual->pestaña->explorarHistorial();
			}
			else { 
				cout << "\x1B[2J\x1B[H";
				cout << "\n  \x1B[35m[!] No hay historial en este modo.\x1B[0m\n" << endl;
				system("pause");
			}
			break;

		}

		case 2: {
			string url;
			cout << "\x1B[2J\x1B[H";
			cout << "\x1B[36m\n  =======================================================\x1B[0m" << endl;
			cout << "\x1B[36m  ||                IR A UN SITIO WEB                  ||\x1B[0m" << endl;
			cout << "\x1B[36m  =======================================================\x1B[0m" << endl;
			cout << "  > Digite el URL de la pagina (Ej. devdocs.io): ";
			cin >> url;

			cout << "\n  \x1B[33m[~] Buscando el dominio...\x1B[0m";
			Sleep(800);
			cout << "\x1B[2J\x1B[H";

			PaginaWeb* PagNueva = buscaPaginaWeb(url);
			if (PagNueva == nullptr) {
				cout << "\x1B[31m\n  =======================================================\x1B[0m" << endl;
				cout << "\x1B[31m  ||           ERROR 404 - SITE NOT FOUND              ||\x1B[0m" << endl;
				cout << "\x1B[31m  =======================================================\x1B[0m" << endl;
				cout << "  \x1B[31m[!] El dominio en la URL ingresada no existe o no responde.\x1B[0m\n" << endl;
			}
			else if (actual->pestaña->getIcognito() == false) {
				actual->pestaña->insertarPrimero(*PagNueva);
				cout << "  \x1B[32m[+] Pagina cargada exitosamente\x1B[0m\n" << endl;
				actual->pestaña->getTail()->paginaWeb->MostrarPaginaWeb();
			}
			else {
				cout << "  \x1B[32m[+] Pagina cargada exitosamente\x1B[0m\n" << endl;
				PagNueva->MostrarPaginaWeb();
			}
			cout << endl;
			system("pause");
			break;
		}
		case 3: {
			//Menu para el modo incognito
			control3 = true;
			while (control3 != false) {
				cout << "\x1B[2J\x1B[H";
				cout << "\x1B[35m\n  =======================================\x1B[0m" << endl;
				cout << "\x1B[35m  ||         MODO INCOGNITO            ||\x1B[0m" << endl;
				cout << "\x1B[35m  =======================================\x1B[0m" << endl;
				if (actual->pestaña->getIcognito()) {
					cout << "    Estado actual: \x1B[32mACTIVO\x1B[0m\n" << endl;
				} else {
					cout << "    Estado actual: \x1B[31mINACTIVO\x1B[0m\n" << endl;
				}
				cout << "    [1] Activar modo incognito" << endl;
				cout << "    [2] Desactivar modo incognito" << endl;
				cout << "\x1B[35m  ---------------------------------------\x1B[0m" << endl;
				cout << "    [3] Regresar al menu de la pestaña" << endl;
				cout << "\x1B[35m  =======================================\x1B[0m" << endl;
				cout << "  > ";
				int op3 = obtenerOpcion();
				switch (op3) {
				case 1:
					//Activa el modo incognito de la pestaña
					actual->pestaña->activarModoIncognito();
					if (actual->pestaña->getIcognito() == true) {
						cout << "Modo incognito activado" << endl;
					}
					system("pause");
					break;
				case 2:
					//Desactiva el modo incognito de la pestaña
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
				cout << "\x1B[2J\x1B[H";
				//Menu para manejar las busquedas y filtros
				cout << "\x1B[36m\n  =================================================\x1B[0m" << endl;
				cout << "\x1B[36m  ||             BUSQUEDAS Y FILTROS             ||\x1B[0m" << endl;
				cout << "\x1B[36m  =================================================\x1B[0m" << endl;
				cout << "    [1] Mostrar solo paginas favoritas" << endl;
				cout << "    [2] Busqueda por palabra clave en URL/Titulo" << endl;
				cout << "    [3] Buscar una pagina especifica" << endl;
				cout << "    [4] Desactivar cualquier filtro activo" << endl;
				cout << "\x1B[36m  -------------------------------------------------\x1B[0m" << endl;
				cout << "    [5] Regresar" << endl;
				cout << "\x1B[36m  =================================================\x1B[0m" << endl;
				cout << "  > ";
				int op4 = obtenerOpcion();
				switch (op4) {

				case 1: {
					cout << "\x1B[2J\x1B[H";
					actual->pestaña->buscarFavorito();
					system("pause");
					break;
				}

				case 2: {
					cout << "Digite la palabra clave para filtrar paginas" << endl;
					cout << "Se enseñaran solo las paginas que tenga la palabra que usted digite ya sea en el titulo o en la URL" << endl;
					cin >> palabraclave;
					cout << "\x1B[2J\x1B[H";
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
						system("pause");
					}
					break;
				}
				case 4: {
					actual->pestaña->desactivarFiltros();
					cout << "Filtro por palabra clave desactivado" << endl;
					system("pause");
					break;
				}

				case 5: {
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
			control5 = true;
			while (control5 != false) {
				cout << "\x1B[2J\x1B[H";
				//Menu para manejar las politicas del historial
				cout << "\x1B[36m\n  =======================================================\x1B[0m" << endl;
				cout << "\x1B[36m  ||            CONFIGURACION DEL HISTORIAL            ||\x1B[0m" << endl;
				cout << "\x1B[36m  =======================================================\x1B[0m" << endl;
				if (estadoFiltroTiempo == "ACTIVO") {
					cout << "    Estado actual: \x1B[32mACTIVO\x1B[0m " << detalleFiltro << "\n" << endl;
				} else {
					cout << "    Estado actual: \x1B[31mINACTIVO\x1B[0m\n" << endl;
				}
				cout << "    [1] Limitar entradas por antiguedad (ej. N minutos)" << endl;
				cout << "    [2] Eliminar historial que exceda cierta antiguedad" << endl;
				cout << "    [3] Desactivar filtro de tiempo" << endl;
				cout << "\x1B[36m  -------------------------------------------------------\x1B[0m" << endl;
				cout << "    [4] Regresar" << endl;
				cout << "\x1B[36m  =======================================================\x1B[0m" << endl;
				cout << "  > ";
				int op2 = obtenerOpcion();
				switch (op2) {
				case 1: {
					int min = 0;
					cout << "\x1B[2J\x1B[H";
					cout << "\x1B[36m\n  =======================================================\x1B[0m" << endl;
					cout << "\x1B[36m  ||                FILTRAR POR TIEMPO                 ||\x1B[0m" << endl;
					cout << "\x1B[36m  =======================================================\x1B[0m" << endl;
					cout << "  > Esta funcion ocultara las entradas mas antiguas que el tiempo especificado." << endl;
					cout << "  > Digite el numero de minutos: ";
					cin >> min;
					actual->pestaña->timeFilter(min);
					estadoFiltroTiempo = "ACTIVO";
					detalleFiltro = "(Limitando a " + to_string(min) + " min)";
					cout << "\n  \x1B[32m[+] Filtro aplicado con exito.\x1B[0m\n" << endl;
					system("pause");
					break;
				}
				case 2: {
					int mins = 0;
					cout << "\x1B[2J\x1B[H";
					cout << "\x1B[31m\n  =======================================================\x1B[0m" << endl;
					cout << "\x1B[31m  ||           ELIMINAR HISTORIAL POR TIEMPO           ||\x1B[0m" << endl;
					cout << "\x1B[31m  =======================================================\x1B[0m" << endl;
					cout << "  > En esta opcion se ELIMINARAN permanentemente las paginas." << endl;
					cout << "  > Digite los minutos limite de antiguedad: ";
					cin >> mins;
					cout << "\n  Eliminando paginas que superen los " << mins << " minutos...\n" << endl;
					actual->pestaña->eliminarCadaTiempo(mins);
					cout << "  \x1B[32m[+] Paginas antiguas eliminadas.\x1B[0m\n" << endl;
					system("pause");
					break;
				}

				case 3: {
					actual->pestaña->desactivarFiltroTiempo();
					estadoFiltroTiempo = "INACTIVO";
					detalleFiltro = "";
					cout << "\x1B[32mFiltro por tiempo desactivado exitosamente.\x1B[0m" << endl;
					system("pause");
					break;
				}

				case 4: {
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
			//archivos
			controlAr = true;
			while (controlAr != false) {
				cout << "\x1B[2J\x1B[H";
				cout << "\x1B[36m\n  ===========================================\x1B[0m" << endl;
				cout << "\x1B[36m  ||        GUARDAR / CARGAR SESION        ||\x1B[0m" << endl;
				cout << "\x1B[36m  ===========================================\x1B[0m" << endl;
				cout << "    [1] Guardar sesion actual y el historial" << endl;
				cout << "    [2] Cargar sesion guardada previamente" << endl;
				cout << "\x1B[36m  -------------------------------------------\x1B[0m" << endl;
				cout << "    [3] Regresar" << endl;
				cout << "\x1B[36m  ===========================================\x1B[0m" << endl;
				cout << "  > ";
				int opAr = obtenerOpcion();
				switch (opAr) {


					case 1: {
						guardarPestañaBinario();
						guardarHistorialPestaña();
						cout << "\x1B[32mHistorial guardado exitosamente\x1B[0m" << endl;
						system("pause");
						break;
					}

					case 2: {
						leerPestañaBinario();
						leerHistorialPestaña();
						cout << "\x1B[32mSesion cargada exitosamente\x1B[0m" << endl;
						system("pause");
						break;
					}

					case 3: {
						controlAr = false;
						break;
					}
				}
			}

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

	if (!file.is_open()) {
		cout << "El archivo no se abrio" << endl;
		return nullptr;
	}

	string linea;
	while (getline(file, linea)) {
		stringstream ss(linea);
		string url;
		string titulo;

		if (getline(ss, url, ',') && getline(ss, titulo)) {
			if (url == urlBuscado) {
				PaginaWeb* pagAr = new PaginaWeb(url, titulo);
				file.close();
				return pagAr;
			}
		}
	}

	file.close();
	return nullptr;
}

int AdminPestañas::obtenerOpcion()
{
	int op;
	cout << "Ingrese una opcion: ";
	cin >> op;

	// Si la entrada no es un número entero
	while (cin.fail()) {
		cin.clear();  // Limpia el estado de error de cin
		cin.ignore(1000, '\n');  // Ignora hasta 1000 caracteres o hasta un salto de línea
		cout << "Entrada invalida. Por favor, ingrese un numero: ";
		cin >> op;
	}

	return op;  // Retorna la opción válida
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
		if (!file.is_open()) {
			cout << "El archivo no se abrio" << endl;
		}
		actual->pestaña->guardarHistorialBinario(file);
		file.close();
		actual = actual->siguiente;
	}
}

void AdminPestañas::leerHistorialPestaña() {
	NodoPest* actual = tail;
	ifstream file;
	string nombre;

	while (actual != nullptr) {
		nombre = "Historial" + actual->pestaña->getNombre() + ".bin";
		file.open(nombre, ios::binary);
		if (!file.is_open()) {
			cout << "El archivo no se abrio" << endl;
		}
		actual->pestaña->leerHistorialBinario(file);
		file.close();
		actual = actual->siguiente;
	}
}
