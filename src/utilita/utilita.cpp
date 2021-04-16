//============================================================================
// Name        : utilita.cpp
// Version     :
// Copyright   :
// Description : Rubrica in C++
//============================================================================

#include "utilita.h"				// Inclusione header per alcune funzioni utili
#include "../rubrica/rubrica.h"		// Inclusione header classe Rubrica
#include "../contatto/contatto.h"	// Inclusione header classe Contatto generico

/**
 * Firma funzione termina che prende in input un messaggio stringa
 * e un codice di terminazione, stampa il messaggio e termina il programma
 */
void Utilita::termina(const std::string messaggio, const int terminationCode) {
	std::cout << messaggio << std::endl;
	exit(terminationCode);
}

/**
 * Funzione di visualizzazione menu principale
 */
void Utilita::mostraMenu() {
	std::cout << "|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|" << std::endl;
	std::cout << "|    MENU Principale                                                                                                                                    |" << std::endl;
	std::cout << "|                                                                                                                                                       |" << std::endl;
	std::cout << "| 1. Crea un nuovo contatto in rubrica                                                                                                                  |" << std::endl;
	std::cout << "| 2. Elimina un contatto già esistente                                                                                                                  |" << std::endl;
	std::cout << "| 3. Visualizza i contatti memorizzati                                                                                                                  |" << std::endl;
	std::cout << "| 4. Modifica contenuti di un contatto                                                                                                                  |" << std::endl;
	std::cout << "| 5. Popola la rubrica da file locale                                                                                                                   |" << std::endl;
	std::cout << "| 6. Esci                                                                                                                                               |" << std::endl;
	std::cout << "|                                                                                                                                                       |" << std::endl;
	std::cout << "|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|" << std::endl;
}

/**
 * Funzione di selezione di una voce dal menu
 */
void Utilita::selezionaMenu() {
	std::string userInput = Utilita::getInput(
			"| >  Inserisci la tua scelta                                                                                                                            |\n| >  ");
	int menuSelection = (Utilita::isNumber(userInput) && (stoi(userInput) > 0 && stoi(userInput) < 7)) ? stoi(userInput) : -1;

	switch (menuSelection) {
		case -1:
			std::cout << "| >  Valore inserito non valido                                                                                                                         |" << std::endl;
			break;
		case 1:
			Rubrica::aggiungiContattoDaInput();
			break;
		case 2:
			Utilita::menuEliminaContatto();
			break;
		case 3:
			Rubrica::mostra();
			break;
		case 4:
			std::cout << "| >  Funzionalita da sviluppare ulteriormente                                                                                                           |" << std::endl;
//			Utilita::menuModificaContatto();
			break;
		case 5:
			Rubrica::popolaRubrica();
			break;
		case 6:
			Rubrica::salvaSuFile();
			std::cout << "|                                                                                                                                                       |" << std::endl;
			std::cout << "| >  Salvando su file prima di uscire                                                                                                                   |" << std::endl;
			Rubrica::eliminaRubrica();
			std::cout << "| >  Deallocando rubrica dalla memoria                                                                                                                  |" << std::endl;
			termina("| >  Chiusura!                                                                                                                                          |\n"
					"'-------------------------------------------------------------------------------------------------------------------------------------------------------'", 0);
			break;
	}
}

/**
 * Fuzione del menu di eliminazione di un contatto
 */
