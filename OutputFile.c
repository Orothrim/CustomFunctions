#include "OutputFile.h"
#include "/home/swift/code/customfunctions/VoxelStruct.h"

using namespace std;
using namespace cv;

void outputMeshlab(vector<Voxel> voxelGrid, vector<Voxel> new_voxels, char* filename) {
	// vector<Voxel> voxelGrid;
	// vector<Voxel> new_voxels;

	ofstream MeshlabFile(filename);

	MeshlabFile << "ply" << endl;
	MeshlabFile << "format ascii 1.0" << endl;
	MeshlabFile << "element vertex " << voxelGrid.size() + new_voxels.size() << endl;
	MeshlabFile << "property float x" << endl;
	MeshlabFile << "property float y" << endl;
	MeshlabFile << "property float z" << endl;
	MeshlabFile << "property uchar diffuse_red" << endl;
	MeshlabFile << "property uchar diffuse_green" << endl;
	MeshlabFile << "property uchar diffuse_blue" << endl;
	MeshlabFile << "end_header" << endl;

	for(size_t i=0; i < voxelGrid.size(); i++) {
		Voxel &v = voxelGrid[i];
		MeshlabFile << v.x << " " << v.y << " " << v.z << " " << (int)v.r << " " << (int)v.g << " " << (int)v.b << endl;
	}

	// Refined voxels
	for(size_t i=0; i < new_voxels.size(); i++) {
		Voxel &v = new_voxels[i];
		MeshlabFile << v.x << " " << v.y << " " << v.z << " " << (int)v.r << " " << (int)v.g << " " << (int)v.b << endl;
	}
}