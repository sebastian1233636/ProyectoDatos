#include "Marcador.h"

Marcador::Marcador(PaginaWeb* pag) :paginaWeb(pag) {}

void Marcador::agregarEtiqueta(const string& etiqueta) {
	etiquetas.push_back(etiqueta); 

}

void Marcador::mostrarMarcador() {
	paginaWeb->MostrarPaginaWeb(); 
	cout << "Etiquetas:";
	for (const auto& etiqueta: etiquetas) {
		cout << etiqueta << ""; 

	}
	cout << endl;
}

string Marcador::getURL() { return paginaWeb->getURL();  }

string Marcador::getTitulo() { return paginaWeb->getTitulo(); }

