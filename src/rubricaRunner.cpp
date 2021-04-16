//============================================================================
// Name        : rubricaRunner.cpp
// Version     :
// Copyright   :
// Description : Rubrica in C++
//============================================================================

#include "rubrica/rubrica.h"	// Inclusione header classe Rubrica
#include "utilita/utilita.h"	// Inclusione header per alcune funzioni utili

/**
 * Main function
 */
int main(void) {
	// Al lancio del programma chiama la funzione di popolamento
	// della rubrica con contatti da file in locale
	Rubrica::popolaRubrica();

	// Cicla finche non riceve un istruzione di break
	while (1) {
		// Mostra il menu principale
		Utilita::mostraMenu();

		// Chiama la funzione che invoca altre funzioni
		// a seconda dell'input dell'utente.
		Utilita::selezionaMenu();
	}

	return (0);
}
