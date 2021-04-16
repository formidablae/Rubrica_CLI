//============================================================================
// Name        : rubrica.cpp
// Version     :
// Copyright   :
// Description : Rubrica in C++
//============================================================================

#include <string>
#include <vector>
#include <iostream>
#include <fstream>	// Input file stream per lettura di file in locale
#include <sstream>	// String stream di bufferizzazione e tokenizzazione delle letture
#include <memory>	// Necessario per vector di puntatori shared_ptr a Contatto
#include "rubrica.h"						// Inclusione header classe Rubrica
#include "../contatto/contatto.h"			// Inclusione header classe Contatto generico
#include "../contatto/contattoFamiglia.h"	// Inclusione header classe ContattoFamiglia
#include "../contatto/contattoLavoro.h"		// Inclusione header classe ContattoLavoro
#include "../contatto/businessCard.h"		// Inclusione header classe BusinessCard
#include "../contatto/contattoBusiness.h"	// Inclusione header classe ContattoBusiness
#include "../utilita/utilita.h"				// Inclusione header per alcune funzioni utili

// Puntatore statico globale a istanza singleton di Rubrica
static Rubrica* instance;

// Flag statico globale indicante se il singleton di Rubrica e gia stato inizializzato
static bool instantialized = false;

// Iteratore per vector di puntatori shared_ptr a Contatto.
std::vector<typename std::vector<std::shared_ptr<Contatto>>::iterator> edge_iters;

/**
 * Costruttore di Rubrica.
 */	
Rubrica::Rubrica() {
}

/**
 * Destruttore di Rubrica.
 */
Rubrica::~Rubrica() {
}

/**
 * Getter di istanza singleton di di Rubrica.
 */
Rubrica* Rubrica::getRubricaInstance() {
	if (!instantialized) {
		instance = (Rubrica*) malloc(sizeof(Rubrica));
		// Inizializzazione dell'elencoContatti a vector di puntatori shared_ptr a Contatto
		instance->elencoContatti = std::vector<std::shared_ptr<Contatto>>();
		instantialized = true;
		std::cout <<
				"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
				"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
				"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n"
				"| >  La rubrica e stata creata                                                                                                                          |" << std::endl;
	}
	return instance;
}

/**
 * Funzione membro per popolare la Rubrica di contatti salvati
 * in un file locale
 */
void Rubrica::popolaRubrica() {
	Rubrica* rubrica = Rubrica::getRubricaInstance();
	std::string riga, virgola,
				tagTel, numero,
				tagNome, nome,
				tagTipo, tipo,
				tagRelazione, relazione,
				tagAzienda, azienda,
				tagIndirizzo, indirizzo,
				tagPartitaIva, partitaIva;

	// Apertura stream lettura da file locale
	std::ifstream streamDaFileInLocale("rubrica.txt");

	rubrica->elencoContatti.clear();

	// Ottenimento di nuova riga da stream di lettura da file locale
	while (getline(streamDaFileInLocale, riga)) {

		// Streaming token di ciascuna riga
		std::stringstream streamLinea(riga);
		streamLinea >> tagTel >> numero >> virgola >> tagNome >> nome >> virgola >> tagTipo >> tipo;
		switch (tipo.compare("Famiglia") == 0 ? 1 : (tipo.compare("Lavoro") == 0 ? 2 : (tipo.compare("BCard") == 0 ? 3 : (tipo.compare("Business") == 0 ? 4 : 0)))) {
			case 0:
				rubrica->elencoContatti.emplace_back(new Contatto(numero, nome));
				break;
			case 1:
				streamLinea >> virgola >> tagRelazione >> relazione;
				rubrica->elencoContatti.emplace_back(new ContattoFamiglia(numero, nome, relazione));
				break;
			case 2:
				streamLinea >> virgola >> tagAzienda >> azienda;
				rubrica->elencoContatti.emplace_back(new ContattoLavoro(numero, nome, azienda));
				break;
			case 3:
				streamLinea >> virgola >> tagIndirizzo >> indirizzo >> virgola >> tagPartitaIva >> partitaIva;
				rubrica->elencoContatti.emplace_back(new BusinessCard(numero, nome, indirizzo, partitaIva));
				break;
			case 4:
				streamLinea >> virgola >> tagAzienda >> azienda >> virgola >> tagIndirizzo >> indirizzo >> virgola >> tagPartitaIva >> partitaIva;
				rubrica->elencoContatti.emplace_back(new ContattoBusiness(numero, nome, azienda, indirizzo, partitaIva));
				break;
		}
	}

	// Chiusura stream lettura da file locale
	streamDaFileInLocale.close();
	std::cout << "| >  Fine popolamento da file locale                                                                                                                    |" << std::endl;
}

/**
 * Funzione membro per aggiungere in rubrica contatti
 * attraverso l'input iterativo di dati.
 */
