#pragma once
namespace Mappings
{
	auto mappings_laby_1_18 = XOR_STR_S(R"(
{
	"minecraft": {
		"obfuscated": "dyr",
		"signature": "Ldyr;",
		"fields": [],
		"methods": []
	},
	"world": {
		"obfuscated": "ems",
		"signature": "Lems;",
		"fields": [],
		"methods": []
	},
	"myPlayer": {
		"obfuscated": "epw",
		"signature": "Lepw;",
		"fields": [],
		"methods": []
	},
	"playerEntity": {
		"obfuscated": "boj",
		"signature": "Lboj;",
		"fields": [],
		"methods": []
	},
	"otherPlayer": {
		"obfuscated": "epx",
		"signature": "Lepx;",
		"fields": [],
		"methods": []
	},
	"axisAligned": {
		"obfuscated": "dpj",
		"signature": "Ldpj;"
	},
	"vec3": {
		"obfuscated": "dpo",
		"signature": "Ldpo;"
	},
	"entity": {
		"obfuscated": "axk",
		"signature": "Laxk;"
	},
	"mobEntity": {
		"obfuscated": "aya",
		"signature": "Laya;"
	},
	"hitResult": {
		"obfuscated": "dpm",
		"signature": "Ldpm;"
	},
	"entityHitResult": {
		"obfuscated": "dpl",
		"signature": "Ldpl;"
	},
	"timer": {
		"obfuscated": "dzf",
		"signature": "Ldzf;"
	},
	"dyr": {
		"obfuscated": "dyr",
		"fields": [
			{
				"name": "theMinecraft",
				"obfuscated": "E",
				"signature": "Ldyr;",
				"static": true
			},
			{
				"name": "hitResult",
				"obfuscated": "v",
				"signature": "Ldpm;",
				"static": true
			},
			{
				"name": "thePlayer",
				"obfuscated": "s",
				"signature": "Lepw;",
				"static": false
			},
			{
				"name": "theTimer",
				"obfuscated": "Q",
				"signature": "Ldzf;",
				"static": false
			},
			{
				"name": "theWorld",
				"obfuscated": "r",
				"signature": "Lems;",
				"static": false
			}
		],
		"methods": []
	},
	"dpl": {
		"obfuscated": "dpl",
		"fields": [
			{
				"name": "entity",
				"obfuscated": "b",
				"signature": "Laxk;",
				"static": false
			}
		],
		"methods": []
	},
	"dzf": {
		"obfuscated": "dzf",
		"fields": [
			{
				"name": "partialTick",
				"obfuscated": "a",
				"signature": "F",
				"static": false
			}
		],
		"methods": []
	},
	"boj": {
		"obfuscated": "boj",
		"fields": [],
		"methods": [
			{
				"name": "getAttackStrength",
				"obfuscated": "v",
				"signature": "(F)F",
				"static": false
			}
		]
	},
	"axk": {
		"obfuscated": "axk",
		"fields": [
			{
				"name": "onGround",
				"obfuscated": "y",
				"signature": "Z",
				"static": false
			},
			{
				"name": "rotationYaw",
				"obfuscated": "aA",
				"signature": "F",
				"static": false
			},
			{
				"name": "rotationPitch",
				"obfuscated": "aB",
				"signature": "F",
				"static": false
			},
			{
				"name": "deltaMovement",
				"obfuscated": "az",
				"signature": "Ldpo;",
				"static": false
			},
			{
				"name": "lastTickX",
				"obfuscated": "t",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickY",
				"obfuscated": "u",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickZ",
				"obfuscated": "v",
				"signature": "D",
				"static": false
			},
			{
				"name": "boundingBox",
				"obfuscated": "aC",
				"signature": "Ldpj;",
				"static": false
			}
		],
		"methods": [
			{
				"name": "isInvisible",
				"obfuscated": "bU",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "getEyeHeight",
				"obfuscated": "cy",
				"signature": "()F",
				"static": false
			},
			{
				"name": "isAlive",
				"obfuscated": "bl",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "getX",
				"obfuscated": "dc",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getY",
				"obfuscated": "de",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getZ",
				"obfuscated": "di",
				"signature": "()D",
				"static": false
			}
		]
	},
	"ems": {
		"obfuscated": "ems",
		"fields": [
			{
				"name": "entityList",
				"obfuscated": "F",
				"signature": "Ljava/util/List;",
				"static": false
			}
		],
		"methods": []
	},
	"dpo": {
		"obfuscated": "dpo",
		"fields": [
			{
				"name": "y",
				"obfuscated": "c",
				"signature": "D",
				"static": false
			}
		],
		"methods": []
	},
	"dpj": {
		"obfuscated": "dpj",
		"fields": [
			{
				"name": "minX",
				"obfuscated": "a",
				"signature": "D",
				"static": false
			},
			{
				"name": "minY",
				"obfuscated": "b",
				"signature": "D",
				"static": false
			},
			{
				"name": "minZ",
				"obfuscated": "c",
				"signature": "D",
				"static": false
			},
			{
				"name": "maxX",
				"obfuscated": "d",
				"signature": "D",
				"static": false
			},
			{
				"name": "maxY",
				"obfuscated": "e",
				"signature": "D",
				"static": false
			},
			{
				"name": "maxZ",
				"obfuscated": "f",
				"signature": "D",
				"static": false
			}
		],
		"methods": []
	}
}
)");
}