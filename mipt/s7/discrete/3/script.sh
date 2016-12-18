#!/bin/bash
solvers="glpk minos bonmin cbc scip couenne gecode ipopt jacob"
for solver in $solvers
do
    echo "Solver: $solver"
    rm results.json
    cmd="pyomo solve assignment_problem.py assignment_problem.dat --solver=$solver"
    echo "$cmd" > ${solver}_out.txt
    $cmd 2>&1 >> ${solver}_out.txt
    mv results.json ${solver}_results.json
done
