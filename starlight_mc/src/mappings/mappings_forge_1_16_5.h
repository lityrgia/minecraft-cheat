#pragma once
namespace Mappings
{
	auto mappings_forge_1_16_5 = XOR_STR_S(R"(
{
	"minecraft": {
		"obfuscated": "djz",
		"signature": "Ldjz;",
		"fields": [],
		"methods": []
	},
	"world": {
		"obfuscated": "dwt",
		"signature": "Ldwt;",
		"fields": [],
		"methods": []
	},
	"myPlayer": {
		"obfuscated": "dzm",
		"signature": "Ldzm;",
		"fields": [],
		"methods": []
	},
	"playerEntity": {
		"obfuscated": "bfw",
		"signature": "Lbfw;",
		"fields": [],
		"methods": []
	},
	"otherPlayer": {
		"obfuscated": "dzn",
		"signature": "Ldzn;",
		"fields": [],
		"methods": []
	},
	"axisAligned": {
		"obfuscated": "dci",
		"signature": "Ldci;"
	},
	"vec3": {
		"obfuscated": "dcn",
		"signature": "Ldcn;"
	},
	"render": {
		"obfuscated": "eet",
		"signature": "Leet;"
	},
	"entity": {
		"obfuscated": "aqa",
		"signature": "Laqa;"
	},
	"mobEntity": {
		"obfuscated": "aqn",
		"signature": "Laqn;"
	},
	"hitResult": {
		"obfuscated": "dcl",
		"signature": "Ldcl;"
	},
	"entityHitResult": {
		"obfuscated": "dck",
		"signature": "Ldck;"
	},
	"timer": {
		"obfuscated": "dkk",
		"signature": "Ldkk;"
	},
	"djz": {
		"obfuscated": "djz",
		"fields": [
			{
				"name": "theMinecraft",
				"obfuscated": "F",
				"signature": "Ldjz;",
				"static": true
			},
			{
				"name": "hitResult",
				"obfuscated": "v",
				"signature": "Ldcl;",
				"static": true
			},
			{
				"name": "thePlayer",
				"obfuscated": "s",
				"signature": "Ldzm;",
				"static": false
			},
			{
				"name": "theTimer",
				"obfuscated": "P",
				"signature": "Ldkk;",
				"static": false
			},
			{
				"name": "theWorld",
				"obfuscated": "r",
				"signature": "Ldwt;",
				"static": false
			}
		],
		"methods": []
	},
	"dck": {
		"obfuscated": "dck",
		"fields": [
			{
				"name": "entity",
				"obfuscated": "b",
				"signature": "Laqa;",
				"static": false
			}
		],
		"methods": []
	},
	"dkk": {
		"obfuscated": "dkk",
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
	"bfw": {
		"obfuscated": "bfw",
		"fields": [],
		"methods": [
			{
				"name": "getAttackStrength",
				"obfuscated": "u",
				"signature": "(F)F",
				"static": false
			}
		]
	},
	"aqa": {
		"obfuscated": "aqa",
		"fields": [
			{
				"name": "onGround",
				"obfuscated": "t",
				"signature": "Z",
				"static": false
			},
			{
				"name": "rotationYaw",
				"obfuscated": "p",
				"signature": "F",
				"static": false
			},
			{
				"name": "rotationPitch",
				"obfuscated": "q",
				"signature": "F",
				"static": false
			},
			{
				"name": "ticksExisted",
				"obfuscated": "K",
				"signature": "I",
				"static": false
			},
			{
				"name": "deltaMovement",
				"obfuscated": "ak",
				"signature": "Ldcn;",
				"static": false
			},
			{
				"name": "lastTickX",
				"obfuscated": "m",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickY",
				"obfuscated": "n",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickZ",
				"obfuscated": "o",
				"signature": "D",
				"static": false
			},
			{
				"name": "boundingBox",
				"obfuscated": "al",
				"signature": "Ldci;",
				"static": false
			}
		],
		"methods": [
			{
				"name": "isInvisible",
				"obfuscated": "bF",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "getEyeHeight",
				"obfuscated": "ce",
				"signature": "()F",
				"static": false
			},
			{
				"name": "isAlive",
				"obfuscated": "aX",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "getX",
				"obfuscated": "cD",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getY",
				"obfuscated": "cE",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getZ",
				"obfuscated": "cH",
				"signature": "()D",
				"static": false
			}
		]
	},
	"dwt": {
		"obfuscated": "dwt",
		"fields": [
			{
				"name": "entityList",
				"obfuscated": "z",
				"signature": "Ljava/util/List;",
				"static": false
			}
		],
		"methods": []
	},
	"eet": {
		"obfuscated": "eet",
		"fields": [],
		"methods": [
			{
				"name": "renderEntityStatic",
				"obfuscated": "a",
				"signature": "(Laqa;DDDFFLdfm;Leag;I)V",
				"static": false
			}
		]
	},
	"dcn": {
		"obfuscated": "dcn",
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
	"dci": {
		"obfuscated": "dci",
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
