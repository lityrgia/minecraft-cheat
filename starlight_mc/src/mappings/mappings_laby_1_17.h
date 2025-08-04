#pragma once
namespace Mappings
{
	auto mappings_laby_1_17 = XOR_STR_S(R"(
{
	"minecraft": {
		"obfuscated": "dvp",
		"signature": "Ldvp;",
		"fields": [],
		"methods": []
	},
	"world": {
		"obfuscated": "eji",
		"signature": "Leji;",
		"fields": [],
		"methods": []
	},
	"myPlayer": {
		"obfuscated": "emm",
		"signature": "Lemm;",
		"fields": [],
		"methods": []
	},
	"playerEntity": {
		"obfuscated": "bke",
		"signature": "Lbke;",
		"fields": [],
		"methods": []
	},
	"otherPlayer": {
		"obfuscated": "emn",
		"signature": "Lemn;",
		"fields": [],
		"methods": []
	},
	"axisAligned": {
		"obfuscated": "dmv",
		"signature": "Ldmv;"
	},
	"vec3": {
		"obfuscated": "dna",
		"signature": "Ldna;"
	},
	"entity": {
		"obfuscated": "atg",
		"signature": "Latg;"
	},
	"mobEntity": {
		"obfuscated": "atw",
		"signature": "Latw;"
	},
	"hitResult": {
		"obfuscated": "dmy",
		"signature": "Ldmy;"
	},
	"entityHitResult": {
		"obfuscated": "dmx",
		"signature": "Ldmx;"
	},
	"timer": {
		"obfuscated": "dwb",
		"signature": "Ldwb;"
	},
	"dvp": {
		"obfuscated": "dvp",
		"fields": [
			{
				"name": "theMinecraft",
				"obfuscated": "E",
				"signature": "Ldvp;",
				"static": true
			},
			{
				"name": "hitResult",
				"obfuscated": "v",
				"signature": "Ldmy;",
				"static": true
			},
			{
				"name": "thePlayer",
				"obfuscated": "s",
				"signature": "Lemm;",
				"static": false
			},
			{
				"name": "theTimer",
				"obfuscated": "P",
				"signature": "Ldwb;",
				"static": false
			},
			{
				"name": "theWorld",
				"obfuscated": "r",
				"signature": "Leji;",
				"static": false
			}
		],
		"methods": []
	},
	"dmx": {
		"obfuscated": "dmx",
		"fields": [
			{
				"name": "entity",
				"obfuscated": "b",
				"signature": "Latg;",
				"static": false
			}
		],
		"methods": []
	},
	"dwb": {
		"obfuscated": "dwb",
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
	"bke": {
		"obfuscated": "bke",
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
	"atg": {
		"obfuscated": "atg",
		"fields": [
			{
				"name": "onGround",
				"obfuscated": "z",
				"signature": "Z",
				"static": false
			},
			{
				"name": "rotationYaw",
				"obfuscated": "ay",
				"signature": "F",
				"static": false
			},
			{
				"name": "rotationPitch",
				"obfuscated": "az",
				"signature": "F",
				"static": false
			},
			{
				"name": "deltaMovement",
				"obfuscated": "ax",
				"signature": "Ldna;",
				"static": false
			},
			{
				"name": "lastTickX",
				"obfuscated": "u",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickY",
				"obfuscated": "v",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickZ",
				"obfuscated": "w",
				"signature": "D",
				"static": false
			},
			{
				"name": "boundingBox",
				"obfuscated": "aA",
				"signature": "Ldmv;",
				"static": false
			}
		],
		"methods": [
			{
				"name": "isInvisible",
				"obfuscated": "bP",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "getEyeHeight",
				"obfuscated": "ct",
				"signature": "()F",
				"static": false
			},
			{
				"name": "isAlive",
				"obfuscated": "bg",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "getX",
				"obfuscated": "cX",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getY",
				"obfuscated": "cZ",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getZ",
				"obfuscated": "dd",
				"signature": "()D",
				"static": false
			}
		]
	},
	"eji": {
		"obfuscated": "eji",
		"fields": [
			{
				"name": "entityList",
				"obfuscated": "E",
				"signature": "Ljava/util/List;",
				"static": false
			}
		],
		"methods": []
	},
	"dna": {
		"obfuscated": "dna",
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
	"dmv": {
		"obfuscated": "dmv",
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