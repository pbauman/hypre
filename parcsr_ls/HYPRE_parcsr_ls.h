/*BHEADER**********************************************************************
 * (c) 2000   The Regents of the University of California
 *
 * See the file COPYRIGHT_and_DISCLAIMER for a complete copyright
 * notice, contact person, and disclaimer.
 *
 * $Revision$
 *********************************************************************EHEADER*/
/******************************************************************************
 *
 * Header file for HYPRE_ls library
 *
 *****************************************************************************/

#ifndef HYPRE_PARCSR_LS_HEADER
#define HYPRE_PARCSR_LS_HEADER

#include "HYPRE_utilities.h"
#include "HYPRE_seq_mv.h"
#include "HYPRE_parcsr_mv.h"
#include "HYPRE_IJ_mv.h"

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/**
 * @name ParCSR Solvers
 *
 * These solvers use matrix/vector storage schemes that are taylored
 * for general sparse matrix systems.
 *
 * @memo Linear solvers for sparse matrix systems
 **/
/*@{*/

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/**
 * @name ParCSR Solvers
 **/
/*@{*/

struct hypre_Solver_struct;
/**
 * The solver object.
 **/

#ifndef HYPRE_SOLVER_STRUCT
#define HYPRE_SOLVER_STRUCT
struct hypre_Solver_struct;
typedef struct hypre_Solver_struct *HYPRE_Solver;
#endif

typedef int (*HYPRE_PtrToParSolverFcn)(HYPRE_Solver,
                                       HYPRE_ParCSRMatrix,
                                       HYPRE_ParVector,
                                       HYPRE_ParVector);

/*@}*/

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/**
 * @name ParCSR BoomerAMG Solver
 **/
/*@{*/

/**
 * Create a solver object.
 **/
int HYPRE_BoomerAMGCreate(HYPRE_Solver *solver);

/**
 * Destroy a solver object.
 **/
int HYPRE_BoomerAMGDestroy(HYPRE_Solver solver);

/**
 **/
int HYPRE_BoomerAMGSetup(HYPRE_Solver       solver,
                         HYPRE_ParCSRMatrix A,
                         HYPRE_ParVector    b,
                         HYPRE_ParVector    x);

/**
 * Solve the system.
 **/
int HYPRE_BoomerAMGSolve(HYPRE_Solver       solver,
                         HYPRE_ParCSRMatrix A,
                         HYPRE_ParVector    b,
                         HYPRE_ParVector    x);

/**
 * (Optional) Set the convergence tolerance.
 **/
int HYPRE_BoomerAMGSetTol(HYPRE_Solver solver,
                          double       tol);

/**
 * (Optional) Set maximum number of iterations.
 **/
int HYPRE_BoomerAMGSetMaxIter(HYPRE_Solver solver,
                              int          max_iter);

/**
 * (Optional) Set maximum number of multigrid levels.
 **/
int HYPRE_BoomerAMGSetMaxLevels(HYPRE_Solver solver,
                                int          max_levels);

/**
 * (Optional) Set AMG strength threshold.
 **/
int HYPRE_BoomerAMGSetStrongThreshold(HYPRE_Solver solver,
                                      double       strong_threshold);

/**
 * (Optional) 
 **/
int HYPRE_BoomerAMGSetMaxRowSum(HYPRE_Solver solver,
                                double        max_row_sum);

/**
 * (Optional) Defines which parallel coarsening algorithm is used.
 **/
int HYPRE_BoomerAMGSetCoarsenType(HYPRE_Solver solver,
                                  int          coarsen_type);

/**
 * (Optional) Defines whether local or global measures are used.
 **/
int HYPRE_BoomerAMGSetMeasureType(HYPRE_Solver solver,
                                  int          measure_type);

/**
 * (Optional) Defines whether to use a V-cycle (default) or a W-cycle.
 **/
int HYPRE_BoomerAMGSetCycleType(HYPRE_Solver solver,
                                int          cycle_type);

/**
 * (Optional) Defines the number of sweeps for fine and coarse grid, up and down cycle.
 **/
int HYPRE_BoomerAMGSetNumGridSweeps(HYPRE_Solver  solver,
                                    int          *num_grid_sweeps);

/**
 * (Optional) Defines which smoother is used on fine and coarse grid, up and down cycle.
 **/
int HYPRE_BoomerAMGSetGridRelaxType(HYPRE_Solver  solver,
                                    int          *grid_relax_type);

/**
 * (Optional) Defines in which order points are relaxed.
 **/
int HYPRE_BoomerAMGSetGridRelaxPoints(HYPRE_Solver   solver,
                                      int          **grid_relax_points);

/**
 * (Optional) Defines the relaxation weight for smoothed Jacobi and hybrid SOR.
 **/
int HYPRE_BoomerAMGSetRelaxWeight(HYPRE_Solver  solver,
                                  double       *relax_weight);

/**
 * (Optional) Defines the outer relaxation weight for hybrid SOR.
 **/
int HYPRE_BoomerAMGSetOmega(HYPRE_Solver  solver,
                            double       *omega);

/**
 * (Optional)
 **/
int HYPRE_BoomerAMGSetDebugFlag(HYPRE_Solver solver,
                                int          debug_flag);

/**
 * Returns the number of iterations taken.
 **/
int HYPRE_BoomerAMGGetNumIterations(HYPRE_Solver  solver,
                                    int          *num_iterations);

/**
 * Returns the norm of the final relative residual.
 **/
int HYPRE_BoomerAMGGetFinalRelativeResidualNorm(HYPRE_Solver  solver,
                                                double       *rel_resid_norm);

