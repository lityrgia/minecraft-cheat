#pragma once
namespace Mappings
{
	auto mappings_laby_1_20 = XOR_STR_S(R"(
{
	"minecraft": {
		"obfuscated": "enn",
		"signature": "Lenn;",
		"fields": [],
		"methods": []
	},
	"world": {
		"obfuscated": "few",
		"signature": "Lfew;",
		"fields": [],
		"methods": []
	},
	"myPlayer": {
		"obfuscated": "fiy",
		"signature": "Lfiy;",
		"fields": [],
		"methods": []
	},
	"playerEntity": {
		"obfuscated": "byo",
		"signature": "Lbyo;",
		"fields": [],
		"methods": []
	},
	"otherPlayer": {
		"obfuscated": "fiz",
		"signature": "Lfiz;",
		"fields": [],
		"methods": []
	},
	"axisAligned": {
		"obfuscated": "eed",
		"signature": "Leed;"
	},
	"vec3": {
		"obfuscated": "eei",
		"signature": "Leei;"
	},
	"entity": {
		"obfuscated": "bfj",
		"signature": "Lbfj;"
	},
	"mobEntity": {
		"obfuscated": "bgb",
		"signature": "Lbgb;"
	},
	"hitResult": {
		"obfuscated": "eeg",
		"signature": "Leeg;"
	},
	"entityHitResult": {
		"obfuscated": "eef",
		"signature": "Leef;"
	},
	"timer": {
		"obfuscated": "eoa",
		"signature": "Leoa;"
	},
	"enn": {
		"obfuscated": "enn",
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
				"signature": "Leeg;",
				"static": true
			},
			{
				"name": "thePlayer",
				"obfuscated": "t",
				"signature": "Lfiy;",
				"static": false
			},
			{
				"name": "theTimer",
				"obfuscated": "R",
				"signature": "Leoa;",
				"static": false
			},
			{
				"name": "theWorld",
				"obfuscated": "s",
				"signature": "Lfew;",
				"static": false
			}
		],
		"methods": []
	},
	"eef": {
		"obfuscated": "eef",
		"fields": [
			{
				"name": "entity",
				"obfuscated": "b",
				"signature": "Lbfj;",
				"static": false
			}
		],
		"methods": []
	},
	"eoa": {
		"obfuscated": "eoa",
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
	"byo": {
		"obfuscated": "byo",
		"fields": [],
		"methods": [
			{
				"name": "getAttackStrength",
				"obfuscated": "A",
				"signature": "(F)F",
				"static": false
			}
		]
	},
	"bfj": {
		"obfuscated": "bfj",
		"fields": [
			{
				"name": "onGround",
				"obfuscated": "aJ",
				"signature": "Z",
				"static": false
			},
			{
				"name": "rotationYaw",
				"obfuscated": "aG",
				"signature": "F",
				"static": false
			},
			{
				"name": "rotationPitch",
				"obfuscated": "aH",
				"signature": "F",
				"static": false
			},
			{
				"name": "deltaMovement",
				"obfuscated": "aF",
				"signature": "Leei;",
				"static": false
			},
			{
				"name": "lastTickX",
				"obfuscated": "J",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickY",
				"obfuscated": "K",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickZ",
				"obfuscated": "L",
				"signature": "D",
				"static": false
			},
			{
				"name": "boundingBox",
				"obfuscated": "aI",
				"signature": "Leed;",
				"static": false
			}
		],
		"methods": [
			{
				"name": "isInvisible",
				"obfuscated": "cb",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "getEyeHeight",
				"obfuscated": "cF",
				"signature": "()F",
				"static": false
			},
			{
				"name": "isAlive",
				"obfuscated": "bs",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "getX",
				"obfuscated": "dn",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getY",
				"obfuscated": "dp",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getZ",
				"obfuscated": "dt",
				"signature": "()D",
				"static": false
			}
		]
	},
	"few": {
		"obfuscated": "few",
		"fields": [
			{
				"name": "entityList",
				"obfuscated": "I",
				"signature": "Ljava/util/List;",
				"static": false
			}
		],
		"methods": []
	},
	"eei": {
		"obfuscated": "eei",
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
	"eed": {
		"obfuscated": "eed",
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