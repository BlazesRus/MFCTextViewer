// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MFCTextViewer under MIT license
// (MainProject this is submodule to at https://github.com/BlazesRus/BlazesRusSharedCode)
// Other Required submodule at https://github.com/BlazesRus/MFCApp
// ***********************************************************************
#pragma once

//#include "AppPch.h"
#include "../MFCApp/MFCApp.h"
#include "TextView.h"

#include "../OtherFunctions/MFCMacrosV3.h"
#include "../OtherFunctions/MFCBaseOneMacros.h"

class AppProcesser : public MFCApp<TextView>
{
    MFC_RuntimeExtPart01Base01(AppProcesser, MFCApp, TextView)
    //Any message map messages here
    MFC_RuntimeExtPart02()
    MFC_RuntimeExtClassName(AppProcesser)
};

MFC_RuntimeImplimentation(AppProcesser)
MFC_RuntimeClassImplimentation(AppProcesser)

extern AppProcesser theApp;