/*
 * Solves the transpose system.
 **/
int HYPRE_BoomerAMGSolveT(HYPRE_Solver       solver,
                          HYPRE_ParCSRMatrix A,
                          HYPRE_ParVector    b,
                          HYPRE_ParVector    x);

/*
 * (Optional)
 **/
int HYPRE_BoomerAMGSetRestriction(HYPRE_Solver solver,
                                  int          restr_par);

/*
 * (Optional) Defines a truncation factor for the interpolation.
 **/
int HYPRE_BoomerAMGSetTruncFactor(HYPRE_Solver solver,
                                  double       trunc_factor);

/*
 * (Optional)
 **/
int HYPRE_BoomerAMGSetInterpType(HYPRE_Solver solver,
                                 int          interp_type);

/*
 * (Optional)
 **/
int HYPRE_BoomerAMGSetMinIter(HYPRE_Solver solver,
                              int          min_iter);

/*
 * (Optional)
 **/
int HYPRE_BoomerAMGInitGridRelaxation(int    **num_grid_sweeps_ptr,
                                      int    **grid_relax_type_ptr,
                                      int   ***grid_relax_points_ptr,
                                      int      coarsen_type,
                                      double **relax_weights_ptr,
                                      int      max_levels);

/*
 * (Optional) Sets more complex smoothers.
 **/
int HYPRE_BoomerAMGSetSmoothOption(HYPRE_Solver  solver,
                                  int       *smooth_option);

/*
 * (Optional) Sets the number of sweeps for more complex smoothers.
 **/
int HYPRE_BoomerAMGSetSmoothNumSweep(HYPRE_Solver  solver,
                                  int       smooth_num_sweep);

/*
 * (Optional) Name of file to which BoomerAMG will print;
 * cf HYPRE_BoomerAMGSetPrintLevel.  (Presently this is ignored).
 **/
int HYPRE_BoomerAMGSetPrintFileName(HYPRE_Solver  solver,
                                  const char   *print_file_name);

/*
 * (Optional) Requests automatic printing of solver performance and
 * degugging data; default to 0 for no printing.
 **/
int HYPRE_BoomerAMGSetPrintLevel(HYPRE_Solver  solver,
                              int           print_level);

/*
 * (Optional) Requests additional computations for diagnostic and similar
 * data to be logged by the user. Default to 0 for do nothing.  The latest
 * residual will be available if log_level>2.
 **/
int HYPRE_BoomerAMGSetLogLevel(HYPRE_Solver  solver,
                              int           log_level);

/*
 * (Optional) Sets the size of the system of PDEs, if using the systems version.
 **/
int HYPRE_BoomerAMGSetNumFunctions(HYPRE_Solver solver,
                                int          num_functions);

/*
 * (Optional) Sets mapping that assigns the function to each variable if using the systems version.
 **/
int HYPRE_BoomerAMGSetDofFunc(HYPRE_Solver solver,
                              int         *dof_func);

/*
 * (Optional) Defines which variant of the Schwarz method is used.
 **/
int HYPRE_BoomerAMGSetVariant(HYPRE_Solver solver,
                                int          variant);

/*
 * (Optional) Defines the overlap for the Schwarz method.
 **/
int HYPRE_BoomerAMGSetOverlap(HYPRE_Solver solver,
                                int          overlap);

/*
 * (Optional) Defines the type of domain used for the Schwarz method.
 **/
int HYPRE_BoomerAMGSetDomainType(HYPRE_Solver solver,
                                int          domain_type);

/*
 * (Optional) Defines a smoothing parameter for the additive Schwarz method.
 **/
int HYPRE_BoomerAMGSetSchwarzRlxWeight(HYPRE_Solver solver,
                                double    schwarz_rlx_weight);

/*
 * (Optional) Defines symmetry for ParaSAILS.
 **/
int HYPRE_BoomerAMGSetSym(HYPRE_Solver solver,
                          int          sym);

/*
 * (Optional) Defines level for ParaSAILS.
 **/
int HYPRE_BoomerAMGSetLevel(HYPRE_Solver solver,
                            int          level);

/*
 * (Optional) Defines threshold for ParaSAILS.
 **/
int HYPRE_BoomerAMGSetThreshold(HYPRE_Solver solver,
                                double       threshold);

/*
 * (Optional) Defines filter for ParaSAILS.
 **/
int HYPRE_BoomerAMGSetFilter(HYPRE_Solver solver,
                             double  	  filter);

/*
 * (Optional) Defines drop tolerance for PILUT.
 **/
int HYPRE_BoomerAMGSetDropTol(HYPRE_Solver solver,
                              double 	   drop_tol);

/*
 * (Optional) Defines maximal number of nonzeros for PILUT.
 **/
int HYPRE_BoomerAMGSetMaxNzPerRow(HYPRE_Solver solver,
                          	  int          max_nz_per_row);

/*
 * (Optional) Defines name of an input file for Euclid parameters.
 **/
int HYPRE_BoomerAMGSetEuclidFile(HYPRE_Solver solver,
                         	 char        *euclidfile); 

/*
 * (Optional) Specifies the use of GSMG - geometrically smooth 
 * coarsening and interpolation.
 **/
int HYPRE_BoomerAMGSetGSMG(HYPRE_Solver solver,
                                int    gsmg);

/*
 * (Optional) Defines the number of sample vectors used in GSMG.
 **/
int HYPRE_BoomerAMGSetGSMGNumSamples(HYPRE_Solver solver,
                                int    gsmg);

/*@}*/

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/**
 * @name ParCSR ParaSails Preconditioner
 *
 * Parallel sparse approximate inverse preconditioner for the
 * ParCSR matrix format.
 **/
