#ifndef voxel_struct
#define voxel_struct
struct Voxel
{
	float x, y, z;
	float depth; // used to decide which camera colours the voxel
	unsigned char r, g, b;
	unsigned char camIndex;
};
#endif