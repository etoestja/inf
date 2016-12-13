# abstract2.py

from __future__ import division
from pyomo.environ import *

model = AbstractModel()

model.I = Set()
model.J = Set()

model.c = Param(model.I, model.J)

model.x = Var(model.I, model.J, domain=NonNegativeReals)

def obj_expression(model):
    return summation(model.c, model.x)

model.OBJ = Objective(rule=obj_expression)

def constI(model, i):
    # return the expression for the constraint for i
    return sum(model.x[i,j] for j in model.J) == 1

def constJ(model, j):
    # return the expression for the constraint for i
    return sum(model.x[i,j] for i in model.I) == 1

# the next line creates one constraint for each member of the set model.I
model.c1 = Constraint(model.I, rule=constI)
model.c2 = Constraint(model.J, rule=constJ)