/*@{*/

/**
 * Create a ParaSails preconditioner.
 **/
int HYPRE_ParaSailsCreate(MPI_Comm      comm,
                          HYPRE_Solver *solver);

/**
 * Destroy a ParaSails preconditioner.
 **/
int HYPRE_ParaSailsDestroy(HYPRE_Solver solver);

/**
 * Set up the ParaSails preconditioner.  This function should be passed
 * to the iterative solver {\tt SetPrecond} function.
 *
 * @param solver [IN] Preconditioner object to set up.
 * @param A [IN] ParCSR matrix used to construct the preconditioner.
 * @param b Ignored by this function.
 * @param x Ignored by this function.
 **/
int HYPRE_ParaSailsSetup(HYPRE_Solver       solver,
                         HYPRE_ParCSRMatrix A,
                         HYPRE_ParVector    b,
                         HYPRE_ParVector    x);

/**
 * Apply the ParaSails preconditioner.  This function should be passed
 * to the iterative solver {\tt SetPrecond} function.
 *
 * @param solver [IN] Preconditioner object to apply.
 * @param A Ignored by this function.
 * @param b [IN] Vector to precondition.
 * @param x [OUT] Preconditioned vector.
 **/
int HYPRE_ParaSailsSolve(HYPRE_Solver       solver,
                         HYPRE_ParCSRMatrix A,
                         HYPRE_ParVector    b,
                         HYPRE_ParVector    x);

/**
 * Set the threshold and levels parameter for the ParaSails
 * preconditioner.  The accuracy and cost of ParaSails are
 * parameterized by these two parameters.  Lower values of the
 * threshold parameter and higher values of levels parameter 
 * lead to more accurate, but more expensive preconditioners.
 *
 * @param solver [IN] Preconditioner object for which to set parameters.
 * @param thresh [IN] Value of threshold parameter, $0 \le$ thresh $\le 1$.
 *                    The default value is 0.1.
 * @param nlevels [IN] Value of levels parameter, $0 \le$ nlevels.  
 *                     The default value is 1.
 **/
int HYPRE_ParaSailsSetParams(HYPRE_Solver solver,
                             double       thresh,
                             int          nlevels);
/**
 * Set the filter parameter for the 
 * ParaSails preconditioner.
 *
 * @param solver [IN] Preconditioner object for which to set filter parameter.
 * @param filter [IN] Value of filter parameter.  The filter parameter is
 *                    used to drop small nonzeros in the preconditioner,
 *                    to reduce the cost of applying the preconditioner.
 *                    Values from 0.05 to 0.1 are recommended.
 *                    The default value is 0.1.
 **/
int HYPRE_ParaSailsSetFilter(HYPRE_Solver solver,
                             double       filter);

/**
 * Set the symmetry parameter for the
 * ParaSails preconditioner.
 *
 * @param solver [IN] Preconditioner object for which to set symmetry parameter.
 * @param sym [IN] Value of the symmetry parameter:
 * \begin{tabular}{|c|l|} \hline
 * value & meaning \\ \hline
 * 0 & nonsymmetric and/or indefinite problem, and nonsymmetric preconditioner\\
 * 1 & SPD problem, and SPD (factored) preconditioner \\
 * 2 & nonsymmetric, definite problem, and SPD (factored) preconditioner \\
 * \hline
 * \end{tabular}
 **/
int HYPRE_ParaSailsSetSym(HYPRE_Solver solver,
                          int          sym);

/**
 * Set the load balance parameter for the
 * ParaSails preconditioner.
 *
 * @param solver [IN] Preconditioner object for which to set the load balance
 *                    parameter.
 * @param loadbal [IN] Value of the load balance parameter, 
 *                     $0 \le$ loadbal $\le 1$.  A zero value indicates that
 *                     no load balance is attempted; a value of unity indicates
 *                     that perfect load balance will be attempted.  The 
 *                     recommended value is 0.9 to balance the overhead of
 *                     data exchanges for load balancing.  No load balancing
 *                     is needed if the preconditioner is very sparse and
 *                     fast to construct.  The default value when this 
 *                     parameter is not set is 0.
 **/
int HYPRE_ParaSailsSetLoadbal(HYPRE_Solver solver,
                              double       loadbal);

/**
 * Set the pattern reuse parameter for the
 * ParaSails preconditioner.
 *
 * @param solver [IN] Preconditioner object for which to set the pattern reuse 
 *                    parameter.
 * @param reuse [IN] Value of the pattern reuse parameter.  A nonzero value
 *                   indicates that the pattern of the preconditioner should
 *                   be reused for subsequent constructions of the 
 *                   preconditioner.  A zero value indicates that the 
 *                   preconditioner should be constructed from scratch.
 *                   The default value when this parameter is not set is 0.
 **/
int HYPRE_ParaSailsSetReuse(HYPRE_Solver solver,
                            int          reuse);

/**
 * Set the logging parameter for the
 * ParaSails preconditioner.
 *
 * @param solver [IN] Preconditioner object for which to set the logging
 *                    parameter.
 * @param logging [IN] Value of the logging parameter.  A nonzero value
 *                     sends statistics of the setup procedure to stdout.
 *                     The default value when this parameter is not set is 0.
 **/
int HYPRE_ParaSailsSetLogging(HYPRE_Solver solver,
                              int          logging);

/**
 * Build IJ Matrix of the sparse approximate inverse (factor).
 *
 * @param solver [IN] Preconditioner object.
 * @param logging [OUT] Pointer to the IJ Matrix.
 **/
