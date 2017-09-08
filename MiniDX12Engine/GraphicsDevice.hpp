#pragma once

#include <memory>
#include <d3d12.h>

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

		static GraphicsDevice createDevice(const desc::Device& desc);

	private:
		std::shared_ptr<ID3D12Device> m_device;
	};
}
