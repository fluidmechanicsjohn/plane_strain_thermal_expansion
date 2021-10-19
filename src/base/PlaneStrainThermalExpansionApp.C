#include "PlaneStrainThermalExpansionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
PlaneStrainThermalExpansionApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

PlaneStrainThermalExpansionApp::PlaneStrainThermalExpansionApp(InputParameters parameters) : MooseApp(parameters)
{
  PlaneStrainThermalExpansionApp::registerAll(_factory, _action_factory, _syntax);
}

PlaneStrainThermalExpansionApp::~PlaneStrainThermalExpansionApp() {}

void
PlaneStrainThermalExpansionApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"PlaneStrainThermalExpansionApp"});
  Registry::registerActionsTo(af, {"PlaneStrainThermalExpansionApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
PlaneStrainThermalExpansionApp::registerApps()
{
  registerApp(PlaneStrainThermalExpansionApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
PlaneStrainThermalExpansionApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  PlaneStrainThermalExpansionApp::registerAll(f, af, s);
}
extern "C" void
PlaneStrainThermalExpansionApp__registerApps()
{
  PlaneStrainThermalExpansionApp::registerApps();
}