void Utilita::menuEliminaContatto() {
	std::string userInput = "";
	int menuSelection = 0;
	int indiceRicercaContatto = -1;
	do {
		userInput = Utilita::getInput(
				"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n"
				"|    MENU Elimina contatto                                                                                                                              |\n"
				"|                                                                                                                                                       |\n"
				"| 1. Elimina un contatto per numero                                                                                                                     |\n"
				"| 2. Elimina un contatto per nome                                                                                                                       |\n"
				"| 3. Ritorna nel MENU Principale                                                                                                                        |\n"
				"|                                                                                                                                                       |\n"
				"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n"
				"| >  Inserisci la tua scelta                                                                                                                            |\n| >  ");
		menuSelection = (Utilita::isNumber(userInput) && (stoi(userInput) > 0 && stoi(userInput) < 4)) ? stoi(userInput) : -1;

		switch (menuSelection) {
			case -1:
				std::cout <<
				"| >  Valore inserito non valido                                                                                                                         |" << std::endl;
				break;
			case 1:
				userInput = Utilita::getInput(
						"| >  Inserire il numero da eliminare                                                                                                                    |\n| >  ");
				indiceRicercaContatto = Rubrica::cercaIndiceContattoPerNumero(userInput);
				if (indiceRicercaContatto != -1) {
					Rubrica::eliminaContatto(indiceRicercaContatto);
					std::cout << "| >  Contatto eliminato dalla rubrica                                                                                                                   |" << std::endl;
					Rubrica::salvaSuFile();
				}
				else {
					std::cout << "| >  Nessun contatto è stato eliminato                                                                                                                  |" << std::endl;
				}
				break;
			case 2:
				userInput = Utilita::getInput(
						"| >  Inserire il nome da eliminare                                                                                                                      |\n| >  ");
				indiceRicercaContatto = Rubrica::cercaIndiceContattoPerNome(userInput);
				if (indiceRicercaContatto != -1) {
					Rubrica::eliminaContatto(indiceRicercaContatto);
					std::cout << "| >  Contatto eliminato dalla rubrica                                                                                                                   |" << std::endl;
					Rubrica::salvaSuFile();
				}
				else {
					std::cout << "| >  Nessun contatto è stato eliminato                                                                                                                  |" << std::endl;
				}
				break;
			case 3:
				std::cout << "| >  Ritorno nel MENU principale                                                                                                                        |" << std::endl;
				break;
		}
	} while (menuSelection != 3);
}

/**
 * Fuzione del menu di modifica di un contatto
 */
//void Utilita::menuModificaContatto() {
//	std::string userInput = "";
//	int menuSelection = 0;
//	int indiceRicercaContatto = -1;
//	do {
//		userInput = Utilita::getInput(
//				"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n"
//				"|    MENU Modifica contatto                                                                                                                             |\n"
//				"|                                                                                                                                                       |\n"
//				"| 1. Modifica un contatto per numero                                                                                                                    |\n"
//				"| 2. Modifica un contatto per nome                                                                                                                      |\n"
//				"| 3. Torna nel MENU Principale                                                                                                                          |\n"
//				"|                                                                                                                                                       |\n"
//				"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n"
//				"| >  Inserisci la tua scelta                                                                                                                            |\n| >  ");
//		menuSelection = (Utilita::isNumber(userInput) && (stoi(userInput) > 0 && stoi(userInput) < 4)) ? stoi(userInput) : -1;
//
//		switch (menuSelection) {
//			case -1:
//				std::cout <<
//				"| >  Valore inserito non valido                                                                                                                         |" << std::endl;
//				break;
//			case 1:
//				userInput = Utilita::getInput("| >  Inserire il numero da modificare   |\n| >  ");
//				indiceRicercaContatto = Rubrica::cercaIndiceContattoPerNumero(userInput);
//				if (indiceRicercaContatto != -1) {
//					Rubrica::modificaContatto(indiceRicercaContatto);
//					std::cout << "| >  Contatto modificato con successo   |" << std::endl;
//					Rubrica::salvaSuFile();
//				}
//				else {
//					std::cout << "| >  Contatto non trovato               |" << std::endl;
//				}
//				break;
//			case 2:
//				userInput = Utilita::getInput(
//						"| >  Inserire il nome da modificare     |\n| >  ");
//				indiceRicercaContatto = Rubrica::cercaIndiceContattoPerNome(userInput);
//				if (indiceRicercaContatto != -1) {
//					Rubrica::modificaContatto(indiceRicercaContatto);
//					std::cout << "| >  Contatto modificato con successo   |" << std::endl;
//					Rubrica::salvaSuFile();
//				}
//				else {
//					std::cout << "| >  Contatto non trovato               |" << std::endl;
//				}
//				break;
//			case 3:
//				std::cout << "| >  Ritorno nel MENU principale        |" << std::endl;
//				break;
//		}
//	} while (menuSelection != 3);
//}

/**
 * Funzione membro di stampa di righe vuote in console
 */
void Utilita::stampoVuotoConsole() {for (int i = 0; i < 2; i++) {std::cout << std::endl;}}

/**
 * Funzione membro per avere input un input dall'utente
 */
std::string Utilita::getInput(std::string message) {
	std::string userInput = "";
	std::cout << message;
	std::cin >> userInput;
	return userInput;
}

/**
 * Funzione membro per ritorna se un input rappresenta un numero o meno
 */
bool Utilita::isNumber(const std::string input) {
	std::string::const_iterator it = input.begin();
    while (it != input.end() && isdigit(*it)) ++it;
    return !input.empty() && it == input.end();
}
