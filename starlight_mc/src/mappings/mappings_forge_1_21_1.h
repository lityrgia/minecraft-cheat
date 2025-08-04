#pragma once
namespace Mappings
{
	auto mappings_forge_1_21_1 = XOR_STR_S(R"(
{
	"minecraft": {
		"obfuscated": "net/minecraft/client/Minecraft",
		"signature": "Lnet/minecraft/client/Minecraft;",
		"fields": [],
		"methods": []
	},
	"world": {
		"obfuscated": "net/minecraft/client/multiplayer/ClientLevel",
		"signature": "Lnet/minecraft/client/multiplayer/ClientLevel;",
		"fields": [],
		"methods": []
	},
	"myPlayer": {
		"obfuscated": "net/minecraft/client/player/LocalPlayer",
		"signature": "Lnet/minecraft/client/player/LocalPlayer;",
		"fields": [],
		"methods": []
	},
	"otherPlayer": {
		"obfuscated": "net/minecraft/client/player/RemotePlayer",
		"signature": "Lnet/minecraft/client/player/RemotePlayer;",
		"fields": [],
		"methods": []
	},
	"axisAligned": {
		"obfuscated": "net/minecraft/world/phys/AABB",
		"signature": "Lnet/minecraft/world/phys/AABB;"
	},
	"render": {
		"obfuscated": "net/minecraft/client/renderer/entity/EntityRenderDispatcher",
		"signature": "Lnet/minecraft/client/renderer/entity/EntityRenderDispatcher;"
	},
	"entity": {
		"obfuscated": "net/minecraft/world/entity/Entity",
		"signature": "Lnet/minecraft/world/entity/Entity;"
	},
	"net/minecraft/client/Minecraft": {
		"obfuscated": "net/minecraft/client/Minecraft",
		"fields": [
			{
				"name": "theMinecraft",
				"obfuscated": "instance",
				"signature": "Lnet/minecraft/client/Minecraft;",
				"static": true
			},
			{
				"name": "thePlayer",
				"obfuscated": "player",
				"signature": "Lnet/minecraft/client/player/LocalPlayer;",
				"static": false
			},
			{
				"name": "theWorld",
				"obfuscated": "level",
				"signature": "Lnet/minecraft/client/multiplayer/ClientLevel;",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/world/entity/Entity": {
		"obfuscated": "net/minecraft/world/entity/Entity",
		"fields": [
			{
				"name": "posX",
				"obfuscated": "xo",
				"signature": "D",
				"static": false
			},
			{
				"name": "posZ",
				"obfuscated": "zo",
				"signature": "D",
				"static": false
			},
			{
				"name": "boundingBox",
				"obfuscated": "bb",
				"signature": "Lnet/minecraft/world/phys/AABB;",
				"static": false
			}
		],
		"methods": [
			{
				"name": "getX",
				"obfuscated": "getX",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getZ",
				"obfuscated": "getZ",
				"signature": "()D",
				"static": false
			}
		]
	},
	"net/minecraft/client/multiplayer/ClientLevel": {
		"obfuscated": "net/minecraft/client/multiplayer/ClientLevel",
		"fields": [
			{
				"name": "entityList",
				"obfuscated": "players",
				"signature": "Ljava/util/List;",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/client/renderer/entity/EntityRenderDispatcher": {
		"obfuscated": "net/minecraft/client/renderer/entity/EntityRenderDispatcher",
		"fields": [],
		"methods": [
			{
				"name": "renderEntityStatic",
				"obfuscated": "render",
				"signature": "(Lnet/minecraft/world/entity/Entity;DDDFLcom/mojang/blaze3d/vertex/PoseStack;Lnet/minecraft/client/renderer/MultiBufferSource;I)V",
				"static": false
			}
		]
	},
	"net/minecraft/world/phys/AABB": {
		"obfuscated": "net/minecraft/world/phys/AABB",
		"fields": [
			{
				"name": "minX",
				"obfuscated": "minX",
				"signature": "D",
				"static": false
			},
			{
				"name": "minY",
				"obfuscated": "minY",
				"signature": "D",
				"static": false
			},
			{
				"name": "minZ",
				"obfuscated": "minZ",
				"signature": "D",
				"static": false
			},
			{
				"name": "maxX",
				"obfuscated": "maxX",
				"signature": "D",
				"static": false
			},
			{
				"name": "maxY",
				"obfuscated": "maxY",
				"signature": "D",
				"static": false
			},
			{
				"name": "maxZ",
				"obfuscated": "maxZ",
				"signature": "D",
				"static": false
			}
		],
		"methods": []
	}
}
)");
}