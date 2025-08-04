#pragma once
namespace Mappings
{
	auto mappings_laby_1_19 = XOR_STR_S(R"(
{
	"minecraft": {
		"obfuscated": "emh",
		"signature": "Lemh;",
		"fields": [],
		"methods": []
	},
	"world": {
		"obfuscated": "fdj",
		"signature": "Lfdj;",
		"fields": [],
		"methods": []
	},
	"myPlayer": {
		"obfuscated": "fhk",
		"signature": "Lfhk;",
		"fields": [],
		"methods": []
	},
	"playerEntity": {
		"obfuscated": "bym",
		"signature": "Lbym;",
		"fields": [],
		"methods": []
	},
	"otherPlayer": {
		"obfuscated": "fhl",
		"signature": "Lfhl;",
		"fields": [],
		"methods": []
	},
	"axisAligned": {
		"obfuscated": "ecz",
		"signature": "Lecz;"
	},
	"vec3": {
		"obfuscated": "ede",
		"signature": "Lede;"
	},
	"entity": {
		"obfuscated": "bfh",
		"signature": "Lbfh;"
	},
	"mobEntity": {
		"obfuscated": "bfz",
		"signature": "Lbfz;"
	},
	"hitResult": {
		"obfuscated": "edc",
		"signature": "Ledc;"
	},
	"entityHitResult": {
		"obfuscated": "edb",
		"signature": "Ledb;"
	},
	"timer": {
		"obfuscated": "emu",
		"signature": "Lemu;"
	},
	"emh": {
		"obfuscated": "emh",
		"fields": [
			{
				"name": "theMinecraft",
				"obfuscated": "F",
				"signature": "Lemh;",
				"static": true
			},
			{
				"name": "hitResult",
				"obfuscated": "w",
				"signature": "Ledc;",
				"static": true
			},
			{
				"name": "thePlayer",
				"obfuscated": "t",
				"signature": "Lfhk;",
				"static": false
			},
			{
				"name": "theTimer",
				"obfuscated": "R",
				"signature": "Lemu;",
				"static": false
			},
			{
				"name": "theWorld",
				"obfuscated": "s",
				"signature": "Lfdj;",
				"static": false
			}
		],
		"methods": []
	},
	"edb": {
		"obfuscated": "edb",
		"fields": [
			{
				"name": "entity",
				"obfuscated": "b",
				"signature": "Lbfh;",
				"static": false
			}
		],
		"methods": []
	},
	"emu": {
		"obfuscated": "emu",
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
	"bym": {
		"obfuscated": "bym",
		"fields": [],
		"methods": [
			{
				"name": "getAttackStrength",
				"obfuscated": "z",
				"signature": "(F)F",
				"static": false
			}
		]
	},
	"bfh": {
		"obfuscated": "bfh",
		"fields": [
			{
				"name": "onGround",
				"obfuscated": "N",
				"signature": "Z",
				"static": false
			},
			{
				"name": "rotationYaw",
				"obfuscated": "aE",
				"signature": "F",
				"static": false
			},
			{
				"name": "rotationPitch",
				"obfuscated": "aF",
				"signature": "F",
				"static": false
			},
			{
				"name": "deltaMovement",
				"obfuscated": "aD",
				"signature": "Lede;",
				"static": false
			},
			{
				"name": "lastTickX",
				"obfuscated": "I",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickY",
				"obfuscated": "J",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickZ",
				"obfuscated": "K",
				"signature": "D",
				"static": false
			},
			{
				"name": "boundingBox",
				"obfuscated": "aG",
				"signature": "Lecz;",
				"static": false
			}
		],
		"methods": [
			{
				"name": "isInvisible",
				"obfuscated": "ca",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "getEyeHeight",
				"obfuscated": "cE",
				"signature": "()F",
				"static": false
			},
			{
				"name": "isAlive",
				"obfuscated": "bq",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "getX",
				"obfuscated": "dl",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getY",
				"obfuscated": "dn",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getZ",
				"obfuscated": "dr",
				"signature": "()D",
				"static": false
			}
		]
	},
	"fdj": {
		"obfuscated": "fdj",
		"fields": [
			{
				"name": "entityList",
				"obfuscated": "H",
				"signature": "Ljava/util/List;",
				"static": false
			}
		],
		"methods": []
	},
	"ede": {
		"obfuscated": "ede",
		"fields": [
			{
				"name": "y",
				"obfuscated": "d",
				"signature": "D",
				"static": false
			}
		],
		"methods": []
	},
	"ecz": {
		"obfuscated": "ecz",
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