int HYPRE_ParaSailsBuildIJMatrix(HYPRE_Solver solver, HYPRE_IJMatrix *pij_A);


/*@}*/

/*--------------------------------------------------------------------------*
 *--------------------------------------------------------------------------*/

/**
 * @name ParCSR Euclid Preconditioner 
 *
 * MPI Parallel ILU preconditioner 
 *
 * Options summary:
 * \begin{center}
 * \begin{tabular}{|l|c|l|}
 * \hline
 * Option & Default & Synopsis \\
 * \hline
 * -level    & 1 & ILU($k$) factorization level \\ \hline
 * -bj       & 0 (false) & Use Block Jacobi ILU instead of PILU \\ \hline
 * -eu\_stats & 0 (false) & Print  internal timing and statistics \\ \hline
 * -eu\_mem   & 0 (false) & Print  internal memory usage \\ \hline
 * \end{tabular}
 * \end{center}
 *
 **/
/*@{*/

/**
 * Create a Euclid object.
 **/
int HYPRE_EuclidCreate(MPI_Comm      comm,
                             HYPRE_Solver *solver);

/**
 * Destroy a Euclid object.
 **/
int HYPRE_EuclidDestroy(HYPRE_Solver solver);

/**
 * Set up the Euclid preconditioner.  This function should be passed
 * to the iterative solver {\tt SetPrecond} function.
 *
 * @param solver [IN] Preconditioner object to set up.
 * @param A [IN] ParCSR matrix used to construct the preconditioner.
 * @param b Ignored by this function.
 * @param x Ignored by this function.
 **/
int HYPRE_EuclidSetup(HYPRE_Solver       solver,
                      HYPRE_ParCSRMatrix A,
                      HYPRE_ParVector    b,
                      HYPRE_ParVector    x);

/**
 * Apply the Euclid preconditioner. This function should be passed
 * to the iterative solver {\tt SetPrecond} function.
 *
 * @param solver [IN] Preconditioner object to apply.
 * @param A Ignored by this function.
 * @param b [IN] Vector to precondition.
 * @param x [OUT] Preconditioned vector.
 **/
int HYPRE_EuclidSolve(HYPRE_Solver       solver,
                      HYPRE_ParCSRMatrix A,
                      HYPRE_ParVector    b,
                      HYPRE_ParVector    x);

/**
 * Insert (name, value) pairs in Euclid's options database
 * by passing Euclid the command line (or an array of strings).
 * All Euclid options (e.g, level, drop-tolerance) are stored in
 * this database.  
 * If a (name, value) pair already exists, this call updates the value.
 * See also: HYPRE\_EuclidSetParamsFromFile.
 *
 * @param argc [IN] Length of argv array
 * @param argv [IN] Array of strings
 **/
int HYPRE_EuclidSetParams(HYPRE_Solver solver,
                          int argc,
                          char *argv[]);

/**
 * Insert (name, value) pairs in Euclid's options database.
 * Each line of the file should either begin with a ``\#,''
 * indicating a comment line, or contain a (name value)
 * pair, e.g: \\
 *
 * >cat optionsFile \\
 * \#sample runtime parameter file \\
 * -blockJacobi 3 \\
 * -matFile     /home/hysom/myfile.euclid \\
 * -doSomething true \\
 * -xx\_coeff -1.0
 *
 * See also: HYPRE\_EuclidSetParams.
 *
 * @param filename[IN] Pathname/filename to read
 **/
int HYPRE_EuclidSetParamsFromFile(HYPRE_Solver solver, char *filename);

/*@}*/
/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/**
 * @name ParCSR Pilut Preconditioner
 **/
/*@{*/

/**
 * Create a preconditioner object.
 **/
int HYPRE_ParCSRPilutCreate(MPI_Comm      comm,
                            HYPRE_Solver *solver);

/**
 * Destroy a preconditioner object.
 **/
int HYPRE_ParCSRPilutDestroy(HYPRE_Solver solver);

/**
 **/
int HYPRE_ParCSRPilutSetup(HYPRE_Solver       solver,
                           HYPRE_ParCSRMatrix A,
                           HYPRE_ParVector    b,
                           HYPRE_ParVector    x);

/**
 * Precondition the system.
 **/
int HYPRE_ParCSRPilutSolve(HYPRE_Solver       solver,
                           HYPRE_ParCSRMatrix A,
                           HYPRE_ParVector    b,
                           HYPRE_ParVector    x);

/**
 * (Optional) Set maximum number of iterations.
 **/
int HYPRE_ParCSRPilutSetMaxIter(HYPRE_Solver solver,
                                int          max_iter);

/**
 * (Optional)
 **/
int HYPRE_ParCSRPilutSetDropTolerance(HYPRE_Solver solver,
                                      double       tol);

/**
 * (Optional)
 **/
int HYPRE_ParCSRPilutSetFactorRowSize(HYPRE_Solver solver,
                                      int          size);

/*@}*/

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/**
 * @name ParCSR PCG Solver
 **/
/*@{*/

/**
 * Create a solver object.
 **/
int HYPRE_ParCSRPCGCreate(MPI_Comm      comm,
                          HYPRE_Solver *solver);

/**
 * Destroy a solver object.
 **/
int HYPRE_ParCSRPCGDestroy(HYPRE_Solver solver);

/**
 **/
int HYPRE_ParCSRPCGSetup(HYPRE_Solver       solver,
                         HYPRE_ParCSRMatrix A,
                         HYPRE_ParVector    b,
                         HYPRE_ParVector    x);

/**
 * Solve the system.
 **/
int HYPRE_ParCSRPCGSolve(HYPRE_Solver       solver,
                         HYPRE_ParCSRMatrix A,
                         HYPRE_ParVector    b,
                         HYPRE_ParVector    x);

