% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/utils.R
\name{eb_rates_standardization}
\alias{eb_rates_standardization}
\title{Empirical Bayes(EB) Rate Standardization}
\usage{
eb_rates_standardization(df)
}
\arguments{
\item{df}{A data frame with two selected variable: one is "event", anothor is
"base" variable. E.g. guerry[c("hr60", "po60")]}
}
\value{
A data.frame with two columns "EB Rate" and "IsNull".
}
\description{
The function to compute EB Rate Standardization from 
an event variable and a base variable.
}
\examples{
\dontrun{
library(sf)
nat <- st_read("natregimes.shp")
ebr <- eb_rates_standardization(nat[c("HR60", "PO60")])
ebr
}
}
