#!/bin/sh
#BHEADER**********************************************************************
# Copyright (c) 2008,  Lawrence Livermore National Security, LLC.
# Produced at the Lawrence Livermore National Laboratory.
# This file is part of HYPRE.  See file COPYRIGHT for details.
#
# HYPRE is free software; you can redistribute it and/or modify it under the
# terms of the GNU Lesser General Public License (as published by the Free
# Software Foundation) version 2.1 dated February 1999.
#
# $Revision$
#EHEADER**********************************************************************

testname=`basename $0 .sh`

# Echo usage information
case $1 in
   -h|-help)
      cat <<EOF

   $0 [-h|-help] {src_dir}

   where: {src_dir}  is the hypre source directory
          -h|-help   prints this usage information and exits

   This script checks for 'MPI_' in certain sections of hypre.

   Example usage: $0 ..

EOF
      exit
      ;;
esac

# Setup
src_dir=$1
shift

cd $src_dir

find . -type f -print | egrep '[.]*[.](c|cc|cpp|cxx|C|h|hpp|hxx|H)$' |
  egrep -v '/AUTOTEST' |
  egrep -v '/babel' |
  egrep -v '/cmbuild' |
  egrep -v '/docs' |
  egrep -v '/docs_misc' |
  egrep -v '/examples' |
  egrep -v '/FEI_mv' |
  egrep -v '/hypre/include' > check-mpi.files

egrep '(^|[^[:alnum:]_]+)MPI_' `cat check-mpi.files` |
  egrep -v 'MPI_Comm([^_]|$)' >&2

rm -f check-mpi.files
