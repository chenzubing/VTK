/*=========================================================================

  Program:   ParaView
  Module:    vtkXMLHierarchicalDataReader.cxx

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkXMLHierarchicalDataReader.h"

#include "vtkCompositeDataPipeline.h"
#include "vtkHierarchicalDataSet.h"
#include "vtkObjectFactory.h"

vtkCxxRevisionMacro(vtkXMLHierarchicalDataReader, "1.4");
vtkStandardNewMacro(vtkXMLHierarchicalDataReader);

//----------------------------------------------------------------------------
vtkXMLHierarchicalDataReader::vtkXMLHierarchicalDataReader()
{
}

//----------------------------------------------------------------------------
vtkXMLHierarchicalDataReader::~vtkXMLHierarchicalDataReader()
{
}

//----------------------------------------------------------------------------
void vtkXMLHierarchicalDataReader::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

//----------------------------------------------------------------------------
vtkHierarchicalDataSet* vtkXMLHierarchicalDataReader::GetOutput()
{
  return this->GetOutput(0);
}

//----------------------------------------------------------------------------
vtkHierarchicalDataSet* vtkXMLHierarchicalDataReader::GetOutput(int port)
{
  vtkDataObject* output = 
    vtkCompositeDataPipeline::SafeDownCast(this->GetExecutive())->
    GetCompositeOutputData(port);
  return vtkHierarchicalDataSet::SafeDownCast(output);
}


//----------------------------------------------------------------------------
const char* vtkXMLHierarchicalDataReader::GetDataSetName()
{
  return "vtkHierarchicalDataSet";
}

