#include "GraphicsDevice.hpp"

#include <dxgi1_4.h>
#include <wrl.h>

using namespace Microsoft::WRL;

namespace graphics
{
	void getHardwareAdapter(IDXGIFactory4* pFactory, IDXGIAdapter1** ppAdapter)
	{
		ppAdapter = nullptr;
		for (uint32_t adapterIndex = 0; ; ++adapterIndex)
		{
			IDXGIAdapter1* pAdapter = nullptr;
			HRESULT hr = pFactory->EnumAdapters1(adapterIndex, &pAdapter);
			if (hr == DXGI_ERROR_NOT_FOUND) break;

			if (SUCCEEDED(D3D12CreateDevice(pAdapter, D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
			{
				*ppAdapter = pAdapter;

				// TODO: Check capabilities

				return;
			}
			pAdapter->Release();
		}
	}

	GraphicsDevice GraphicsDevice::createDevice(const desc::Device& desc)
	{
		bool enableDebugLayer =
			(desc.debugMode == desc::Device::DebugMode::Enabled)
#if defined(_DEBUG)
			|| (desc.debugMode == desc::Device::DebugMode::Auto)
#endif
			;

		if (enableDebugLayer)
		{
			ComPtr<ID3D12Debug> debugController;
			if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController))))
			{
				debugController->EnableDebugLayer();
			}
			else
			{
				// TODO: Error Handling
			}
		}

		ComPtr<IDXGIFactory4> factory;
		if (!CreateDXGIFactory1(IID_PPV_ARGS(&factory)))
		{
			// TODO: Error handling
		}

		IDXGIAdapter1* pAdapter;
		getHardwareAdapter(factory.Get(), &pAdapter);
	}
}