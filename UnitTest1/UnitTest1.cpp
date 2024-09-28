#include "pch.h"
#include "CppUnitTest.h"
#include"../ProyectoDatos/PaginaWeb.cpp"
#include"../ProyectoDatos/Pesta�a.cpp"
#include"../ProyectoDatos/AdminPesta�as.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		

		TEST_METHOD(TestTiempo)
		{
			PaginaWeb pagina;
			time_t tiempoActual = time(0);

			pagina.setTiempo(tiempoActual);

			Assert::AreEqual(tiempoActual, pagina.getTiempo());
		}

		TEST_METHOD(TestArchivos)
		{
			
			PaginaWeb pagina("www:algo.com", "algo");
			pagina.setMarcadorPersonal("Marcador");
			pagina.PonerMarcador();
			time_t tiempoActual = time(0);
			pagina.setTiempo(tiempoActual);

			
			ofstream fileOut("testPaginaWeb.bin", ios::binary);
			pagina.guardarPaginaWeb(fileOut);
			fileOut.close();

			
			ifstream fileIn("testPaginaWeb.bin", ios::binary);
			PaginaWeb* paginaLeida = pagina.leerPaginaWeb(fileIn);
			fileIn.close();

			
			Assert::AreEqual(pagina.getURL(), paginaLeida->getURL());
			Assert::AreEqual(pagina.getTitulo(), paginaLeida->getTitulo());
			Assert::AreEqual(pagina.getMarcadorPersonal(), paginaLeida->getMarcadorPersonal());
			Assert::AreEqual(pagina.getMarcador(), paginaLeida->getMarcador());
			Assert::AreEqual(pagina.getTiempo(), paginaLeida->getTiempo());

			
			delete paginaLeida;
		}


	};



	TEST_CLASS(UnitTestPesta�a)
	{
	public:

		TEST_METHOD(TestInsertar)
		{
			Pesta�a pesta�a;
			PaginaWeb pagina("www:algo.com", "Example");

			pesta�a.insertarPrimero(pagina);

			Assert::IsNotNull(pesta�a.getTail());
			Assert::IsNotNull(pesta�a.getHead());
			Assert::AreEqual(pesta�a.getTail()->paginaWeb->getURL(), std::string("www:algo.com"));
		}

		// Test activar/desactivar modo inc�gnito
		TEST_METHOD(TestIncognito)
		{
			Pesta�a pesta�a;
			pesta�a.activarModoIncognito();
			Assert::IsTrue(pesta�a.getIcognito());

			pesta�a.desactivarModoIncognito();
			Assert::IsFalse(pesta�a.getIcognito());
		}

		// Test guardar y leer pesta�a
		TEST_METHOD(TestArchivosPesta�a)
		{
			
			ofstream archivoGuardar("pesta�a.bin", ios::binary);
			Pesta�a pesta�a("TestPesta�a");
			pesta�a.guardarPesta�a(archivoGuardar);
			archivoGuardar.close();

			ifstream archivoLeer("pesta�a.bin", ios::binary);
			Pesta�a* pesta�aLeida = Pesta�a::leerPesta�a(archivoLeer);
			archivoLeer.close();

			Assert::AreEqual(pesta�aLeida->getNombre(), std::string("TestPesta�a"));
			delete pesta�aLeida;
		}

		TEST_METHOD(TestBuscarFavorito)
		{
		
			Pesta�a pesta�a;
			PaginaWeb pagina1("www.pagina1.com", "P�gina 1");
			PaginaWeb pagina2("www.pagina2.com", "P�gina 2");
			PaginaWeb pagina3("www.pagina3.com", "P�gina 3");

			
			pagina1.PonerMarcador();
			pagina3.PonerMarcador();

			
			pesta�a.insertarPrimero(pagina1);
			pesta�a.insertarPrimero(pagina2);
			pesta�a.insertarPrimero(pagina3);

			
			pesta�a.buscarFavorito();

			
			Assert::IsTrue(pagina1.yaMostrada());
			Assert::IsFalse(pagina2.yaMostrada());
			Assert::IsTrue(pagina3.yaMostrada());

		}

		TEST_METHOD(TestBuscarPagina)
		{
			Pesta�a pesta�a;
			PaginaWeb pagina1("www.pagina1.com", "Pagina 1");
			PaginaWeb pagina2("www.pagina2.com", "Pagina 2");
			PaginaWeb pagina3("www.pagina3.com", "Pagina 3");

			pesta�a.insertarPrimero(pagina1);
			pesta�a.insertarPrimero(pagina2);
			pesta�a.insertarPrimero(pagina3);

			PaginaWeb* resultado = pesta�a.buscarPaginaWeb("www.pagina1.com");
			Assert::IsNotNull(resultado);
			Assert::AreEqual(string("Pagina 1"), resultado->getTitulo());

			resultado = pesta�a.buscarPaginaWeb("Pagina 2");
			Assert::IsNotNull(resultado);
			Assert::AreEqual(string("www.pagina2.com"), resultado->getURL());

			resultado = pesta�a.buscarPaginaWeb("No existe");
			Assert::IsNull(resultado);

		}

		TEST_METHOD(TestArchivosPesta�a2)
		{
			
			
			Pesta�a pesta�a("TestPesta�a");
			PaginaWeb* pag1 = new PaginaWeb("www.ejemplo1.com", "ejemplo1");
			PaginaWeb* pag2 = new PaginaWeb("www.ejemplo2.com", "ejemplo2");
			pesta�a.insertarPrimero(*pag1);
			pesta�a.insertarPrimero(*pag2);

			
			ofstream file("test_historial.bin", ios::binary);
			pesta�a.guardarHistorialBinario(file);
			file.close();

			
			Pesta�a pesta�aLeida("TestPesta�aLeida");
			ifstream FileLectura("test_historial.bin", ios::binary);
			pesta�aLeida.leerHistorialBinario(FileLectura);
			FileLectura.close();

			
			PaginaWeb* resultado1 = pesta�aLeida.buscarPaginaWeb("www.ejemplo1.com");
			PaginaWeb* resultado2 = pesta�aLeida.buscarPaginaWeb("www.ejemplo2.com");

			Assert::IsNotNull(resultado1, L"La p�gina 1 no se encontr� despu�s de leer el historial.");
			Assert::IsNotNull(resultado2, L"La p�gina 2 no se encontr� despu�s de leer el historial.");

			
			remove("test_historial.bin");
			delete pag1;
			delete pag2;
		}





	};

	TEST_CLASS(UnitTestAdmin)
	{
	public:
		TEST_METHOD(TestInsertarPrimeroAdmin)
		{
		
			AdminPesta�as admin;
			Pesta�a* nuevaPesta�a = new Pesta�a("Pesta�a1");
			admin.InsertarPrimero(nuevaPesta�a);

			
			Assert::AreEqual(1, admin.contadorPesta�as());
			Assert::IsNotNull(admin.getTail());
			Assert::AreEqual("Pesta�a1", admin.getTail()->pesta�a->getNombre().c_str());

		
			Pesta�a* segundaPesta�a = new Pesta�a("Pesta�a2");
			admin.InsertarPrimero(segundaPesta�a);

			
			Assert::AreEqual(2, admin.contadorPesta�as());
			Assert::AreEqual("Pesta�a2", admin.getTail()->pesta�a->getNombre().c_str());
			Assert::AreEqual("Pesta�a1", admin.getTail()->siguiente->pesta�a->getNombre().c_str());
		}


		TEST_METHOD(TestBuscaPaginaWeb)
		{
		
			string testArchivo = "Prueba.csv";
			ofstream archivoPrueba(testArchivo);
			archivoPrueba << "www.ejemplo.com,ejemplo\n"; 
			archivoPrueba.close();

			
			AdminPesta�as admin;
			PaginaWeb* paginaBuscada = admin.buscaPaginaWeb("www.ejemplo.com");

			Assert::IsNotNull(paginaBuscada);
			Assert::AreEqual("www.ejemplo.com", paginaBuscada->getURL().c_str());
			Assert::AreEqual("ejemplo", paginaBuscada->getTitulo().c_str());

			PaginaWeb* paginaNoExistente = admin.buscaPaginaWeb("No Existe");
			Assert::IsNull(paginaNoExistente);

		
			remove(testArchivo.c_str());
		}



	};


}
