// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MFCTextViewer under MIT license
// (MainProject this is submodule to at https://github.com/BlazesRus/BlazesRusSharedCode)
// Other Required submodule at https://github.com/BlazesRus/MFCApp
// ***********************************************************************
#pragma once

//#include "AppPch.h"

#include "../MFCApp/MFCView.h"
#include "../VariableLists/StringVectorList.h"

class TextView : public MFCView
{
protected: // create from serialization only
    TextView() noexcept;
    virtual ~TextView()
    {
        Reset();
    }
    DECLARE_DYNCREATE(TextView)

// Attributes
public:
    StringVectorList ContentList;
    MFCDoc* GetDocument() const;

protected:

// Operations
public:
    /// <summary>
    /// Resets the storage of this instance.
    /// </summary>
    void Reset()
    {
        ContentList.clear();
    }

    //-------File Loading Operations-------------------------------------------------------
    
    /// <summary>
    /// Loads the data from file.
    /// </summary>
    /// <param name="FilePath">The file path.</param>
    /// <returns>bool</returns>
    bool LoadDataFromFile(std::string FilePath);

    /// <summary>
    /// Saves the loaded data to file. (if / or \ is last character(Targeting Directory instead of file), will instead create/replace TextFile.xml)
    /// </summary>
    /// <param name="FilePath">The file path. or file name </param>
    void SaveDataToFile(std::string FilePath);
//--------------------------------------------------------------------------------------

// Overrides
public:
    virtual void OnDraw(CDC* pDC);  // overridden to draw this view
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
#ifndef BlazesMFCApp_DisablePrinter
    virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
    virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
    virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
#endif

// Implementation
public:
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
    DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TextView.cpp
inline MFCDoc* TextView::GetDocument() const
   { return reinterpret_cast<MFCDoc*>(m_pDocument); }
#endif

