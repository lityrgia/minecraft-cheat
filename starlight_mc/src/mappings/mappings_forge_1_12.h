#pragma once
namespace Mappings
{
	auto mappings_forge_1_12 = XOR_STR_S(R"(
{
	"world": {
		"obfuscated": "net/minecraft/client/multiplayer/WorldClient",
		"signature": "Lnet/minecraft/client/multiplayer/WorldClient;",
		"fields": [],
		"methods": []
	},
	"myPlayer": {
		"obfuscated": "net/minecraft/client/entity/EntityPlayerSP",
		"signature": "Lnet/minecraft/client/entity/EntityPlayerSP;",
		"fields": [],
		"methods": []
	},
	"otherPlayer": {
		"obfuscated": "net/minecraft/client/entity/EntityOtherPlayerMP",
		"signature": "Lnet/minecraft/client/entity/EntityOtherPlayerMP;",
		"fields": [],
		"methods": []
	},
	"axisAligned": {
		"obfuscated": "net/minecraft/util/math/AxisAlignedBB",
		"signature": "Lnet/minecraft/util/math/AxisAlignedBB;"
	},
	"render": {
		"obfuscated": "net/minecraft/client/renderer/entity/RenderManager",
		"fc": "net.minecraft.client.renderer.entity.RenderManager",
		"signature": "Lnet/minecraft/client/renderer/entity/RenderManager;"
	},
	"entity": {
		"obfuscated": "net/minecraft/entity/Entity",
		"signature": "Lnet/minecraft/entity/Entity;"
	},
	"net/minecraft/client/Minecraft": {
		"obfuscated": "net/minecraft/client/Minecraft",
		"fields": [
			{
				"name": "theMinecraft",
				"obfuscated": "field_71432_P",
				"signature": "Lnet/minecraft/client/Minecraft;",
				"static": true
			},
			{
				"name": "thePlayer",
				"obfuscated": "field_71439_g",
				"signature": "Lnet/minecraft/client/entity/EntityPlayerSP;",
				"static": false
			},
			{
				"name": "theWorld",
				"obfuscated": "field_71441_e",
				"signature": "Lnet/minecraft/client/multiplayer/WorldClient;",
				"static": false
			},
			{
				"name": "gameSettings",
				"obfuscated": "field_71474_y",
				"signature": "Lnet/minecraft/client/settings/GameSettings;",
				"static": false
			},
			{
				"name": "objectMouseOver",
				"obfuscated": "field_71476_x",
				"signature": "Lnet/minecraft/util/MovingObjectPosition;",
				"static": false
			},
			{
				"name": "rightClickDelayTimer",
				"obfuscated": "field_71467_ac",
				"signature": "I",
				"static": false
			},
			{
				"name": "pointedEntity",
				"obfuscated": "field_147125_j",
				"signature": "Lnet/minecraft/entity/Entity;",
				"static": false
			},
			{
				"name": "timer",
				"obfuscated": "field_71428_T",
				"signature": "Lnet/minecraft/util/Timer;",
				"static": false
			},
			{
				"name": "playerController",
				"obfuscated": "field_71442_b",
				"signature": "Lnet/minecraft/client/multiplayer/PlayerControllerMP;",
				"static": false
			},
			{
				"name": "currentScreen",
				"obfuscated": "field_71462_r",
				"signature": "Lnet/minecraft/client/gui/GuiScreen;",
				"static": false
			},
			{
				"name": "renderViewEntity",
				"obfuscated": "field_71451_h",
				"signature": "Lnet/minecraft/entity/EntityLivingBase;",
				"static": false
			}
		],
		"methods": [
			{
				"name": "clickMouse",
				"obfuscated": "func_147116_af",
				"signature": "()V",
				"static": false
			}
		]
	},
	"net/minecraft/client/entity/EntityPlayerSP": {
		"obfuscated": "net/minecraft/client/entity/EntityPlayerSP",
		"fields": [
			{
				"name": "sendQueue",
				"obfuscated": "field_71174_a",
				"signature": "Lnet/minecraft/client/network/NetHandlerPlayClient;",
				"static": false
			}
		],
		"methods": [
			{
				"name": "onUpdateWalkingPlayer",
				"obfuscated": "func_71166_b",
				"signature": "()V",
				"static": false
			}
		]
	},
	"net/minecraft/client/entity/EntityPlayerSP": {
		"obfuscated": "net/minecraft/client/entity/EntityPlayerSP",
		"fields": [],
		"methods": []
	},
	"net/minecraft/client/entity/AbstractClientPlayer": {
		"obfuscated": "net/minecraft/client/entity/AbstractClientPlayer",
		"fields": [],
		"methods": []
	},
	"net/minecraft/entity/player/EntityPlayer": {
		"obfuscated": "net/minecraft/entity/player/EntityPlayer",
		"fields": [],
		"methods": [
			{
				"name": "attackTargetEntityWithCurrentItem",
				"obfuscated": "func_71059_n",
				"signature": "(Lnet/minecraft/entity/Entity;)V",
				"static": false
			}
		]
	},
	"net/minecraft/entity/EntityLivingBase": {
		"obfuscated": "net/minecraft/entity/EntityLivingBase",
		"fields": [],
		"methods": [
			{
				"name": "setPositionAndUpdate",
				"obfuscated": "func_70634_a",
				"signature": "(DDD)V",
				"static": false
			}
		]
	},
	"net/minecraft/entity/Entity": {
		"obfuscated": "net/minecraft/entity/Entity",
		"fields": [
			{
				"name": "posX",
				"obfuscated": "field_70165_t",
				"signature": "D",
				"static": false
			},
			{
				"name": "posY",
				"obfuscated": "field_70163_u",
				"signature": "D",
				"static": false
			},
			{
				"name": "posZ",
				"obfuscated": "field_70161_v",
				"signature": "D",
				"static": false
			},
			{
				"name": "rotationYaw",
				"obfuscated": "field_70177_z",
				"signature": "F",
				"static": false
			},
			{
				"name": "rotationPitch",
				"obfuscated": "field_70125_A",
				"signature": "F",
				"static": false
			},
			{
				"name": "motionX",
				"obfuscated": "field_70159_w",
				"signature": "D",
				"static": false
			},
			{
				"name": "motionY",
				"obfuscated": "field_70181_x",
				"signature": "D",
				"static": false
			},
			{
				"name": "motionZ",
				"obfuscated": "field_70179_y",
				"signature": "D",
				"static": false
			},
			{
				"name": "hurtResistantTime",
				"obfuscated": "field_70172_ad",
				"signature": "I",
				"static": false
			},
			{
				"name": "ticksExisted",
				"obfuscated": "field_70173_aa",
				"signature": "I",
				"static": false
			},
			{
				"name": "boundingBox",
				"obfuscated": "field_70121_D",
				"signature": "Lnet/minecraft/util/math/AxisAlignedBB;",
				"static": false
			},
			{
				"name": "lastTickPosX",
				"obfuscated": "field_70142_S",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickPosY",
				"obfuscated": "field_70137_T",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickPosZ",
				"obfuscated": "field_70136_U",
				"signature": "D",
				"static": false
			},
			{
				"name": "onGround",
				"obfuscated": "field_70122_E",
				"signature": "Z",
				"static": false
			},
			{
				"name": "ridingEntity",
				"obfuscated": "field_70154_o",
				"signature": "Lnet/minecraft/entity/Entity;",
				"static": false
			},
			{
				"name": "prevRotationYaw",
				"obfuscated": "field_70126_B",
				"signature": "F",
				"static": false
			},
			{
				"name": "prevRotationPitch",
				"obfuscated": "field_70127_C",
				"signature": "F",
				"static": false
			},
			{
				"name": "entityId",
				"obfuscated": "field_145783_c",
				"signature": "I",
				"static": false
			}
		],
		"methods": [
			{
				"name": "getEyeHeight",
				"obfuscated": "func_70047_e",
				"signature": "()F",
				"static": false
			},
			{
				"name": "isSprinting",
				"obfuscated": "func_70051_ag",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "setSprinting",
				"obfuscated": "func_70031_b",
				"signature": "(Z)V",
				"static": false
			},
			{
				"name": "setPosition",
				"obfuscated": "func_70107_b",
				"signature": "(DDD)V",
				"static": false
			}
		]
	},
	"net/minecraft/client/multiplayer/WorldClient": {
		"obfuscated": "net/minecraft/client/multiplayer/WorldClient",
		"fields": [
			{
				"name": "entityList",
				"obfuscated": "field_73032_d",
				"signature": "Ljava/util/Set;",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/util/Vec3": {
		"obfuscated": "net/minecraft/util/Vec3",
		"fields": [
			{
				"name": "xCoord",
				"obfuscated": "field_72450_a",
				"signature": "D",
				"static": false
			},
			{
				"name": "yCoord",
				"obfuscated": "field_72448_b",
				"signature": "D",
				"static": false
			},
			{
				"name": "zCoord",
				"obfuscated": "field_72449_c",
				"signature": "D",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/client/renderer/EntityRenderer": {
		"obfuscated": "net/minecraft/client/renderer/EntityRenderer",
		"fields": [],
		"methods": [
			{
				"name": "getMouseOver",
				"obfuscated": "func_78473_a",
				"signature": "(F)V",
				"static": false
			}
		]
	},
	"net/minecraft/client/renderer/entity/RenderManager": {
		"obfuscated": "net/minecraft/client/renderer/entity/RenderManager",
		"fields": [],
		"methods": [
			{
				"name": "renderEntityStatic",
				"obfuscated": "func_188388_a",
				"signature": "(Lnet/minecraft/entity/Entity;FZ)V",
				"static": false
			}
		]
	},
	"net/minecraft/util/math/AxisAlignedBB": {
		"obfuscated": "net/minecraft/util/math/AxisAlignedBB",
		"fields": [
			{
				"name": "minX",
				"obfuscated": "field_72340_a",
				"signature": "D",
				"static": false
			},
			{
				"name": "minY",
				"obfuscated": "field_72338_b",
				"signature": "D",
				"static": false
			},
			{
				"name": "minZ",
				"obfuscated": "field_72339_c",
				"signature": "D",
				"static": false
			},
			{
				"name": "maxX",
				"obfuscated": "field_72336_d",
				"signature": "D",
				"static": false
			},
			{
				"name": "maxY",
				"obfuscated": "field_72337_e",
				"signature": "D",
				"static": false
			},
			{
				"name": "maxZ",
				"obfuscated": "field_72334_f",
				"signature": "D",
				"static": false
			}
		],
		"methods": []
	}
}
)");
}