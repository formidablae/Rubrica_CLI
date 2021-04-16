//============================================================================
// Name        : contattoBusiness.h
// Version     :
// Copyright   :
// Description : Rubrica in C++
//============================================================================

#ifndef CONTATTO_CONTATTOBUSINESS_H_
#define CONTATTO_CONTATTOBUSINESS_H_

#include "businessCard.h"	// Inclusione header classe BusinessCard
#include "contattoLavoro.h"	// Inclusione header classe ContattoLavoro

/**
 * Classe ContattoBusiness, sottoclasse derivata di ContattoLavoro e BusinessCard.
 * Ereditarieta multipla di tipo "diamante".
 */
class ContattoBusiness : public ContattoLavoro::ContattoLavoro, public BusinessCard::BusinessCard {
private:

protected:

public:
	// Firma costruttore ContattoBusiness
	ContattoBusiness(std::string numero, std::string nome, std::string azienda, std::string indirizzo, std::string partIva);

	// Firma distruttore ContattoBusiness
	~ContattoBusiness();

	// Funzione membro di ritorno stringa dei contenuti di un contatto
	std::string toStringContatto();
};

#endif /* CONTATTO_CONTATTOBUSINESS_H_ */




