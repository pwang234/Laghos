// Copyright (c) 2017, Lawrence Livermore National Security, LLC. Produced at
// the Lawrence Livermore National Laboratory. LLNL-CODE-734707. All Rights
// reserved. See files LICENSE and NOTICE for details.
//
// This file is part of CEED, a collection of benchmarks, miniapps, software
// libraries and APIs for efficient high-order finite element and spectral
// element discretizations for exascale applications. For more information and
// source code availability see http://github.com/ceed.
//
// The CEED research is supported by the Exascale Computing Project 17-SC-20-SC,
// a collaborative effort of two U.S. Department of Energy organizations (Office
// of Science and the National Nuclear Security Administration) responsible for
// the planning and preparation of a capable exascale ecosystem, including
// software, applications, hardware, advanced system engineering and early
// testbed platforms, in support of the nation's exascale computing imperative.


#ifndef MFEM_LAGHOS_FPE
#define MFEM_LAGHOS_FPE

#include <cfenv>

namespace mfem
{
#define MFEM_FE_CLEAR_EXCEPT std::feclearexcept(FE_ALL_EXCEPT);

//MFEM_VERIFY(!std::fetestexcept(FE_INEXACT), "FE_INEXACT");
//MFEM_VERIFY(!std::fetestexcept(FE_ALL_EXCEPT), "FE_ALL_EXCEPT");

#define MFEM_FE_TEST_EXCEPT {                                           \
      MFEM_VERIFY(!std::fetestexcept(FE_DIVBYZERO), "FE_DIVBYZERO");    \
      MFEM_VERIFY(!std::fetestexcept(FE_OVERFLOW), "FE_OVERFLOW");      \
      MFEM_VERIFY(!std::fetestexcept(FE_UNDERFLOW), "FE_UNDERFLOW");    \
   }

} // namespace mfem

#endif // MFEM_LAGHOS_FPE
