//============================================================================
// Name        : rubrica.h
// Version     :
// Copyright   :
// Description : Rubrica in C++
//============================================================================

#ifndef RUBRICA_RUBRICA_H_
#define RUBRICA_RUBRICA_H_

#include <string>
#include <memory>	// Necessario per vector di puntatori shared_ptr a Contatto
#include <vector>

#include "../contatto/contatto.h"	// Inclusione header classe Contatto

/**
 * Classe Rubrica
 */
class Rubrica {
private:
	// Firma di elencoContatti come tipo vector di puntatori shared_ptr a Contatto
	std::vector<std::shared_ptr<Contatto>> elencoContatti;
public:
	// Firma costruttore Rubrica
	Rubrica();

	// Firma distruttore Rubrica
	~Rubrica();

	// Firma del getter di istanza singleton di Rubrica
	static Rubrica* getRubricaInstance();

	// Firma funzione membro per popolare la rubrica da file locale
	static void popolaRubrica();

	// Firma funzione membro per aggiungere in rubrica contatti
	// attraverso l'input iterativo di dati.
	static void aggiungiContattoDaInput();

	// Firma funzione membro per ritornare il contatto in rubrica in posizione index
//	static Contatto getIndexthContact(int index);

	// Firma funzione membro per cercare un contatto per nome e
	// ritornare la sua posizione in rubrica.
	static int cercaIndiceContattoPerNome(std::string nomeDaCercare);

	// Firma funzione membro per cercare un contatto per numero e
	// ritornare la sua posizione in rubrica.
	static int cercaIndiceContattoPerNumero(std::string numeroDaCercare);

	// Firma funzione membro per eliminare dalla rubrica il contatto
	// nella posizione passata come argomento
	static void eliminaContatto(int indiceRicercaContatto);

	// Firma funzione membro per modificare il contatto
	// nella posizione passata come argomento
//	static void modificaContatto(int indiceContatto);

	// Firma funzione membro per salvare tutti i dati della rubrica
	// (dati dei contatti) in un file locale.
	static void salvaSuFile();

	// Firma funzione membro di ritorno stringa dei contenuti di una rubrica
	static std::string toStringRubrica();

	// Firma funzione membro stampa dei contenuti di una rubrica
	static void mostra();

	// Firma funzione membro di deallocazione ed eliminazione dei contatti e della rubrica
	static void eliminaRubrica();
};

#endif /* RUBRICA_RUBRICA_H_ */
