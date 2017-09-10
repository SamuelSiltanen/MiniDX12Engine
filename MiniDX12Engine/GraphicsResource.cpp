#include "GraphicsResource.hpp"

#include <dxgi1_2.h>
#include <wrl.h>

using namespace Microsoft::WRL;

namespace graphics
{
	SwapChain::SwapChain(ID3D12Device* device, HWND hWnd, const desc::SwapChain& desc)
	{
		ComPtr<IDXGIFactory2> factory;
		if (!CreateDXGIFactory1(IID_PPV_ARGS(&factory)))
		{
			// TODO: Error handling
		}

		DXGI_SWAP_CHAIN_DESC1 swapChainDesc;
		swapChainDesc.Width					= desc.width;
		swapChainDesc.Height				= desc.height;
		swapChainDesc.Format				= desc.format.toDXGI();
		swapChainDesc.Stereo				= FALSE;	// Not supported yet
		swapChainDesc.SampleDesc.Count		= 1;		// No multisampling
		swapChainDesc.SampleDesc.Quality	= 0;
		swapChainDesc.BufferUsage			= desc.usage.toDXGI();
		swapChainDesc.BufferCount			= desc.bufferCount;
		swapChainDesc.Scaling				= DXGI_SCALING_NONE; // No scaling
		swapChainDesc.SwapEffect			= DXGI_SWAP_EFFECT_DISCARD; // No other swap effects
		swapChainDesc.AlphaMode				= DXGI_ALPHA_MODE_UNSPECIFIED; // Not used
		swapChainDesc.Flags					= 0; // Not needed

		DXGI_SWAP_CHAIN_FULLSCREEN_DESC fullScreenDesc;
		if (desc.fullscreen)
		{
			fullScreenDesc.RefreshRate.Numerator	= 1;	// Try 60 Hz
			fullScreenDesc.RefreshRate.Denominator	= 60;
			fullScreenDesc.ScanlineOrdering			= DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
			fullScreenDesc.Scaling					= DXGI_MODE_SCALING_UNSPECIFIED;
			fullScreenDesc.Windowed					= FALSE;
		}

		IDXGISwapChain1* pSwapChain = m_swapChain.get();
		if (!SUCCEEDED(factory->CreateSwapChainForHwnd(device, hWnd, &swapChainDesc,
					   desc.fullscreen ? &fullScreenDesc : NULL, NULL, &pSwapChain)))	// Restricting content not used
		{
			// TODO: Error handling
		}
	}

	SwapChain::~SwapChain()
	{
		if (m_swapChain != nullptr)
		{
			m_swapChain->Release();
			m_swapChain = nullptr;
		}
	}
}