% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/utils.R
\name{hinge30_breaks}
\alias{hinge30_breaks}
\title{(Box) Hinge30 Breaks}
\usage{
hinge30_breaks(df)
}
\arguments{
\item{df}{A data frame with selected variable. E.g. guerry["Crm_prs"]}
}
\value{
A vector of numeric values of computed breaks
}
\description{
Hinge30 breaks data into 6 groups like box plot groups
(Lower outlier, < 25%, 25-50%, 50-75%, >75%, Upper outlier) with hinge=3.0
}
\examples{
library(sf)
guerry_path <- system.file("extdata", "Guerry.shp", package = "rgeoda")
guerry <- st_read(guerry_path)
hinge30_breaks(guerry['Crm_prs'])
}
