#ifndef _GdkDx9_Mesh_h_
#define _GdkDx9_Mesh_h_

#include <d3d9.h>
#include <d3dx9.h>

namespace gdk
{
	namespace dx9
	{
		class Mesh
		{
		private:

			ID3DXMesh* mesh;
			ID3DXBuffer* geometry;
			IDirect3DTexture9* texture;
			DWORD materialNum;

		public:

			D3DXVECTOR3 position;
			D3DXVECTOR3 rotation;
			D3DXVECTOR3 scale;

			Mesh(const std::string& xFileDirectory, const std::string& textureFileDirectory);

			~Mesh();

			void Draw();

		};
	}
}

#endif	// _GdkDx9_Mesh_h_
