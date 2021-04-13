#ifndef hypre_MV_HPP
#define hypre_MV_HPP

#ifdef __cplusplus
extern "C" {
#endif

#if defined(HYPRE_USING_CUSPARSE)
HYPRE_Int hypreDevice_CSRSpGemmCusparse(HYPRE_Int m, HYPRE_Int k, HYPRE_Int n, cusparseMatDescr_t descr_A, HYPRE_Int nnzA, HYPRE_Int *d_ia, HYPRE_Int *d_ja, HYPRE_Complex *d_a, cusparseMatDescr_t descr_B, HYPRE_Int nnzB, HYPRE_Int *d_ib, HYPRE_Int *d_jb, HYPRE_Complex *d_b, HYPRE_Int *nnzC_out, HYPRE_Int **d_ic_out, HYPRE_Int **d_jc_out, HYPRE_Complex **d_c_out);
#endif

#ifdef __cplusplus
}
#endif

#endif