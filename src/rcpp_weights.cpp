// This file is used to wrap C++ classes and functions defines in RcppExports.R
// All other R script files will use this file as a bridge to C++ classes and functions
//
// Author: lixun910@gmail.com
// Changes:
// 10/29/2020 init rcpp_weights.cpp

#include <Rcpp.h>
#include "libgeoda/weights/GeodaWeight.h"
#include "libgeoda/weights/GalWeight.h"
#include "libgeoda/gda_weights.h"
#include "libgeoda/gda_interface.h"
#include "libgeoda/libgeoda.h"

using namespace Rcpp;

// [[Rcpp::export]]
SEXP p_GeoDaWeight__new(int num_obs) 
{
  // create a pointer to an GeoDa object and wrap it
  // as an external pointer
  Rcpp::XPtr<GeoDaWeight> ptr( new GalWeight(num_obs) );

  // return the external pointer to the R side
  return ptr;
}

// [[Rcpp::export]]
SEXP p_GeoDaWeight__GetPointer(SEXP xp)
{
  // return c++ object pointer
  return xp;
}

//  [[Rcpp::export]]
void p_GeoDaWeight__SetNeighbors(SEXP xp, int idx, SEXP v_nbr_ids)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  std::vector<int> nbr_ids = as<std::vector<int> >(v_nbr_ids);

  if (idx <= 0) {
    Rcout << "The index of observations in SetNeighbor() function should start from 1." << std::endl;
    return;
  }

  for (int i=0; i<nbr_ids.size(); ++i) {
    if (nbr_ids[i] <= 0) {
      Rcout << "The index of observations in SetNeighbor() function should start from 1." << std::endl;
      return;
    }
  }

  // re-org index
  idx = idx - 1;
  for (int i=0; i<nbr_ids.size(); ++i) {
    nbr_ids[i] = nbr_ids[i] - 1;
  }

  // invoke the function
  ptr->SetNeighbors(idx, nbr_ids);
}

//  [[Rcpp::export]]
void p_GeoDaWeight__SetNeighborsAndWeights(SEXP xp, int idx, SEXP v_nbr_ids, SEXP v_nbr_w)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  std::vector<int> nbr_ids = as<std::vector<int> >(v_nbr_ids);
  std::vector<double> nbr_w = as<std::vector<double> >(v_nbr_w);

  if (idx <= 0) {
    Rcout << "The index of observations in SetNeighbor() function should start from 1." << std::endl;
    return;
  }

  for (int i=0; i<nbr_ids.size(); ++i) {
    if (nbr_ids[i] <= 0) {
      Rcout << "The index of observations in SetNeighbor() function should start from 1." << std::endl;
      return;
    }
  }

  // re-org index
  idx = idx - 1;
  for (int i=0; i<nbr_ids.size(); ++i) {
    nbr_ids[i] = nbr_ids[i] - 1;
  }

  // invoke the function
  ptr->SetNeighborsAndWeights(idx, nbr_ids, nbr_w);
}

//  [[Rcpp::export]]
void p_GeoDaWeight__GetNbrStats(SEXP xp)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  // invoke the function
  ptr->GetNbrStats();
}

//  [[Rcpp::export]]
int p_GeoDaWeight__GetNumObs(SEXP xp)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  // invoke the function
  return ptr->GetNumObs();
}

//  [[Rcpp::export]]
bool p_GeoDaWeight__IsSymmetric(SEXP xp)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  // invoke the function
  bool is_sym = ptr->IsSymmetric();

  return is_sym;
}

//  [[Rcpp::export]]
bool p_GeoDaWeight__HasIsolates(SEXP xp)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  // invoke the function
  bool has_iso = ptr->HasIsolates();

  return has_iso;
}

//  [[Rcpp::export]]
double p_GeoDaWeight__GetSparsity(SEXP xp)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  // invoke the function
  double sparsity = ptr->GetSparsity();

  return sparsity;
}

//  [[Rcpp::export]]
int p_GeoDaWeight__GetMinNeighbors(SEXP xp)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  // invoke the function
  int min_nbrs = ptr->GetMinNbrs();

  return min_nbrs;
}

//  [[Rcpp::export]]
int p_GeoDaWeight__GetMaxNeighbors(SEXP xp)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  // invoke the function
  int max_nbrs = ptr->GetMaxNbrs();

  return max_nbrs;
}

//  [[Rcpp::export]]
double p_GeoDaWeight__GetMeanNeighbors(SEXP xp)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  // invoke the function
  return ptr->GetMeanNbrs();
}

