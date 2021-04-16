//============================================================================
// Name        : businessCard.h
// Version     :
// Copyright   :
// Description : Rubrica in C++
//============================================================================

#ifndef CONTATTO_BUSINESSCARD_H_
#define CONTATTO_BUSINESSCARD_H_

#include "contatto.h"	// Inclusione header classe Contatto generico

/**
 * Classe BusinessCard, sottoclasse derivata da Contatto.
 * Eredita con modalita virtual public.
 */
class BusinessCard : virtual public Contatto::Contatto {
private:

protected:
	// Campi protected ereditabili dalle sottoclassi derivate da BusinessCard.
	std::string address;
	std::string partitaIva;

public:
	// Firma costruttore BusinessCard
	BusinessCard(std::string numero, std::string nome, std::string indirizzo, std::string partIva);

	// Firma destruttore BusinessCard
	~BusinessCard();

	// Funzione membro di ritorno stringa dei contenuti di un contatto
	std::string toStringContatto();
};

#endif /* CONTATTO_BUSINESSCARD_H_ */
