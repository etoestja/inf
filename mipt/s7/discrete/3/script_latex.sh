#!/bin/bash
solvers="glpk minos bonmin cbc scip couenne gecode ipopt jacob"
for solver in $solvers
do
    if [ -e ${solver}_results.json ]
    then
        echo "%Solver: $solver"
        echo "\subsection*{Solver $solver}"
        echo "Commands:"
        echo "\begin{verbatim}"
        echo -n " $ "
        cat ${solver}_out.txt
        echo "\end{verbatim}"
        echo "results.json:"
        echo "\begin{verbatim}"
        cat ${solver}_results.json
        echo "\end{verbatim}"
        echo ""
    fi
done