//  [[Rcpp::export]]
double p_GeoDaWeight__GetMedianNeighbors(SEXP xp)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  // invoke the function
  return ptr->GetMedianNbrs();
}

//  [[Rcpp::export]]
Rcpp::DataFrame p_GeoDaWeight__SpatialLag(SEXP xp, SEXP vals)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  std::vector<double> _vals = as<std::vector<double> >(vals);

  // invoke the function
  int num_obs = ptr->GetNumObs();

  Rcpp::NumericVector lags;
  for (int i=0; i<num_obs; ++i) {
    lags.push_back(ptr->SpatialLag(i, _vals));
  }

  Rcpp::DataFrame df = Rcpp::DataFrame::create(Rcpp::Named("Spatial Lag") = lags);
  return df;
}

//  [[Rcpp::export]]
int p_GeoDaWeight__GetNeighborSize(SEXP xp, int obs_idx)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  // invoke the function
  int nn_sz = ptr->GetNbrSize(obs_idx);

  return nn_sz;
}

//  [[Rcpp::export]]
bool p_GeoDaWeight__SaveToFile(SEXP xp, std::string out_path, std::string layer_name, std::string id_name, SEXP id_vec)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  if (TYPEOF(id_vec) == INTSXP) { // using integers as id_vec
    // convert
    std::vector<int> _id_vec = as<std::vector<int> >(id_vec);

    // invoke the function
    return ptr->Save(out_path.c_str(), layer_name.c_str(), id_name.c_str(), _id_vec);
  } else {
    // using strings as id_vec
    std::vector<std::string> _id_vec = as<std::vector<std::string> >(id_vec);

    // invoke the function
    return ptr->Save(out_path.c_str(), layer_name.c_str(), id_name.c_str(), _id_vec);
  }
}

//  [[Rcpp::export]]
NumericVector p_GeoDaWeight__GetNeighbors(SEXP xp, int obs_idx)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  // invoke the function
  std::vector<long> nn = ptr->GetNeighbors(obs_idx);

  // convert to Rcpp::StringVector
  NumericVector nv_nn(nn.size());

  for (int i=0; i<nn.size(); ++i) {
    nv_nn[i] = nn[i];
  }

  return nv_nn;
}

//  [[Rcpp::export]]
DoubleVector p_GeoDaWeight__GetNeighborWeights(SEXP xp, int obs_idx)
{
  // grab the object as a XPtr (smart pointer) to GeoDaWeight
  Rcpp::XPtr<GeoDaWeight> ptr(xp);

  // invoke the function
  std::vector<double> nnw = ptr->GetNeighborWeights(obs_idx);

  // convert to Rcpp::StringVector
  DoubleVector nv_nnw(nnw.size());

  for (int i=0; i<nnw.size(); ++i) {
    nv_nnw[i] = nnw[i];
  }

  return nv_nnw;
}

//  [[Rcpp::export]]
double p_gda_min_distthreshold(SEXP xp_geoda, bool is_arc, bool is_mile)
{
  // grab the object as a XPtr (smart pointer) to GeoDa
  Rcpp::XPtr<GeoDa> ptr(xp_geoda);
  GeoDa* geoda = static_cast<GeoDa*> (R_ExternalPtrAddr(ptr));

  // invoke the function
  double min_dist = gda_min_distthreshold(geoda, is_arc, is_mile);

  return min_dist;
}

//  [[Rcpp::export]]
SEXP p_gda_queen_weights(SEXP xp_geoda, int order, bool include_lower_order, double precision_threshold)
{
  // grab the object as a XPtr (smart pointer) to GeoDa
  Rcpp::XPtr<GeoDa> ptr(xp_geoda);
  GeoDa* geoda = static_cast<GeoDa*> (R_ExternalPtrAddr(ptr));

  // invoke the function
  GeoDaWeight* w = gda_queen_weights(geoda, order, include_lower_order, precision_threshold);

  Rcpp::XPtr<GeoDaWeight> w_ptr(w, true); // true: we need to register a delete finalizer with the external pointer.

  return w_ptr;
}

//  [[Rcpp::export]]
SEXP p_gda_rook_weights(SEXP xp_geoda, int order, bool include_lower_order, double precision_threshold)
{
  // grab the object as a XPtr (smart pointer) to GeoDa
  Rcpp::XPtr<GeoDa> ptr(xp_geoda);
  GeoDa* geoda = static_cast<GeoDa*> (R_ExternalPtrAddr(ptr));

  // invoke the function
  GeoDaWeight* w = gda_rook_weights(geoda, order, include_lower_order, precision_threshold);

  Rcpp::XPtr<GeoDaWeight> w_ptr(w, true);
  return w_ptr;
}

