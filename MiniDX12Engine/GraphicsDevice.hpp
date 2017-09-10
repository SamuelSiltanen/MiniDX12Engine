#pragma once

#include <memory>
#include <d3d12.h>
#include <dxgi1_4.h>

#include "GraphicsDescriptor.hpp"

namespace graphics
{
	class SwapChain;
	class GraphicsPipeline;
	class ComputePipeline;
	class Texture;
	class Buffer;

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

		// Resources and pipelines are created by the device
		SwapChain			createSwapChain(HWND hWnd, const desc::SwapChain& desc);
		GraphicsPipeline	createGraphicsPipeline(const desc::GraphicsPipeline& desc);
		ComputePipeline		createComputePipeline(const desc::ComputePipeline& desc);
		Texture				createTexture(const desc::Texture& desc);
		Buffer				createBuffer(const desc::Buffer& desc);

	private:
		GraphicsDevice(IDXGIAdapter1* pAdapter);

		std::shared_ptr<ID3D12Device> m_device;
	};
}