/**
 * (Optional) Set the convergence tolerance.
 **/
int HYPRE_ParCSRPCGSetTol(HYPRE_Solver solver,
                          double       tol);

/**
 * (Optional) Set maximum number of iterations.
 **/
int HYPRE_ParCSRPCGSetMaxIter(HYPRE_Solver solver,
                              int          max_iter);

/*
 * RE-VISIT
 **/
int HYPRE_ParCSRPCGSetStopCrit(HYPRE_Solver solver,
                               int          stop_crit);

/**
 * (Optional) Use the two-norm in stopping criteria.
 **/
int HYPRE_ParCSRPCGSetTwoNorm(HYPRE_Solver solver,
                              int          two_norm);

/**
 * (Optional) Additionally require that the relative difference in
 * successive iterates be small.
 **/
int HYPRE_ParCSRPCGSetRelChange(HYPRE_Solver solver,
                                int          rel_change);

/**
 * (Optional) Set the preconditioner to use.
 **/
int HYPRE_ParCSRPCGSetPrecond(HYPRE_Solver         solver,
                              HYPRE_PtrToParSolverFcn precond,
                              HYPRE_PtrToParSolverFcn precond_setup,
                              HYPRE_Solver         precond_solver);

/**
 **/
int HYPRE_ParCSRPCGGetPrecond(HYPRE_Solver  solver,
                              HYPRE_Solver *precond_data);

/**
 * (Optional) Set the amount of print logging to do.
 **/
int HYPRE_ParCSRPCGSetPrintLevel(HYPRE_Solver solver,
                              int          logging);

/**
 * Return the number of iterations taken.
 **/
int HYPRE_ParCSRPCGGetNumIterations(HYPRE_Solver  solver,
                                    int          *num_iterations);

/**
 * Return the norm of the final relative residual.
 **/
int HYPRE_ParCSRPCGGetFinalRelativeResidualNorm(HYPRE_Solver  solver,
                                                double       *norm);

/**
 * Setup routine for diagonal preconditioning.
 **/
int HYPRE_ParCSRDiagScaleSetup(HYPRE_Solver       solver,
                               HYPRE_ParCSRMatrix A,
                               HYPRE_ParVector    y,
                               HYPRE_ParVector    x);

/**
 * Solve routine for diagonal preconditioning.
 **/
int HYPRE_ParCSRDiagScale(HYPRE_Solver       solver,
                          HYPRE_ParCSRMatrix HA,
                          HYPRE_ParVector    Hy,
                          HYPRE_ParVector    Hx);

/*@}*/

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/**
 * @name ParCSR GMRES Solver
 **/
/*@{*/

/**
 * Create a solver object.
 **/
int HYPRE_ParCSRGMRESCreate(MPI_Comm      comm,
                            HYPRE_Solver *solver);

/**
 * Destroy a solver object.
 **/
int HYPRE_ParCSRGMRESDestroy(HYPRE_Solver solver);

/**
 **/
int HYPRE_ParCSRGMRESSetup(HYPRE_Solver       solver,
                           HYPRE_ParCSRMatrix A,
                           HYPRE_ParVector    b,
                           HYPRE_ParVector    x);

/**
 * Solve the system.
 **/
int HYPRE_ParCSRGMRESSolve(HYPRE_Solver       solver,
                           HYPRE_ParCSRMatrix A,
                           HYPRE_ParVector    b,
                           HYPRE_ParVector    x);

/**
 * (Optional) Set the maximum size of the Krylov space.
 **/
int HYPRE_ParCSRGMRESSetKDim(HYPRE_Solver solver,
                             int          k_dim);

/**
 * (Optional) Set the convergence tolerance.
 **/
int HYPRE_ParCSRGMRESSetTol(HYPRE_Solver solver,
                            double       tol);

/*
 * RE-VISIT
 **/
int HYPRE_ParCSRGMRESSetMinIter(HYPRE_Solver solver,
                                int          min_iter);

/**
 * (Optional) Set maximum number of iterations.
 **/
int HYPRE_ParCSRGMRESSetMaxIter(HYPRE_Solver solver,
                                int          max_iter);

/*
 * RE-VISIT
 **/
int HYPRE_ParCSRGMRESSetStopCrit(HYPRE_Solver solver,
                                 int          stop_crit);

/**
 * (Optional) Set the preconditioner to use.
 **/
int HYPRE_ParCSRGMRESSetPrecond(HYPRE_Solver          solver,
                                HYPRE_PtrToParSolverFcn  precond,
                                HYPRE_PtrToParSolverFcn  precond_setup,
                                HYPRE_Solver          precond_solver);

/**
 **/
int HYPRE_ParCSRGMRESGetPrecond(HYPRE_Solver  solver,
                                HYPRE_Solver *precond_data);

/**
 * (Optional) Set the amount of logging to do.
 **/
int HYPRE_ParCSRGMRESSetLogging(HYPRE_Solver solver,
                                int          logging);

/**
 * Return the number of iterations taken.
 **/
int HYPRE_ParCSRGMRESGetNumIterations(HYPRE_Solver  solver,
                                      int          *num_iterations);

/**
 * Return the norm of the final relative residual.
 **/
int HYPRE_ParCSRGMRESGetFinalRelativeResidualNorm(HYPRE_Solver  solver,
                                                  double       *norm);

/*@}*/

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/*
 * @name Schwarz Solver
 **/

int HYPRE_SchwarzCreate( HYPRE_Solver *solver);

int HYPRE_SchwarzDestroy(HYPRE_Solver solver);

