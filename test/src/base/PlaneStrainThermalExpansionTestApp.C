//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "PlaneStrainThermalExpansionTestApp.h"
#include "PlaneStrainThermalExpansionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
PlaneStrainThermalExpansionTestApp::validParams()
{
  InputParameters params = PlaneStrainThermalExpansionApp::validParams();
  return params;
}

PlaneStrainThermalExpansionTestApp::PlaneStrainThermalExpansionTestApp(InputParameters parameters) : MooseApp(parameters)
{
  PlaneStrainThermalExpansionTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

PlaneStrainThermalExpansionTestApp::~PlaneStrainThermalExpansionTestApp() {}

void
PlaneStrainThermalExpansionTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  PlaneStrainThermalExpansionApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"PlaneStrainThermalExpansionTestApp"});
    Registry::registerActionsTo(af, {"PlaneStrainThermalExpansionTestApp"});
  }
}

void
PlaneStrainThermalExpansionTestApp::registerApps()
{
  registerApp(PlaneStrainThermalExpansionApp);
  registerApp(PlaneStrainThermalExpansionTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
PlaneStrainThermalExpansionTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  PlaneStrainThermalExpansionTestApp::registerAll(f, af, s);
}
extern "C" void
PlaneStrainThermalExpansionTestApp__registerApps()
{
  PlaneStrainThermalExpansionTestApp::registerApps();
}
