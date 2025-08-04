#pragma once
namespace Mappings
{
	auto mappings_laby_1_21_4 = XOR_STR_S(R"(
{
	"minecraft": {
		"obfuscated": "flk",
		"signature": "Lflk;",
		"fields": [],
		"methods": []
	},
	"world": {
		"obfuscated": "gga",
		"signature": "Lgga;",
		"fields": [],
		"methods": []
	},
	"myPlayer": {
		"obfuscated": "gkx",
		"signature": "Lgkx;",
		"fields": [],
		"methods": []
	},
	"playerEntity": {
		"obfuscated": "coy",
		"signature": "Lcoy;",
		"fields": [],
		"methods": []
	},
	"otherPlayer": {
		"obfuscated": "gky",
		"signature": "Lgky;",
		"fields": [],
		"methods": []
	},
	"axisAligned": {
		"obfuscated": "faw",
		"signature": "Lfaw;"
	},
	"vec3": {
		"obfuscated": "fbb",
		"signature": "Lfbb;"
	},
	"entity": {
		"obfuscated": "bum",
		"signature": "Lbum;"
	},
	"mobEntity": {
		"obfuscated": "bvk",
		"signature": "Lbvk;"
	},
	"hitResult": {
		"obfuscated": "faz",
		"signature": "Lfaz;"
	},
	"entityHitResult": {
		"obfuscated": "fay",
		"signature": "Lfay;"
	},
	"timer": {
		"obfuscated": "fla$b",
		"signature": "Lfla$b;"
	},
	"flk": {
		"obfuscated": "flk",
		"fields": [
			{
				"name": "theMinecraft",
				"obfuscated": "F",
				"signature": "Lflk;",
				"static": true
			},
			{
				"name": "hitResult",
				"obfuscated": "w",
				"signature": "Lfaz;",
				"static": true
			},
			{
				"name": "thePlayer",
				"obfuscated": "t",
				"signature": "Lgkx;",
				"static": false
			},
			{
				"name": "theTimer",
				"obfuscated": "T",
				"signature": "Lfla$b;",
				"static": false
			},
			{
				"name": "theWorld",
				"obfuscated": "s",
				"signature": "Lgga;",
				"static": false
			}
		],
		"methods": []
	},
	"fay": {
		"obfuscated": "fay",
		"fields": [
			{
				"name": "entity",
				"obfuscated": "b",
				"signature": "Lbum;",
				"static": false
			}
		],
		"methods": []
	},
	"fla$b": {
		"obfuscated": "fla$b",
		"fields": [
			{
				"name": "partialTick",
				"obfuscated": "c",
				"signature": "F",
				"static": false
			}
		],
		"methods": []
	},
	"coy": {
		"obfuscated": "coy",
		"fields": [],
		"methods": [
			{
				"name": "getAttackStrength",
				"obfuscated": "H",
				"signature": "(F)F",
				"static": false
			}
		]
	},
	"bum": {
		"obfuscated": "bum",
		"fields": [
			{
				"name": "onGround",
				"obfuscated": "aD",
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
				"signature": "Lfbb;",
				"static": false
			},
			{
				"name": "lastTickX",
				"obfuscated": "K",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickY",
				"obfuscated": "L",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickZ",
				"obfuscated": "M",
				"signature": "D",
				"static": false
			},
			{
				"name": "boundingBox",
				"obfuscated": "aC",
				"signature": "Lfaw;",
				"static": false
			}
		],
		"methods": [
			{
				"name": "isInvisible",
				"obfuscated": "cp",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "getEyeHeight",
				"obfuscated": "cS",
				"signature": "()F",
				"static": false
			},
			{
				"name": "isAlive",
				"obfuscated": "bL",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "getX",
				"obfuscated": "dA",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getY",
				"obfuscated": "dC",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getZ",
				"obfuscated": "dG",
				"signature": "()D",
				"static": false
			}
		]
	},
	"gga": {
		"obfuscated": "gga",
		"fields": [
			{
				"name": "entityList",
				"obfuscated": "L",
				"signature": "Ljava/util/List;",
				"static": false
			}
		],
		"methods": []
	},
	"fbb": {
		"obfuscated": "fbb",
		"fields": [
			{
				"name": "y",
				"obfuscated": "e",
				"signature": "D",
				"static": false
			}
		],
		"methods": []
	},
	"faw": {
		"obfuscated": "faw",
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