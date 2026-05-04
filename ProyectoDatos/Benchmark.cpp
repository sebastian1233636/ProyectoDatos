#include "Benchmark.h"
#include "AdminPestanas.h"
#include "Pestana.h"
#include <iostream>
#include <fstream>
#include <omp.h>

using namespace std;

//---------------------------------------------------------------------------------
//Crea una pestaña global para pruebas, de esta manera no carga cada vez que se ejecuta una prueba, sino que se carga una sola vez al inicio del programa
Pestana benchmark("Benchmark");
void InicializarPestanaBenchmark() {
	ifstream file("Historial_Pestana 1.txt");
	if (!file.is_open()) {
		cout << "No se pudo abrir Historial_Pestana 1.txt" << endl;
		return;
	}
	benchmark.leerHistorial(file);
	file.close();
}

//---------------------------------------------------------------------------------




// Función para medir el tiempo de ejecución de una operación
void medirOperacion(string nombre, void (*operacion)()) {
	double inicio = omp_get_wtime();

	operacion();

	double fin = omp_get_wtime();
	double tiempoMs = (fin - inicio) * 1000.0;

	cout << nombre << ": " << tiempoMs << " ms" << endl;
}


// Busca una URL específica en el archivo CSV y mide el tiempo que tarda en encontrarla
void benchmarkBusquedaURLArchivoCSV() {
	AdminPestanas admin;

	PaginaWeb* resultado = admin.buscaPaginaWeb("www.groupglobal999999.com");

	if (resultado != nullptr) {
		delete resultado;
	}
}


// se cargan los datos del historial desde el archivo
void benchmarkCargaHistorialDesdeArchivo() {
	Pestana pestana("Benchmark");

	ifstream file("Historial_Pestana 1.txt");

	if (!file.is_open()) {
		cout << "No se pudo abrir Historial_Pestana 1.txt" << endl;
		return;
	}

	pestana.leerHistorial(file);

	file.close();
}

// se cargan los datos del historial desde el archivo en paralelo
void benchmarkCargaHistorialDesdeArchivoParalelo() {
	Pestana pestana("Benchmark");

	ifstream file("Historial_Pestana 1.txt");

	if (!file.is_open()) {
		cout << "No se pudo abrir Historial_Pestana 1.txt" << endl;
		return;
	}

	pestana.leerHistorialParalelo(file);

	file.close();
}



//Guarda el historial ya existente de la pestaña benchmark en un nuevo archivo de texto
void benchmarkGuardadoHistorial() {


	ofstream fileSalida("Historial_Benchmark_Salida.txt");

	if (!fileSalida.is_open()) {
		cout << "No se pudo crear Historial_Benchmark_Salida.txt" << endl;
		return;
	}

	benchmark.guardarHistorial(fileSalida);
	fileSalida.close();
}

//Guarda el historial usando el método paralelo
void benchmarkGuardadoHistorialParalelo() {
	ofstream fileSalida("Historial_Benchmark_Salida_Paralelo.txt");

	if (!fileSalida.is_open()) {
		cout << "No se pudo crear Historial_Benchmark_Salida_Paralelo.txt" << endl;
		return;
	}

	benchmark.guardarHistorialParalelo(fileSalida);
	fileSalida.close();
}



void benchmarkBusquedaPalabraClave() {
	benchmark.buscarPorPalabraClave("cloud");
}




void benchmarkFiltradoPorTiempo() {
	benchmark.timeFilter(10);
}



void benchmarkMostrarFavoritos() {
	benchmark.mostrarFavoritos();
}

void ejecutarBenchmarks() {
	cout << "==============================================" << endl;
	cout << "       PRUEBAS DE TIEMPO CON OPENMP           " << endl;
	cout << "==============================================" << endl;
	cout << "Cargando datos para las pruebas..." << endl;
	//InicializarPestanaBenchmark();
	/*medirOperacion("Busqueda por URL en archivo CSV", benchmarkBusquedaURLArchivoCSV);
	medirOperacion("Carga de historial y paginas desde archivo", benchmarkCargaHistorialDesdeArchivo);
	medirOperacion("Guardado de historial", benchmarkGuardadoHistorial);
	system("pause");
	medirOperacion("Busqueda por palabra clave", benchmarkBusquedaPalabraClave);
	system("pause");
	medirOperacion("Filtrado por tiempo", benchmarkFiltradoPorTiempo);
	system("pause");
	medirOperacion("Mostrar favoritos", benchmarkMostrarFavoritos);
	system("pause");*/

	/*
	cout << "==============================================" << endl;
	cout << "       PRUEBAS DE TIEMPO PARALELAS GUARDADO DE ARCHIVOS CON OPENMP" << endl;
	cout << "==============================================" << endl;
	medirOperacion("Guardado de historial (Secuencial)", benchmarkGuardadoHistorial);
	medirOperacion("Guardado de historial (Paralelo)", benchmarkGuardadoHistorialParalelo);
	cout << "==============================================" << endl;*/

	cout << "PRUEBAS DE TIEMPO PARALELAS CARGA DE ARCHIVOS CON OPENMP" << endl;
	medirOperacion("Carga de historial (Secuencial)", benchmarkCargaHistorialDesdeArchivo);
	medirOperacion("Carga de historial (Paralelo)", benchmarkCargaHistorialDesdeArchivoParalelo);
	cout << "==============================================" << endl;
	cout << "==============================================" << endl;
	cout << "          FIN DE LAS PRUEBAS                  " << endl;
	cout << "==============================================" << endl;
}