//  [[Rcpp::export]]
SEXP p_gda_distance_weights(SEXP xp_geoda, double dist_thres, double power, bool is_inverse, bool is_arc, bool is_mile)
{
  // grab the object as a XPtr (smart pointer) to GeoDa
  Rcpp::XPtr<GeoDa> ptr(xp_geoda);
  GeoDa* geoda = static_cast<GeoDa*> (R_ExternalPtrAddr(ptr));

  // invoke the function
  GeoDaWeight* w = gda_distance_weights(geoda, dist_thres, "", power, is_inverse, is_arc, is_mile, "", FALSE);

  Rcpp::XPtr<GeoDaWeight> w_ptr(w, true);
  return w_ptr;
}

//  [[Rcpp::export]]
SEXP p_gda_kernel_weights(SEXP xp_geoda, double bandwidth, std::string kernel_method, bool use_kernel_diagonals, double power, bool is_inverse, bool is_arc, bool is_mile)
{
  // grab the object as a XPtr (smart pointer) to GeoDa
  Rcpp::XPtr<GeoDa> ptr(xp_geoda);
  GeoDa* geoda = static_cast<GeoDa*> (R_ExternalPtrAddr(ptr));

  // invoke the function
  GeoDaWeight* w = gda_distance_weights(geoda, bandwidth, "", power, is_inverse, is_arc, is_mile, kernel_method, use_kernel_diagonals);

  Rcpp::XPtr<GeoDaWeight> w_ptr(w, true);
  return w_ptr;
}

//  [[Rcpp::export]]
SEXP p_gda_knn_weights(SEXP xp_geoda, int k, double power, bool is_inverse, bool is_arc, bool is_mile)
{
  // grab the object as a XPtr (smart pointer) to GeoDa
  Rcpp::XPtr<GeoDa> ptr(xp_geoda);
  GeoDa* geoda = static_cast<GeoDa*> (R_ExternalPtrAddr(ptr));

  // invoke the function
  GeoDaWeight* w = gda_knn_weights(geoda, k, power, is_inverse, is_arc, is_mile, "", 0, FALSE, FALSE, "");

  Rcpp::XPtr<GeoDaWeight> w_ptr(w, true);
  return w_ptr;
}

//  [[Rcpp::export]]
SEXP p_gda_kernel_knn_weights(SEXP xp_geoda, int k, double power, bool is_inverse, bool is_arc, bool is_mile, std::string kernel_method, double bandwidth, bool adaptive_bandwidth, bool use_kernel_diagonals)
{
  // grab the object as a XPtr (smart pointer) to GeoDa
  Rcpp::XPtr<GeoDa> ptr(xp_geoda);
  GeoDa* geoda = static_cast<GeoDa*> (R_ExternalPtrAddr(ptr));

  // invoke the function
  GeoDaWeight* w = gda_knn_weights(geoda, k, power, is_inverse, is_arc, is_mile, kernel_method, 0, adaptive_bandwidth, use_kernel_diagonals, "");

  Rcpp::XPtr<GeoDaWeight> w_ptr(w, true);
  return w_ptr;
}

//  [[Rcpp::export]]
SEXP p_gda_load_gal(const char* weights_path, SEXP v_id_vec)
{
  std::vector<std::string> id_vec;
  
  if (v_id_vec) id_vec = as<std::vector<std::string> >(v_id_vec);

  // invoke the function
  GeoDaWeight* w = gda_load_gal(weights_path, id_vec);

  Rcpp::XPtr<GeoDaWeight> w_ptr(w, true);
  return w_ptr;
}

//  [[Rcpp::export]]
SEXP p_gda_load_gwt(const char* weights_path, SEXP v_id_vec)
{
  std::vector<std::string> id_vec;
  
  if (v_id_vec) id_vec = as<std::vector<std::string> >(v_id_vec);

  // invoke the function
  GeoDaWeight* w = gda_load_gwt(weights_path, id_vec);

  Rcpp::XPtr<GeoDaWeight> w_ptr(w, true);
  return w_ptr;
}

//  [[Rcpp::export]]
SEXP p_gda_load_swm(const char* weights_path, SEXP v_id_vec)
{
  std::vector<int> id_vec;
  
  if (v_id_vec) id_vec = as<std::vector<int> >(v_id_vec);

  // invoke the function
  GeoDaWeight* w = gda_load_swm(weights_path, id_vec);

  Rcpp::XPtr<GeoDaWeight> w_ptr(w, true);
  return w_ptr;
}
