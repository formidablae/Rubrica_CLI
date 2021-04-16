//============================================================================
// Name        : contattoLavoro.h
// Version     :
// Copyright   :
// Description : Rubrica in C++
//============================================================================

#ifndef CONTATTO_CONTATTOLAVORO_H_
#define CONTATTO_CONTATTOLAVORO_H_

#include "contatto.h"	// Inclusione header classe Contatto generico

/**
 * Classe ContattoLavoro, sottoclasse derivata da Contatto.
 * Eredita con modalita virtual public.
 */
class ContattoLavoro : virtual public Contatto::Contatto {
private:

protected:
	// Campo protected, ereditabile dalle classi derivate da ContattoLavoro
	std::string company;

public:
	// Firma costruttore ContattoLavoro
	ContattoLavoro(std::string numero, std::string nome, std::string azienda);

	// Firma destruttore ContattoLavoro
	~ContattoLavoro();

	// Funzione membro di ritorno stringa dei contenuti di un contatto
	std::string toStringContatto();
};

#endif /* CONTATTO_CONTATTOLAVORO_H_ */
