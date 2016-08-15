/*
 * TssDe.h
 *
 *  Created on: Sep 24, 2014
 *      Author: kibaekkim
 */

#ifndef TSSDE_H_
#define TSSDE_H_

/** DSP */
#include "Solver/TssSolver.h"
#include "Solver/SolverInterface.h"

class TssDe : public TssSolver {
public:

	/** default constructor */
	TssDe();

	/** default destructor */
	virtual ~TssDe();

	/** solve */
	virtual STO_RTN_CODE solve();

	/** write extensive form */
	void writeMps(const char * filename);

private:

	SolverInterface * si_; /**< my solver interface */
};

#endif /* TSSDE_H_ */