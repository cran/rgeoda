% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/weights.R
\name{has_isolates}
\alias{has_isolates}
\title{Isolation/Island in Spatial Weights}
\usage{
has_isolates(gda_w)
}
\arguments{
\item{gda_w}{A Weight object}
}
\value{
A boolean value indicates if weights matrix is symmetric
}
\description{
Check if weights matrix has isolates, or if any observation has
no neighbors
}
\examples{
\dontrun{
guerry_path <- system.file("extdata", "Guerry.shp", package = "rgeoda")
guerry <- st_read(guerry_path)
queen_w <- queen_weights(guerry)
has_isolates(queen_w)
}
}
