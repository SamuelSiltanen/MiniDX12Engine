#pragma once

#include <memory>
#include <d3d12.h>
#include <dxgi1_4.h>

#include "GraphicsDescriptor.hpp"

namespace graphics
{
	class GraphicsDevice
	{
	public:
		// Don't allow creating new copies of the device
		GraphicsDevice()									= delete;
		GraphicsDevice(const GraphicsDevice&)				= delete;		
		GraphicsDevice& operator=(const GraphicsDevice&)	= delete;

		// Moving is allowed
		GraphicsDevice(GraphicsDevice&&)					= default;
		GraphicsDevice& operator=(GraphicsDevice&&)			= default;

		~GraphicsDevice();

		// A static factory function is used for device creation
		static GraphicsDevice createDevice(const desc::Device& desc);

	private:
		GraphicsDevice(IDXGIAdapter1* pAdapter);

		std::shared_ptr<ID3D12Device> m_device;
	};
}
