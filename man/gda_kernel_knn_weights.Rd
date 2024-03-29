% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/weights.R
\name{gda_kernel_knn_weights}
\alias{gda_kernel_knn_weights}
\title{(For internally use and test only) K-NN Kernel Spatial Weights}
\usage{
gda_kernel_knn_weights(
  geoda_obj,
  k,
  kernel_method,
  adaptive_bandwidth = TRUE,
  use_kernel_diagonals = FALSE,
  power = 1,
  is_inverse = FALSE,
  is_arc = FALSE,
  is_mile = TRUE
)
}
\arguments{
\item{geoda_obj}{An instance of geoda}

\item{k}{a positive integer number for k-nearest neighbors}

\item{kernel_method}{a string value, which has to be one of 'triangular',
'uniform', 'epanechnikov', 'quartic', 'gaussian'}

\item{adaptive_bandwidth}{(optional) TRUE (default) or FALSE: TRUE use
adaptive bandwidth calculated using distance of k-nearest neithbors,
FALSE use max distance of all observation to their k-nearest neighbors}

\item{use_kernel_diagonals}{(optional) FALSE (default) or TRUE, apply kernel
on the diagonal of weights matrix}

\item{power}{(optional) The power (or exponent) of a number says how many
times to use the number in a multiplication.}

\item{is_inverse}{(optional) FALSE (default) or TRUE, apply inverse on
distance value}

\item{is_arc}{(optional) FALSE (default) or TRUE, compute arc distance
between two observations}

\item{is_mile}{(optional) TRUE (default) or FALSE, convert distance unit from
mile to km.}
}
\value{
An instance of Weight-class
}
\description{
Create a kernel weights by specifying k-nearest neighbors and a
kernel method
}
\examples{
\dontrun{
guerry_path <- system.file("extdata", "Guerry.shp", package = "rgeoda")
guerry <- geoda_open(guerry_path)
adptkernel_w = gda_kernel_knn_weights(guerry, 6, "uniform")
summary(adptkernel_w)
}
}
\keyword{kernel}
\keyword{knn}
\keyword{weights}