void Rubrica::aggiungiContattoDaInput() {
	std::string tipoInput;
	Rubrica* rubrica = Rubrica::getRubricaInstance();
	while (true) {
		std::cout << "| >  Inserire il tipo di contatto: 1. Generico , 2. Famiglia ,"
					 " 3. Lavoro , 4. BusinessCard , 5. Business , 0. Per annullare "
					 "l'operazione                |\n| >  ";
		std::cin >> tipoInput;
		int tipoScelto = (Utilita::isNumber(tipoInput) && (stoi(tipoInput) > -1 && stoi(tipoInput) < 6)) ? stoi(tipoInput) : -1;

		if (tipoScelto == 0) {
			std::cout << "| >  L'operzione di inserimento nuovo contatto e stata anullata                                                                                         |" << std::endl;
			break;
		}

		if (tipoScelto == -1) {
			std::cout << "| >  Valore inserito non valido                                                                                                                         |" << std::endl;
			continue;
		}

		std::string num;
		std::string nome;
		std::string relazione;
		std::string azienda;
		std::string indirizzo;
		std::string partitaIva;

		while(true) {
			std::cout << "| >  Inserire il numero di telefono                                                                                                                     |\n| >  ";
			std::cin >> num;
			if ((int) num.length() > Utilita::maxNumLength) {
				std::cout << "| >  Numero troppo lungo. Max " << Utilita::maxNumLength << " cifre.                                                                                                                 |" << std::endl;
				continue;
			}
			break;
		}

		while(true) {
			std::cout << "| >  Inserire il nome con cui salvarlo.                                                                                                                 |\n| >  ";
			std::cin >> nome;
			if ((int) nome.length() > Utilita::maxNameLength) {
				std::cout << "| >  Nome troppo lungo. Max " << Utilita::maxNameLength << " caratteri.                                                                                                                |" << std::endl;
				continue;
			}
			break;
		}


		if (tipoScelto == 2) {
			while(true) {
				std::cout << "| >  Inserire la relazione con tale contatto                                                                                                                                       |\n| >  ";
				std::cin >> relazione;
				if ((int) relazione.length() > Utilita::maxRelationLength) {
					std::cout << "| >  Testo inserito per relazione troppo lungo. Max " << Utilita::maxRelationLength << " caratteri.                                                             |" << std::endl;
					continue;
				}
				break;
			}
		}

		if ((tipoScelto == 3) || (tipoScelto == 5)){
			while(true) {
				std::cout << "| >  Inserire l'azienda di tale contatto                                                                                                                |\n| >  ";
				std::cin >> azienda;
				if ((int) azienda.length() > Utilita::maxCompanyLength) {
					std::cout << "| >  Testo inserito per l'azienda troppo lungo. Max " << Utilita::maxCompanyLength << " caratteri.                                                                                       |" << std::endl;
					continue;
				}
				break;
			}
		}


		if ((tipoScelto == 4) || (tipoScelto == 5)) {
			while(true) {
				std::cout << "| >  Inserire l'indirizzo di tale contatto                                                                                                              |\n| >  ";
				std::cin >> indirizzo;
				if ((int) indirizzo.length() > Utilita::maxAddressLength) {
					std::cout << "| >  Indirizzo troppo lungo. Max " << Utilita::maxAddressLength << " caratteri.                                                                                               |" << std::endl;
					continue;
				}
				break;
			}

			while(true) {
				std::cout << "| >  Inserire la Partita IVA di tale contatto                                                                                                           |\n| >  ";
				std::cin >> partitaIva;
				if ((int) partitaIva.length() > Utilita::maxPivaLength) {
					std::cout << "| >  Partita IVA inserita troppo lunga. Max " << Utilita::maxPivaLength << " caratteri.                                                             |" << std::endl;
					continue;
				}
				break;
			}
		}

		if (tipoScelto == 1) {
			rubrica->elencoContatti.emplace_back(new Contatto(num, nome));
			std::cout << "| >  Contatto generico creato con successo                                                                                                              |" << std::endl;
			Rubrica::salvaSuFile();
			break;
		}
		else if (tipoScelto == 2) {
			rubrica->elencoContatti.emplace_back(new ContattoFamiglia(num, nome, relazione));
			std::cout << "| >  Contatto famiglia creato con successo                                                                                                              |" << std::endl;
			Rubrica::salvaSuFile();
			break;
		}
		else if (tipoScelto == 3) {
			rubrica->elencoContatti.emplace_back(new ContattoLavoro(num, nome, azienda));
			std::cout << "| >  Contatto lavoro creato con successo                                                                                                                |" << std::endl;
			Rubrica::salvaSuFile();
			break;
		}
		else if (tipoScelto == 4) {
			rubrica->elencoContatti.emplace_back(new BusinessCard(num, nome, indirizzo, partitaIva));
			std::cout << "| >  Business card creato con successo                                                                                                                  |" << std::endl;
			Rubrica::salvaSuFile();
			break;
		}
		else if (tipoScelto == 5) {
			rubrica->elencoContatti.emplace_back(new ContattoBusiness(num, nome, azienda, indirizzo, partitaIva));
			std::cout << "| >  Contatto business creato con successo                                                                                                              |" << std::endl;
			Rubrica::salvaSuFile();
			break;
		}
	}
}