int HYPRE_SchwarzSetup(HYPRE_Solver       solver,
                              HYPRE_ParCSRMatrix A,
                              HYPRE_ParVector    b,
                              HYPRE_ParVector    x);

int HYPRE_SchwarzSolve(HYPRE_Solver       solver,
                              HYPRE_ParCSRMatrix A,
                              HYPRE_ParVector    b,
                              HYPRE_ParVector    x);

int HYPRE_SchwarzSetVariant(HYPRE_Solver solver, int variant);

int HYPRE_SchwarzSetOverlap(HYPRE_Solver solver, int overlap);

int HYPRE_SchwarzSetDomainType(HYPRE_Solver solver, int domain_type);

int HYPRE_SchwarzSetRelaxWeight(HYPRE_Solver solver, double relax_weight);

int HYPRE_SchwarzSetDomainStructure(HYPRE_Solver solver,
                                   HYPRE_CSRMatrix domain_structure);

int HYPRE_SchwarzSetNumFunctions(HYPRE_Solver solver, int num_functions);

int HYPRE_SchwarzSetDofFunc(HYPRE_Solver solver, int *dof_func);

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/*
 * @name ParCSR BiCGSTAB Solver
 **/

int HYPRE_ParCSRBiCGSTABCreate(MPI_Comm      comm,
                               HYPRE_Solver *solver);

int HYPRE_ParCSRBiCGSTABDestroy(HYPRE_Solver solver);

int HYPRE_ParCSRBiCGSTABSetup(HYPRE_Solver       solver,
                              HYPRE_ParCSRMatrix A,
                              HYPRE_ParVector    b,
                              HYPRE_ParVector    x);

int HYPRE_ParCSRBiCGSTABSolve(HYPRE_Solver       solver,
                              HYPRE_ParCSRMatrix A,
                              HYPRE_ParVector    b,
                              HYPRE_ParVector    x);

int HYPRE_ParCSRBiCGSTABSetTol(HYPRE_Solver solver,
                               double       tol);

int HYPRE_ParCSRBiCGSTABSetMinIter(HYPRE_Solver solver,
                                   int          min_iter);

int HYPRE_ParCSRBiCGSTABSetMaxIter(HYPRE_Solver solver,
                                   int          max_iter);

int HYPRE_ParCSRBiCGSTABSetStopCrit(HYPRE_Solver solver,
                                    int          stop_crit);

int HYPRE_ParCSRBiCGSTABSetPrecond(HYPRE_Solver         solver,
                                   HYPRE_PtrToParSolverFcn precond,
                                   HYPRE_PtrToParSolverFcn precond_setup,
                                   HYPRE_Solver         precond_solver);

int HYPRE_ParCSRBiCGSTABGetPrecond(HYPRE_Solver  solver,
                                   HYPRE_Solver *precond_data);

int HYPRE_ParCSRBiCGSTABSetLogging(HYPRE_Solver solver,
                                   int          logging);

int HYPRE_ParCSRBiCGSTABGetNumIterations(HYPRE_Solver  solver,
                                         int          *num_iterations);

int HYPRE_ParCSRBiCGSTABGetFinalRelativeResidualNorm(HYPRE_Solver  solver,
                                 		     double       *norm);

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/*
 * @name ParCSR CGNR Solver
 **/

int HYPRE_ParCSRCGNRCreate(MPI_Comm      comm,
                           HYPRE_Solver *solver);

int HYPRE_ParCSRCGNRDestroy(HYPRE_Solver solver);

int HYPRE_ParCSRCGNRSetup(HYPRE_Solver       solver,
                          HYPRE_ParCSRMatrix A,
                          HYPRE_ParVector    b,
                          HYPRE_ParVector    x);

int HYPRE_ParCSRCGNRSolve(HYPRE_Solver       solver,
                          HYPRE_ParCSRMatrix A,
                          HYPRE_ParVector    b,
                          HYPRE_ParVector    x);

int HYPRE_ParCSRCGNRSetTol(HYPRE_Solver solver,
                           double       tol);

int HYPRE_ParCSRCGNRSetMinIter(HYPRE_Solver solver,
                               int          min_iter);

int HYPRE_ParCSRCGNRSetMaxIter(HYPRE_Solver solver,
                               int          max_iter);

int HYPRE_ParCSRCGNRSetStopCrit(HYPRE_Solver solver,
                                int          stop_crit);

int HYPRE_ParCSRCGNRSetPrecond(HYPRE_Solver         solver,
                               HYPRE_PtrToParSolverFcn precond,
                               HYPRE_PtrToParSolverFcn precondT,
                               HYPRE_PtrToParSolverFcn precond_setup,
                               HYPRE_Solver         precond_solver);

int HYPRE_ParCSRCGNRGetPrecond(HYPRE_Solver  solver,
                               HYPRE_Solver *precond_data);

int HYPRE_ParCSRCGNRSetLogging(HYPRE_Solver solver,
                               int          logging);

int HYPRE_ParCSRCGNRGetNumIterations(HYPRE_Solver  solver,
                                     int          *num_iterations);

int HYPRE_ParCSRCGNRGetFinalRelativeResidualNorm(HYPRE_Solver  solver,
                                                 double       *norm);

/*--------------------------------------------------------------------------
 * Miscellaneous: These probably do not belong in the interface.
 *--------------------------------------------------------------------------*/

HYPRE_ParCSRMatrix GenerateLaplacian(MPI_Comm comm,
                                     int      nx,
                                     int      ny,
                                     int      nz,
                                     int      P,
                                     int      Q,
                                     int      R,
                                     int      p,
                                     int      q,
                                     int      r,
                                     double  *value);

