#include "AdminPestanas.h"
#include<limits>
#include<ios>
#include<clocale>
#include <omp.h>

AdminPestanas::AdminPestanas() {
	tail = nullptr;
	head = nullptr;
	tam = 0;
}

AdminPestanas::~AdminPestanas() {
	NodoPest* aux = tail;
	while (aux != nullptr) {
		tail = tail->siguiente;
		delete aux->pestana;
		delete aux;
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}


NodoPest* AdminPestanas::getTail() { return tail; }

NodoPest* AdminPestanas::getHead() { return head; }


void AdminPestanas::iniciarNavegador() {
	setlocale(LC_ALL, "spanish");

	cout << "\x1B[36m\n  ***************************************************" << endl;
	cout << "  *                                                 *" << endl;
	cout << "  *       BIENVENIDO AL NAVEGADOR DE PESTAnAS       *" << endl;
	cout << "  *                                                 *" << endl;
	cout << "  ***************************************************\x1B[0m\n" << endl;

	if (tail == nullptr) {
		cout << "  > No hay pestanas todavia, agregando la primera...\n" << endl;
		string nombrePestana = "Pestana 0";
		Pestana* pes = new Pestana(nombrePestana);
		system("pause");
		InsertarPrimero(pes);
		ExplorarHistorialPestanas();
	}
	else {
		ExplorarHistorialPestanas();
	}
}

void AdminPestanas::InsertarPrimero(Pestana* pes) {
	NodoPest* nuevo = new NodoPest();
	nuevo->pestana = pes;
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

void AdminPestanas::BuscarFavorito() {
	NodoPest* nodoActual = tail;
	//Metodo que recorre la lista y llama al metodo "buscarFavorito" para obtener las paginas con marcador
	while (nodoActual != nullptr) {
		nodoActual->pestana->buscarFavorito();
		nodoActual = nodoActual->siguiente;
	}
}

void AdminPestanas::ExplorarHistorialPestanas() {
	bool bandera = true;  // Controla si el modo de exploración sigue activo
	NodoPest* nodoActual = tail;  // Comienza desde la primera pestana (tail)

	if (nodoActual == nullptr) {
		// Si no hay historial de pestanas, mostrar mensaje y salir
		cout << "No hay historial todavia" << endl;
		return;
	}

	while (bandera) {
		// Limpiar pantalla y mostrar el menú de administración de pestanas
		cout << "\x1B[2J\x1B[H";
		menuAdminPestanas(nodoActual);

		cout << "\x1B[2J\x1B[H";
		cout << "\x1B[36m\n  ===================================================\x1B[0m" << endl;
		cout << "\x1B[36m  ||          MODO NAVEGACION DE PESTAnAS          ||\x1B[0m" << endl;
		cout << "\x1B[36m  ===================================================\x1B[0m" << endl;
		if (nodoActual != nullptr && nodoActual->pestana != nullptr) {
			if (!nodoActual->pestana->getIcognito()) {
				cout << "  :: Pestana actual : \x1B[32m" << nodoActual->pestana->getNombre() << "\x1B[0m | (Total: " << tam << ")" << endl;
			} else {
				cout << "  :: Pestana actual : \x1B[35m[Modo Incognito Activo]\x1B[0m | (Total: " << tam << ")" << endl;
			}
		}
		cout << "\x1B[36m  ---------------------------------------------------\x1B[0m" << endl;
		cout << "    [ ^ ] FLECHA ARRIBA -> Siguiente pestana" << endl;
		cout << "    [ v ] FLECHA ABAJO  -> Pestana anterior" << endl;
		cout << "    [ N ] Letra N       -> Crear una nueva pestana" << endl;
		cout << "    [ESC]               -> Finalizar y salir" << endl;
		cout << "  ===================================================" << endl;
		cout << "\n  > Esperando accion de navegacion..." << endl;

		while (true) {
			// Moverse a la pestana anterior si se presiona flecha abajo
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

			// Moverse a la pestana siguiente si se presiona flecha arriba
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

			// Crear nueva pestana si se presiona N
			if (GetAsyncKeyState('N') & 0x8000) {
				string nombrePestana = "Pestana " + to_string(tam);
				Pestana* pes = new Pestana(nombrePestana);
				InsertarPrimero(pes);
				nodoActual = tail; // Se mueve automáticamente a la nueva pestana
				cout << "\x1B[32m\n  > Se ha creado una nueva pestana con exito.\x1B[0m" << endl;
				Sleep(500);  // Darle un breve tiempo para evitar registrarlo multiples veces
				break;
			}

			Sleep(100);  // Reducir la carga del sistema mientras se espera entrada
		}
	}
}

int AdminPestanas::contadorPestanas() { return tam; }

void AdminPestanas::menuAdminPestanas(NodoPest* actual) {

	if (actual == nullptr) {
		cout << "No hay pestanas todavia." << endl;
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
		if (actual->pestana->getIcognito() == false) {
			cout << "\x1B[36m  ||\x1B[0m   PESTAnA: \x1B[32m" << actual->pestana->getNombre() << "\x1B[0m" << endl;
		}
		else {
			cout << "\x1B[36m  ||\x1B[0m   \x1B[35m" << actual->pestana->mostrarPestanaIncognito() << "\x1B[0m" << endl;
		}
		cout << "\x1B[36m  =============================================\x1B[0m" << endl;

		cout << "    [1] Ver el historial de esta pestana" << endl;
		cout << "    [2] Ir a un sitio web (Escribir URL)" << endl;
		cout << "    [3] Opciones de modo incognito" << endl;
		cout << "    [4] Busquedas y filtros en la pestana" << endl;
		cout << "    [5] Configuracion del historial" << endl;
		cout << "    [6] Guardar / Cargar sesion" << endl;
		cout << "  ---------------------------------------------" << endl;
		cout << "    [7] <--- Navegar a otra pestana o Salir" << endl;
		cout << "  =============================================" << endl;
		cout << "  > ";
		int op = obtenerOpcion();
		cout << endl;
		switch (op) {

		case 1: {//Permite meterse al historial de cada pestana, a menos que sea incognito
			if (actual->pestana->getIcognito() == false) {

				actual->pestana->explorarHistorial();
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
			else if (actual->pestana->getIcognito() == false) {
				actual->pestana->insertarPrimero(*PagNueva);
				cout << "  \x1B[32m[+] Pagina cargada exitosamente\x1B[0m\n" << endl;
				actual->pestana->getTail()->paginaWeb->MostrarPaginaWeb();
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
				if (actual->pestana->getIcognito()) {
					cout << "    Estado actual: \x1B[32mACTIVO\x1B[0m\n" << endl;
				} else {
					cout << "    Estado actual: \x1B[31mINACTIVO\x1B[0m\n" << endl;
				}
				cout << "    [1] Activar modo incognito" << endl;
				cout << "    [2] Desactivar modo incognito" << endl;
				cout << "\x1B[35m  ---------------------------------------\x1B[0m" << endl;
				cout << "    [3] Regresar al menu de la pestana" << endl;
				cout << "\x1B[35m  =======================================\x1B[0m" << endl;
				cout << "  > ";
				int op3 = obtenerOpcion();
				switch (op3) {
				case 1:
					//Activa el modo incognito de la pestana
					actual->pestana->activarModoIncognito();
					if (actual->pestana->getIcognito() == true) {
						cout << "Modo incognito activado" << endl;
					}
					system("pause");
					break;
				case 2:
					//Desactiva el modo incognito de la pestana
					actual->pestana->desactivarModoIncognito();
					if (actual->pestana->getIcognito() == false) {
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
					actual->pestana->mostrarFavoritos();
					break;
				}

				case 2: {
					cout << "Digite la palabra clave para buscar en paginas" << endl;
					cout << "Se mostraran las paginas que contengan la palabra en el titulo o en la URL" << endl;
					cin >> palabraclave;
					actual->pestana->mostrarPorPalabraClave(palabraclave);
					break;
				}

				case 3: {
					PaginaWeb* pag;
					cout << "Digite el URL o el titulo de la pagina web" << endl;
					cin >> nom;
					pag = actual->pestana->buscarPaginaWeb(nom);
					if (pag == nullptr) {
						cout << "\x1B[31mLa pagina que busca no se encuentra\x1B[0m" << endl;
						system("pause");
					}
					else {
						pag->MostrarPaginaWeb();
						system("pause");
					}
					break;
				}
				case 4: {
					actual->pestana->desactivarFiltros();
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
					actual->pestana->timeFilter(min);
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
					actual->pestana->eliminarCadaTiempo(mins);
					cout << "  \x1B[32m[+] Paginas antiguas eliminadas.\x1B[0m\n" << endl;
					system("pause");
					break;
				}

				case 3: {
					actual->pestana->desactivarFiltroTiempo();
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
						guardarPestanaTexto();
						guardarHistorialPestanaTexto();
						cout << "\x1B[32mHistorial guardado exitosamente\x1B[0m" << endl;
						system("pause");
						break;
					}

					case 2: {
						leerPestanaTexto();
						leerHistorialPestanaTexto();
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

PaginaWeb* AdminPestanas::buscaPaginaWeb(string urlBuscado) {
	int numHilos = 8; 
	string archivo("Prueba.csv");

	ifstream tempFile(archivo, ios::ate | ios::binary);
	if (!tempFile.is_open()) {
		cout << "El archivo no se abrio" << endl;
		return nullptr;
	}
	streamoff fileSize = tempFile.tellg();
	tempFile.close();

	PaginaWeb* resultado = nullptr;
	bool encontrado = false;

	#pragma omp parallel num_threads(numHilos) shared(encontrado, resultado)
	{
		int idHilo = omp_get_thread_num();
		int totalHilos = omp_get_num_threads();

		streamoff chunkSize = fileSize / totalHilos;
		streamoff startPos = idHilo * chunkSize;
		streamoff endPos = (idHilo == totalHilos - 1) ? fileSize : (startPos + chunkSize);

		ifstream file(archivo, ios::binary);
		if (file.is_open()) {
			file.seekg(startPos);

			if (startPos != 0) {
				string descartado;
				getline(file, descartado);
			}

			streamoff currentPos = file.tellg();
			string linea;

			while (!encontrado && currentPos != -1 && currentPos < endPos && getline(file, linea)) {

				currentPos = file.tellg(); 

				if (!linea.empty() && linea.back() == '\r') {
					linea.pop_back();
				}

				if (linea.empty()) continue;

				size_t pos_coma = linea.find(',');

				if (pos_coma != string::npos) {
					if (linea.compare(0, pos_coma, urlBuscado) == 0) {

						string url = linea.substr(0, pos_coma);
						string titulo = linea.substr(pos_coma + 1);

						#pragma omp critical
						{
							if (!encontrado) {
								resultado = new PaginaWeb(url, titulo);
								encontrado = true;
							}
						}
					}
				}
			}
			file.close();
		}
	}
	return resultado;
}

int AdminPestanas::obtenerOpcion()
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

void AdminPestanas::guardarPestanaTexto() {
	ofstream file("Pestanas.txt");
	if (!file.is_open()) {
		cout << "El archivo no se abrio" << endl;
		return;
	}

	NodoPest* actual = tail;
	while (actual != nullptr) {
		actual->pestana->guardarPestana(file);
		actual = actual->siguiente;
	}
	file.close();
}

void AdminPestanas::leerPestanaTexto() {
	ifstream file("Pestanas.txt");
	if (!file.is_open()) {
		cout << "El archivo no se abrio" << endl;
		return;
	}

	// Guarda la primera pestana (la inicial del programa)
	NodoPest* pestanaInicial = head;

	while (true) {
		Pestana* pestana = new Pestana();
		Pestana* pes = pestana->leerPestana(file);
		if (pes == nullptr) {
			delete pestana;
			break;
		}
		InsertarPrimero(pes);
	}
	file.close();
}

void AdminPestanas::guardarHistorialPestanaTexto() {
	NodoPest* actual = tail;
	ofstream file;
	string nombre;

	while (actual != nullptr) {
		nombre = "Historial_" + actual->pestana->getNombre() + ".txt";
		file.open(nombre);
		if (!file.is_open()) {
			cout << "El archivo no se abrio" << endl;
		}
		actual->pestana->guardarHistorial(file);
		file.close();
		actual = actual->siguiente;
	}
}

void AdminPestanas::leerHistorialPestanaTexto() {
	NodoPest* actual = tail;
	ifstream file;
	string nombre;

	while (actual != nullptr && actual != head) {  // No tocar la pestana inicial (head)
		nombre = "Historial_" + actual->pestana->getNombre() + ".txt";
		file.open(nombre);
		if (!file.is_open()) {
			cout << "El archivo no se abrio" << endl;
		}
		actual->pestana->leerHistorial(file);
		file.close();
		actual = actual->siguiente;
	}
}