/**
 * Funzione membro per ritornare il contatto in rubrica in posizione index.
 */
//Contatto Rubrica::getIndexthContact(int index) {
//	return *(Rubrica::getRubricaInstance()->elencoContatti[index]);
//}

/**
 * Funzione membro per cercare un contatto per nome e
 * ritornare la sua posizione in rubrica.
 */
int Rubrica::cercaIndiceContattoPerNome(std::string nomeDaCercare) {
	Rubrica* rubrica = Rubrica::getRubricaInstance();
	for (int i = 0; i < (int) rubrica->elencoContatti.size(); i++) {
		if (rubrica->elencoContatti[i]->getNome().compare(nomeDaCercare) == 0) {return i;}
	}
	std::cout << "| >  Contatto non presente in rubrica                                                                                                                   |" << std::endl;
	return -1;
}

/**
 * Funzione membro per cercare un contatto per numero e
 * ritornare la sua posizione in rubrica.
 */
int Rubrica::cercaIndiceContattoPerNumero(std::string numeroDaCercare) {
	Rubrica* rubrica = Rubrica::getRubricaInstance();
	for (int i = 0; i < (int) rubrica->elencoContatti.size(); i++) {
		if (rubrica->elencoContatti[i]->getNumero().compare(numeroDaCercare) == 0) {return i;}
	}
	std::cout << "| >  Contatto non presente in rubrica                                                                                                                   |" << std::endl;
	return -1;
}

/**
 * Funzione membro per eliminare dalla rubrica il contatto
 * nella posizione passata come argomento.
 */
void Rubrica::eliminaContatto(int indiceRicercaContatto) {
	Rubrica* rubrica = Rubrica::getRubricaInstance();
	//delete &rubrica->elencoContatti[indiceRicercaContatto];
	rubrica->elencoContatti.erase(rubrica->elencoContatti.begin() + indiceRicercaContatto);
}

/**
 * Funzione membro per modificare il contatto
 * nella posizione passata come argomento.
 */
//void Rubrica::modificaContatto(int indiceContatto) {
//	Rubrica* rubrica = Rubrica::getRubricaInstance();
//	Contatto newContatto = Rubrica::getIndexthContact(indiceContatto).modContatto();
//	Rubrica::eliminaContatto(indiceContatto);
//	rubrica->elencoContatti.emplace_back(&newContatto);
//}

/**
 * Funzione membro per salvare tutti i dati della rubrica
 * (dati dei contatti) in un file locale.
 */
void Rubrica::salvaSuFile() {
	// Output file stream per scrittura in un file.
	std::ofstream streamVersoFileInLocale("rubrica.txt");
	Rubrica* rubrica = Rubrica::getRubricaInstance();

	int dim = (rubrica->elencoContatti).size();

	for (int i = 0; i < dim; i++) {
		// Scrittura nel file
		streamVersoFileInLocale << (rubrica->elencoContatti[i])->toStringContatto() << std::endl;
	}
	// Chiusura dell'output file stream.
	streamVersoFileInLocale.close();
}

/**
 * Funzione membro di Rubrica per ritornare
 * come stringa i contenuti della lista dei contatti.
 */
std::string Rubrica::toStringRubrica() {
	Rubrica* rubrica = Rubrica::getRubricaInstance();
	std::string result =
			"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
			"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
			"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n"
			"|    Tutti i contatti in rubrica                                                                                                                        |\n"
			"|                                                                                                                                                       |";
	int dim = rubrica->elencoContatti.size();
	int maxSize = std::to_string(dim + 1).size();
	for (int i = 0; i < dim; i++) {
		int sizeIndent = maxSize - ((int) std::to_string(i + 1).size());
		result = result + "\n| ";
		for (int j = 0; j < sizeIndent; j++) {result = result + " ";}
		std::string descrizioneContattoi = (rubrica->elencoContatti[i])->toStringContatto();
		int dimDescContattoi = (int) descrizioneContattoi.size();
		result = result + std::to_string(i + 1) + ". " + descrizioneContattoi;
		for (int k = 0; k < 145 - dimDescContattoi; k++) {result = result + " ";}
		result = result + " |";
	}
	return result + "\n|                                                                                                                                                       |";;
}

/**
 * Funzione membro di Rubrica per stampare
 * tutti i contatti in lista dei contatti.
 */
void Rubrica::mostra() {std::cout << Rubrica::toStringRubrica() << std::endl;}

/**
 * Funzione membro per la deallocazione ed
 * eliminazione dei contatti e della rubrica
 */
void Rubrica::eliminaRubrica() {
	Rubrica* rubrica = Rubrica::getRubricaInstance();
	for (int i = 0; i < (int) rubrica->elencoContatti.size(); i++) {Rubrica::eliminaContatto(i);}
	free(rubrica);
}
