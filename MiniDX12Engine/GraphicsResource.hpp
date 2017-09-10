#pragma once

#include "GraphicsDescriptor.hpp"

#include <d3d12.h>
#include <dxgi1_2.h>

#include <memory>

namespace graphics
{
	class SwapChain
	{
	public:
		SwapChain(ID3D12Device* device, HWND hWnd, const desc::SwapChain& desc);
		~SwapChain();
	private:
		std::shared_ptr<IDXGISwapChain1> m_swapChain;
	};

	class Texture
	{

	};

	class Buffer
	{

	};
}
