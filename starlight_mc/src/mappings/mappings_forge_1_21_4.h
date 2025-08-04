#pragma once
namespace Mappings
{
	auto mappings_forge_1_21_4 = XOR_STR_S(R"(
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
	"vec3": {
		"obfuscated": "net/minecraft/world/phys/Vec3",
		"signature": "Lnet/minecraft/world/phys/Vec3;"
	},
	"render": {
		"obfuscated": "net/minecraft/client/renderer/entity/EntityRenderDispatcher",
		"signature": "Lnet/minecraft/client/renderer/entity/EntityRenderDispatcher;"
	},
	"entity": {
		"obfuscated": "net/minecraft/world/entity/Entity",
		"signature": "Lnet/minecraft/world/entity/Entity;"
	},
	"mobEntity": {
		"obfuscated": "net/minecraft/world/entity/Mob",
		"signature": "Lnet/minecraft/world/entity/Mob;"
	},
	"hitResult": {
		"obfuscated": "net/minecraft/world/phys/HitResult",
		"signature": "Lnet/minecraft/world/phys/HitResult;"
	},
	"entityHitResult": {
		"obfuscated": "net/minecraft/world/phys/EntityHitResult",
		"signature": "Lnet/minecraft/world/phys/EntityHitResult;"
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
				"name": "hitResult",
				"obfuscated": "hitResult",
				"signature": "Lnet/minecraft/world/phys/HitResult;",
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
	"net/minecraft/world/phys/EntityHitResult": {
		"obfuscated": "net/minecraft/world/phys/EntityHitResult",
		"fields": [
			{
				"name": "entity",
				"obfuscated": "entity",
				"signature": "Lnet/minecraft/world/entity/Entity;",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/world/entity/Entity": {
		"obfuscated": "net/minecraft/world/entity/Entity",
		"fields": [
			{
				"name": "onGround",
				"obfuscated": "onGround",
				"signature": "Z",
				"static": false
			},
			{
				"name": "deltaMovement",
				"obfuscated": "deltaMovement",
				"signature": "Lnet/minecraft/world/phys/Vec3;",
				"static": false
			}
		],
		"methods": [
			{
				"name": "isInvisible",
				"obfuscated": "isInvisible",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "isAlive",
				"obfuscated": "isAlive",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "getX",
				"obfuscated": "getX",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getY",
				"obfuscated": "getY",
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
	"net/minecraft/world/phys/Vec3": {
		"obfuscated": "net/minecraft/world/phys/Vec3",
		"fields": [
			{
				"name": "y",
				"obfuscated": "y",
				"signature": "D",
				"static": false
			}
		],
		"methods": []
	}
}
)");
}