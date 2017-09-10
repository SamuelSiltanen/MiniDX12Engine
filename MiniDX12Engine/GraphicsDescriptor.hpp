#pragma once

#include <inttypes.h>
#include <dxgi.h>

namespace graphics
{
	namespace desc
	{
		struct Device
		{
			enum class DebugMode
			{
				Auto,
				Disabled,
				Enabled
			};

			enum class Capability
			{
				Auto,
				DX11_0,
				DX11_1,
				DX12_0,
				DX12_1
			};

			DebugMode	debugMode	= DebugMode::Auto;
			Capability	capability	= Capability::Auto;
		};

		struct Format
		{
			// TODO

			DXGI_FORMAT toDXGI() const { return DXGI_FORMAT_R8G8B8A8_UNORM; } // TODO
		};

		struct Usage
		{
			// TODO

			DXGI_USAGE toDXGI() const { return DXGI_USAGE_BACK_BUFFER; } // TODO
		};

		struct SwapChain
		{
			uint32_t	width;
			uint32_t	height;
			Format		format;
			Usage		usage;
			uint32_t	bufferCount;
			bool		fullscreen;
		};

		struct GraphicsPipeline
		{

		};

		struct ComputePipeline
		{

		};

		struct Texture
		{

		};

		struct Buffer
		{

		};
	}
}
