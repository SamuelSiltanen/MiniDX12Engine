#pragma once

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
