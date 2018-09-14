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

#include "qupdate.hpp"

namespace mfem
{

// *************************************************************************
void* qmemcpy::rHtoH(void *dest, const void *src, std::size_t bytes,
                     const bool async)
{
   dbg("=\033[m");
   if (bytes==0) return dest;
   assert(src); assert(dest);
   std::memcpy(dest,src,bytes);
   return dest;
}

// *************************************************************************
void* qmemcpy::rHtoD(void *dest, const void *src, std::size_t bytes,
                     const bool async)
{
   dbg(">\033[m");
   if (bytes==0) return dest;
   assert(src); assert(dest);
#ifdef __NVCC__
   checkCudaErrors(cuMemcpyHtoD((CUdeviceptr)dest,src,bytes));
   return dest;
#else
   return std::memcpy(dest,src,bytes);
#endif
}

// ***************************************************************************
void* qmemcpy::rDtoH(void *dest, const void *src, std::size_t bytes,
                     const bool async)
{
   dbg("<\033[m");
   if (bytes==0) return dest;
   assert(src); assert(dest);
#ifdef __NVCC__
   checkCudaErrors(cuMemcpyDtoH(dest,(CUdeviceptr)src,bytes));
   return dest;
#else
   return std::memcpy(dest,src,bytes);
#endif
}

// ***************************************************************************
void* qmemcpy::rDtoD(void *dest, const void *src, std::size_t bytes,
                     const bool async)
{
   dbg("=\033[m");
   if (bytes==0) return dest; 
   assert(src); assert(dest);
#ifdef __NVCC__
   checkCudaErrors(cuMemcpyDtoD((CUdeviceptr)dest,(CUdeviceptr)src,bytes));
   return dest;
#else
   return std::memcpy(dest,src,bytes);
#endif
}

} // mfem
