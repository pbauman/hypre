/*BHEADER**********************************************************************
 * (c) 1996   The Regents of the University of California
 *
 * See the file COPYRIGHT_and_DISCLAIMER for a complete copyright
 * notice, contact person, and disclaimer.
 *
 * $Revision$
 *********************************************************************EHEADER*/

/******************************************************************************
 *
 * Header info for AMGS01 solver
 *
 *****************************************************************************/

#ifndef _AMGS01_HEADER
#define _AMGS01_HEADER


/*--------------------------------------------------------------------------
 * AMGS01Data
 *--------------------------------------------------------------------------*/

typedef struct
{
   /* setup params */
   int      levmax;
   int      ncg;
   double   ecg;
   int      nwt;
   double   ewt;
   int      nstr;

   /* solve params */
   int      ncyc;
   int     *mu;
   int     *ntrlx;
   int     *iprlx;
   int     *ierlx;
   int     *iurlx;

   /* output params */
   int      ioutdat;
   int      ioutgrd;
   int      ioutmat;
   int      ioutres;
   int      ioutsol;

   /* problem data */
   Problem *problem;

   /* operator and interpolation arrays */
   Matrix  *A;
   Matrix  *P;

   /* data generated by the setup phase */
   int      num_levels;
   int      ndimu;
   int      ndimp;
   int      ndima;
   int      ndimb;
   int     *icdep;
   int     *imin;
   int     *imax;
   int     *ipmn;
   int     *ipmx;
   int     *icg;
   int     *ifg;
   Matrix **A_array;
   Matrix **P_array;
   int     *leva;
   int     *levb;
   int     *levv;
   int     *levp;
   int     *levpi;
   int     *levi;
   int     *numa;
   int     *numb;
   int     *numv;
   int     *nump;

   char    *log_file_name;

} AMGS01Data;

/*--------------------------------------------------------------------------
 * Accessor functions for the AMGS01Data structure
 *--------------------------------------------------------------------------*/

#define AMGS01DataLevMax(amgs01_data)      ((amgs01_data) -> levmax)
#define AMGS01DataNCG(amgs01_data)         ((amgs01_data) -> ncg)
#define AMGS01DataECG(amgs01_data)         ((amgs01_data) -> ecg)
#define AMGS01DataNWT(amgs01_data)         ((amgs01_data) -> nwt)
#define AMGS01DataEWT(amgs01_data)         ((amgs01_data) -> ewt)
#define AMGS01DataNSTR(amgs01_data)        ((amgs01_data) -> nstr)
		  
#define AMGS01DataNCyc(amgs01_data)        ((amgs01_data) -> ncyc)
#define AMGS01DataMU(amgs01_data)          ((amgs01_data) -> mu)
#define AMGS01DataNTRLX(amgs01_data)       ((amgs01_data) -> ntrlx)
#define AMGS01DataIPRLX(amgs01_data)       ((amgs01_data) -> iprlx)
#define AMGS01DataIERLX(amgs01_data)       ((amgs01_data) -> ierlx)
#define AMGS01DataIURLX(amgs01_data)       ((amgs01_data) -> iurlx)
		  
#define AMGS01DataIOutDat(amgs01_data)     ((amgs01_data) -> ioutdat)
#define AMGS01DataIOutGrd(amgs01_data)     ((amgs01_data) -> ioutgrd)
#define AMGS01DataIOutMat(amgs01_data)     ((amgs01_data) -> ioutmat)
#define AMGS01DataIOutRes(amgs01_data)     ((amgs01_data) -> ioutres)
#define AMGS01DataIOutSol(amgs01_data)     ((amgs01_data) -> ioutsol)

#define AMGS01DataProblem(amgs01_data)     ((amgs01_data) -> problem)

#define AMGS01DataNumLevels(amgs01_data)   ((amgs01_data) -> num_levels)
#define AMGS01DataA(amgs01_data)           ((amgs01_data) -> A)
#define AMGS01DataNDIMU(amgs01_data)       ((amgs01_data) -> ndimu)
#define AMGS01DataNDIMP(amgs01_data)       ((amgs01_data) -> ndimp)
#define AMGS01DataNDIMA(amgs01_data)       ((amgs01_data) -> ndima)
#define AMGS01DataNDIMB(amgs01_data)       ((amgs01_data) -> ndimb)
#define AMGS01DataP(amgs01_data)           ((amgs01_data) -> P)
#define AMGS01DataICDep(amgs01_data)       ((amgs01_data) -> icdep)
#define AMGS01DataIMin(amgs01_data)        ((amgs01_data) -> imin)
#define AMGS01DataIMax(amgs01_data)        ((amgs01_data) -> imax)
#define AMGS01DataIPMN(amgs01_data)        ((amgs01_data) -> ipmn)
#define AMGS01DataIPMX(amgs01_data)        ((amgs01_data) -> ipmx)
#define AMGS01DataICG(amgs01_data)         ((amgs01_data) -> icg)
#define AMGS01DataIFG(amgs01_data)         ((amgs01_data) -> ifg)

#define AMGS01DataAArray(amgs01_data)      ((amgs01_data) -> A_array)
#define AMGS01DataPArray(amgs01_data)      ((amgs01_data) -> P_array)
#define AMGS01DataLevA(amgs01_data)        ((amgs01_data) -> leva)
#define AMGS01DataLevB(amgs01_data)        ((amgs01_data) -> levb)
#define AMGS01DataLevV(amgs01_data)        ((amgs01_data) -> levv)
#define AMGS01DataLevP(amgs01_data)        ((amgs01_data) -> levp)
#define AMGS01DataLevPI(amgs01_data)       ((amgs01_data) -> levpi)
#define AMGS01DataLevI(amgs01_data)        ((amgs01_data) -> levi)
#define AMGS01DataNumA(amgs01_data)        ((amgs01_data) -> numa)
#define AMGS01DataNumB(amgs01_data)        ((amgs01_data) -> numb)
#define AMGS01DataNumV(amgs01_data)        ((amgs01_data) -> numv)
#define AMGS01DataNumP(amgs01_data)        ((amgs01_data) -> nump)

#define AMGS01DataLogFileName(amgs01_data) ((amgs01_data) -> log_file_name)


#endif