int map(int ix,
        int iy,
        int iz,
        int p,
        int q,
        int r,
        int P,
        int Q,
        int R,
        int *nx_part,
        int *ny_part,
        int *nz_part,
        int *global_part);

HYPRE_ParCSRMatrix GenerateLaplacian27pt(MPI_Comm comm,
                                         int      nx,
                                         int      ny,
                                         int      nz,
                                         int      P,
                                         int      Q,
                                         int      R,
                                         int      p,
                                         int      q,
                                         int      r,
                                         double  *value);

int map3(int ix,
         int iy,
         int iz,
         int p,
         int q,
         int r,
         int P,
         int Q,
         int R,
         int *nx_part,
         int *ny_part,
         int *nz_part,
         int *global_part);

HYPRE_ParCSRMatrix GenerateLaplacian9pt(MPI_Comm comm,
                                        int      nx,
                                        int      ny,
                                        int      P,
                                        int      Q,
                                        int      p,
                                        int      q,
                                        double  *value);

int map2(int ix,
         int iy,
         int p,
         int q,
         int P,
         int Q,
         int *nx_part,
         int *ny_part,
         int *global_part);

HYPRE_ParCSRMatrix GenerateDifConv(MPI_Comm comm,
                                   int      nx,
                                   int      ny,
                                   int      nz,
                                   int      P,
                                   int      Q,
                                   int      R,
                                   int      p,
                                   int      q,
                                   int      r,
                                   double  *value);

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/*@}*/

/*
 * ParCSR ParaSails Preconditioner
 *
 * Parallel sparse approximate inverse preconditioner for the
 * ParCSR matrix format.
 **/

/*
 * Create a ParaSails preconditioner.
 **/
int HYPRE_ParCSRParaSailsCreate(MPI_Comm      comm,
                                HYPRE_Solver *solver);

/*
 * Destroy a ParaSails preconditioner.
 **/
int HYPRE_ParCSRParaSailsDestroy(HYPRE_Solver solver);

/*
 * Set up the ParaSails preconditioner.  This function should be passed
 * to the iterative solver {\tt SetPrecond} function.
 *
 * @param solver [IN] Preconditioner object to set up.
 * @param A [IN] ParCSR matrix used to construct the preconditioner.
 * @param b Ignored by this function.
 * @param x Ignored by this function.
 **/
int HYPRE_ParCSRParaSailsSetup(HYPRE_Solver       solver,
                               HYPRE_ParCSRMatrix A,
                               HYPRE_ParVector    b,
                               HYPRE_ParVector    x);

/*
 * Apply the ParaSails preconditioner.  This function should be passed
 * to the iterative solver {\tt SetPrecond} function.
 *
 * @param solver [IN] Preconditioner object to apply.
 * @param A Ignored by this function.
 * @param b [IN] Vector to precondition.
 * @param x [OUT] Preconditioned vector.
 **/
int HYPRE_ParCSRParaSailsSolve(HYPRE_Solver       solver,
                               HYPRE_ParCSRMatrix A,
                               HYPRE_ParVector    b,
                               HYPRE_ParVector    x);

/*
 * Set the threshold and levels parameter for the ParaSails
 * preconditioner.  The accuracy and cost of ParaSails are
 * parameterized by these two parameters.  Lower values of the
 * threshold parameter and higher values of levels parameter 
 * lead to more accurate, but more expensive preconditioners.
 *
 * @param solver [IN] Preconditioner object for which to set parameters.
 * @param thresh [IN] Value of threshold parameter, $0 \le$ thresh $\le 1$.
 *                    The default value is 0.1.
 * @param nlevels [IN] Value of levels parameter, $0 \le$ nlevels.  
 *                     The default value is 1.
 **/
int HYPRE_ParCSRParaSailsSetParams(HYPRE_Solver solver,
                                   double       thresh,
                                   int          nlevels);

/*
 * Set the filter parameter for the 
 * ParaSails preconditioner.
 *
 * @param solver [IN] Preconditioner object for which to set filter parameter.
 * @param filter [IN] Value of filter parameter.  The filter parameter is
 *                    used to drop small nonzeros in the preconditioner,
 *                    to reduce the cost of applying the preconditioner.
 *                    Values from 0.05 to 0.1 are recommended.
 *                    The default value is 0.1.
 **/
int HYPRE_ParCSRParaSailsSetFilter(HYPRE_Solver solver,
                                   double       filter);

/*
 * Set the symmetry parameter for the
 * ParaSails preconditioner.
 *
 * @param solver [IN] Preconditioner object for which to set symmetry parameter.
 * @param sym [IN] Value of the symmetry parameter:
 * \begin{tabular}{|c|l|} \hline
 * value & meaning \\ \hline
 * 0 & nonsymmetric and/or indefinite problem, and nonsymmetric preconditioner\\
 * 1 & SPD problem, and SPD (factored) preconditioner \\
 * 2 & nonsymmetric, definite problem, and SPD (factored) preconditioner \\
 * \hline
 * \end{tabular}
 **/
int HYPRE_ParCSRParaSailsSetSym(HYPRE_Solver solver,
                                int          sym);

/*
 * Set the load balance parameter for the
 * ParaSails preconditioner.
 *
 * @param solver [IN] Preconditioner object for which to set the load balance
 *                    parameter.
 * @param loadbal [IN] Value of the load balance parameter, 
 *                     $0 \le$ loadbal $\le 1$.  A zero value indicates that
 *                     no load balance is attempted; a value of unity indicates
 *                     that perfect load balance will be attempted.  The 
 *                     recommended value is 0.9 to balance the overhead of
 *                     data exchanges for load balancing.  No load balancing
 *                     is needed if the preconditioner is very sparse and
 *                     fast to construct.  The default value when this 
 *                     parameter is not set is 0.
 **/
