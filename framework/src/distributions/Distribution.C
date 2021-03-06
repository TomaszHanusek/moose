//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "Distribution.h"
#include "MooseRandom.h"

template <>
InputParameters
validParams<Distribution>()
{
  InputParameters params = validParams<MooseObject>();
  params.addRequiredParam<std::string>("type", "class/type name identifying the distribution");
  params.registerBase("Distribution");
  return params;
}

Distribution::Distribution(const InputParameters & parameters) : MooseObject(parameters) {}

Real
Distribution::median() const
{
  mooseError("The distribution '", name(), "' must override the median method.");
  return 0;
}
