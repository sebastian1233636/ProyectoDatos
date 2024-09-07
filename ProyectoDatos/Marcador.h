#pragma once

#ifndef MARCADOR_H
#define MARCADOR_H
#include <string>
#include <vector>
#include "PaginaWeb.h"
class Marcador {

private: 
	PaginaWeb* paginaWeb; 
   vector<string> etiquetas;


public: 
	Marcador(PaginaWeb*); 
	void agregarEtiqueta(const string&);
	void mostrarMarcador(); 
	string getURL(); 
	string getTitulo(); 



};
#endif MARCADOR_H




