//============================================================================
// Name        : contattoFamiglia.h
// Version     :
// Copyright   :
// Description : Rubrica in C++
//============================================================================

#ifndef CONTATTO_CONTATTOFAMIGLIA_H_
#define CONTATTO_CONTATTOFAMIGLIA_H_

#include <string>

#include "contatto.h"

/**
 * Classe ContattoFamiglia, sottoclasse derivata di Contatto.
 */
class ContattoFamiglia : public Contatto::Contatto {
private:
	// Campo privato di ContattoFamiglia
	std::string relationship;

protected:

public:
	// Firma costruttore ContattoFamiglia
	ContattoFamiglia(std::string numero, std::string nome, std::string relazione);

	// Firma distruttore ContattoFamiglia
	~ContattoFamiglia();

	// Funzione membro di ritorno stringa dei contenuti di un contatto
	std::string toStringContatto();
};

#endif /* CONTATTO_CONTATTOFAMIGLIA_H_ */
