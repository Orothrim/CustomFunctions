#ifndef _outputfile_included_h_
#define _outputfile_included_h_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include "OutputFile.c"
#include "/home/swift/code/customfunctions/VoxelStruct.h"

void outputMeshlab(vector<Voxel> voxelGrid, vector<Voxel> new_voxels, char* filename);

#endif
