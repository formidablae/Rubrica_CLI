//============================================================================
// Name        : utilita.h
// Version     :
// Copyright   :
// Description : Rubrica in C++
//============================================================================

#ifndef UTILITA_UTILITA_H_
#define UTILITA_UTILITA_H_

#include <iostream>

#include "../rubrica/rubrica.h"		// Inclusione header classe Rubrica
#include "../contatto/contatto.h"	// Inclusione header classe Contatto generico

/**
 * Classe Utilita
 */
class Utilita {
protected:

public:
	// Variabili statiche costanti per imporre limiti sulle lunghezze
	// dei valori dei campi di ciascun contatto
	static const int maxNumLength = 10;
	static const int maxNameLength = 9;
	static const int maxRelationLength = 7;
	static const int maxCompanyLength = 12;
	static const int maxAddressLength = 24;
	static const int maxPivaLength = 10;

	// Firma funzione termina che prende in input un messaggio stringa
	// e un codice di terminazione, stampa il messaggio e termina il programma
	static void termina(const std::string messaggio, const int terminationCode);

	// Firma funzione di visualizzazione menu principale
	static void mostraMenu();

	// Firma funzione di selezione di una voce dal menu
	static void selezionaMenu();

	// Firma fuzione del menu di eliminazione di un contatto
	static void menuEliminaContatto();

	// Firma fuzione del menu di modifica di un contatto
//	static void menuModificaContatto();

	// Firma funzione membro di stampa di righe vuote in console
	static void stampoVuotoConsole();

	// Firma funzione membro per avere input un input dall'utente
	static std::string getInput(std::string message);

	// Firma funzione membro per ritorna se un input rappresenta un numero o meno
	static bool isNumber(const std::string input);
};

#endif /* UTILITA_UTILITA_H_ */
