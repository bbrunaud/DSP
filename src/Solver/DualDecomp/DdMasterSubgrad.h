/*
 * DdMasterSubgrad.h
 *
 *  Created on: Feb 16, 2016
 *      Author: kibaekkim
 */

#ifndef SRC_SOLVER_DUALDECOMP_DDMASTERSUBGRAD_H_
#define SRC_SOLVER_DUALDECOMP_DDMASTERSUBGRAD_H_

#include "Solver/DualDecomp/DdMaster.h"

class DdMasterSubgrad: public DdMaster {
public:

	/** constructor */
	DdMasterSubgrad(
			DspParams *  par,    /**< parameter pointer */
			DecModel *   model,  /**< model pointer */
			DspMessage * message /**< message pointer */);

	/** destructor */
	virtual ~DdMasterSubgrad();

	/** initialize */
	virtual DSP_RTN_CODE init();

	/** solve */
	virtual DSP_RTN_CODE solve();

	/** update problem */
	virtual DSP_RTN_CODE updateProblem();

	/** get number of lambdas */
	virtual int getNumLambdas() {return model_->getNumCouplingRows();}

protected:

	/** create problem */
	virtual DSP_RTN_CODE createProblem();

private:

	int nstalls_;          /**< number of iterations UB were not improved */
	double stepscal_;      /**< another scalar between 0 and 2 */
	double stepsize_;      /**< stepsize */
	double * gradient_;    /**< subgradient */
	double * multipliers_; /**< Lagrangian multipliers */
};

#endif /* SRC_SOLVER_DUALDECOMP_DDMASTERSUBGRAD_H_ */