int HYPRE_ParCSRParaSailsSetLoadbal(HYPRE_Solver solver,
                                    double       loadbal);

/*
 * Set the pattern reuse parameter for the
 * ParaSails preconditioner.
 *
 * @param solver [IN] Preconditioner object for which to set the pattern reuse 
 *                    parameter.
 * @param reuse [IN] Value of the pattern reuse parameter.  A nonzero value
 *                   indicates that the pattern of the preconditioner should
 *                   be reused for subsequent constructions of the 
 *                   preconditioner.  A zero value indicates that the 
 *                   preconditioner should be constructed from scratch.
 *                   The default value when this parameter is not set is 0.
 **/
int HYPRE_ParCSRParaSailsSetReuse(HYPRE_Solver solver,
                                  int          reuse);

/*
 * Set the logging parameter for the
 * ParaSails preconditioner.
 *
 * @param solver [IN] Preconditioner object for which to set the logging
 *                    parameter.
 * @param logging [IN] Value of the logging parameter.  A nonzero value
 *                     sends statistics of the setup procedure to stdout.
 *                     The default value when this parameter is not set is 0.
 **/
int HYPRE_ParCSRParaSailsSetLogging(HYPRE_Solver solver,
                                    int          logging);
/*
 * @name ParCSRHybrid Solver
 **/
 
int HYPRE_ParCSRHybridCreate( HYPRE_Solver *solver);
 
int HYPRE_ParCSRHybridDestroy(HYPRE_Solver solver);
 
int HYPRE_ParCSRHybridSetup(HYPRE_Solver solver,
                            HYPRE_ParCSRMatrix A,
                            HYPRE_ParVector b,
                            HYPRE_ParVector x); 
 
int HYPRE_ParCSRHybridSolve(HYPRE_Solver solver,
                            HYPRE_ParCSRMatrix A,
                            HYPRE_ParVector b,
                            HYPRE_ParVector x);
 
int HYPRE_ParCSRHybridSetTol(HYPRE_Solver solver,
                             double             tol);
 
int HYPRE_ParCSRHybridSetConvergenceTol(HYPRE_Solver solver,
                                        double             cf_tol);
 
int HYPRE_ParCSRHybridSetDSCGMaxIter(HYPRE_Solver solver,
                                     int                dscg_max_its);
 
int HYPRE_ParCSRHybridSetPCGMaxIter(HYPRE_Solver solver,
                                    int                pcg_max_its);
 
int HYPRE_ParCSRHybridSetTwoNorm(HYPRE_Solver solver,
                                 int                two_norm);
 
int HYPRE_ParCSRHybridSetRelChange(HYPRE_Solver solver,
                                   int                rel_change); 
 
int HYPRE_ParCSRHybridSetPrecond(HYPRE_Solver         solver,
                                 HYPRE_PtrToParSolverFcn precond,
                                 HYPRE_PtrToParSolverFcn precond_setup,
                                 HYPRE_Solver         precond_solver);
 
int HYPRE_ParCSRHybridSetLogging(HYPRE_Solver solver,
                                 int                logging);

int
HYPRE_ParCSRHybridSetPLogging( HYPRE_Solver solver,
                              int               plogging    );
 
int
HYPRE_ParCSRHybridSetStrongThreshold( HYPRE_Solver solver,
                              double            strong_threshold    );
 
int
HYPRE_ParCSRHybridSetMaxRowSum( HYPRE_Solver solver,
                              double             max_row_sum    );
 
int
HYPRE_ParCSRHybridSetTruncFactor( HYPRE_Solver solver,
                              double              trunc_factor    );
 
int
HYPRE_ParCSRHybridSetMaxLevels( HYPRE_Solver solver,
                              int                max_levels    );
 
int
HYPRE_ParCSRHybridSetMeasureType( HYPRE_Solver solver,
                              int                measure_type    );
 
int
HYPRE_ParCSRHybridSetCoarsenType( HYPRE_Solver solver,
                              int                coarsen_type    );
 
int
HYPRE_ParCSRHybridSetCycleType( HYPRE_Solver solver,
                              int                cycle_type    );
 
int
HYPRE_ParCSRHybridSetNumGridSweeps( HYPRE_Solver solver,
                              int               *num_grid_sweeps    );
 
int
HYPRE_ParCSRHybridSetGridRelaxType( HYPRE_Solver solver,
                              int               *grid_relax_type    );
 
int
HYPRE_ParCSRHybridSetGridRelaxPoints( HYPRE_Solver solver,
                              int              **grid_relax_points    );
 
int
HYPRE_ParCSRHybridSetRelaxWeight( HYPRE_Solver solver,
                              double             *relax_weight    );
 
int
HYPRE_ParCSRHybridSetOmega( HYPRE_Solver solver,
                              double             *omega    );
 
int HYPRE_ParCSRHybridGetNumIterations(HYPRE_Solver  solver,
                                       int                *num_its);
 
int HYPRE_ParCSRHybridGetDSCGNumIterations(HYPRE_Solver  solver,
                                           int                *dscg_num_its);
 
int HYPRE_ParCSRHybridGetPCGNumIterations(HYPRE_Solver  solver,
                                          int                *pcg_num_its);
 
int HYPRE_ParCSRHybridGetFinalRelativeResidualNorm(HYPRE_Solver  solver,                                                   double             *norm); 

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/ 
#ifdef __cplusplus
}
#endif

#endif
