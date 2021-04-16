//============================================================================
// Name        : contatto.h
// Version     :
// Copyright   :
// Description : Rubrica in C++
//============================================================================

#ifndef CONTATTO_CONTATTO_H_
#define CONTATTO_CONTATTO_H_

#include <string>

/**
 * Classe Contatto. Superclasse di tutte le
 * altre classi contatto.
 */
class Contatto {
protected:
	// Campi protected ereditabili dalle sottoclassi derivate da Contatto.
	std::string num;
	std::string name;
	std::string type;

public:
	// Firma costruttore Contatto
	Contatto(std::string numero, std::string nome);

	// Firma destruttore Contatto, virtual
	virtual ~Contatto();

	// Funzione membro di ritorno stringa dei contenuti di un contatto
	std::string getNome();
	std::string getNumero();
//	std::string getTipo();
	bool controllaNomeContatto(std::string nomeDaControllare);
	bool controllaNumeroContatto(std::string numeroDaControllare);
//	Contatto modContatto();

	// Funzione membro di stampa contatto, virtual
	virtual std::string toStringContatto();
};

#endif /* CONTATTO_CONTATTO_H_ */
