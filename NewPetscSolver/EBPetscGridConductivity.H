#ifdef CH_LANG_CC
/*
 *      _______              __
 *     / ___/ /  ___  __ _  / /  ___
 *    / /__/ _ \/ _ \/  V \/ _ \/ _ \
 *    \___/_//_/\___/_/_/_/_.__/\___/
 *    Please refer to Copyright.txt, in Chombo's root directory.
 */
#endif

#ifndef _EBPETSGRIDCONDUCTIVITY_H_
#define _EBPETSGRIDCONDUCTIVITY_H_
#ifdef CH_USE_PETSC
#include "LinearSolver.H"
#include "EBPetscMap.H"
#include "EBConductivityOp.H"
#include "NamespaceHeader.H"

class EBPetscGridConductivity : public EBPetscMap
{
public:
    virtual void setOp(LinearOp<LevelData<EBCellFAB> > *a_op);

    virtual void defineParameters(const int a_startLevel, 
				  const int a_finestLevel,
				  const int a_numGhostCells) { };
    
    virtual PetscErrorCode formPetscMat(Mat& a_petsc_mat,
				const LevelData<EBCellFAB>& a_phi);
    
    virtual PetscErrorCode addBCToRHS(Vec a_petsc_vec,
				      const LevelData<EBCellFAB>& a_phi,
				      const bool a_homogeneous);
    
    virtual PetscErrorCode getMatAIJSizes(PetscInt* a_d_nnz,
					  PetscInt* a_n_nnz,
					  const PetscInt a_nComp);
    EBConductivityOp* m_op;
};
#include "NamespaceFooter.H"

#endif
#endif
