% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/weights.R
\name{gda_distance_weights}
\alias{gda_distance_weights}
\title{(For internally use and test only) Distance-based Spatial Weights}
\usage{
gda_distance_weights(
  geoda_obj,
  dist_thres,
  power = 1,
  is_inverse = FALSE,
  is_arc = FALSE,
  is_mile = TRUE
)
}
\arguments{
\item{geoda_obj}{An instance of geoda-class}

\item{dist_thres}{A positive numeric value of distance threshold}

\item{power}{(optional) The power (or exponent) of a number indicates how
many times to use the number in a multiplication.}

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
Create a distance-based weights
}
\examples{
\dontrun{
guerry_path <- system.file("extdata", "Guerry.shp", package = "rgeoda")
guerry <- geoda_open(guerry_path)
dist_thres <- gda_min_distthreshold(guerry)
dist_w <- gda_distance_weights(guerry, dist_thres)
summary(dist_w)
}
}
\keyword{distance}
\keyword{weights}
