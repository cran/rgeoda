% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/weights.R
\name{update_weights}
\alias{update_weights}
\title{Update meta data of a spatial weights}
\usage{
update_weights(gda_w)
}
\arguments{
\item{gda_w}{A Weight object}
}
\description{
Update meta data of a spatial weights. This function can be used
after calling `set_neighbor()` function .
}
\examples{
\dontrun{
new_w <- create_weights(10)
set_neighbors(new_w, 1, c(2,3))
update_weights(new_w)
}
}
