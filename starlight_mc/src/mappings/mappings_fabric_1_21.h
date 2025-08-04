#pragma once
namespace Mappings
{
	auto mappings_fabric_1_21 = XOR_STR_S(R"(
{
	"minecraft": {
		"obfuscated": "net/minecraft/class_310",
		"signature": "Lnet/minecraft/class_310;",
		"fields": [],
		"methods": []
	},
	"world": {
		"obfuscated": "net/minecraft/class_638",
		"signature": "Lnet/minecraft/class_638;",
		"fields": [],
		"methods": []
	},
	"myPlayer": {
		"obfuscated": "net/minecraft/class_746",
		"signature": "Lnet/minecraft/class_746;",
		"fields": [],
		"methods": []
	},
	"otherPlayer": {
		"obfuscated": "net/minecraft/class_745",
		"signature": "Lnet/minecraft/class_745;",
		"fields": [],
		"methods": []
	},
	"render": {
		"obfuscated": "net/minecraft/class_898",
		"signature": "Lnet/minecraft/class_898;"
	},
	"entity": {
		"obfuscated": "net/minecraft/class_1297",
		"signature": "Lnet/minecraft/class_1297;"
	},
	"mobEntity": {
		"obfuscated": "net/minecraft/class_1308",
		"signature": "Lnet/minecraft/class_1308;"
	},
	"hitResult": {
		"obfuscated": "net/minecraft/class_239",
		"signature": "Lnet/minecraft/class_239;"
	},
	"entityHitResult": {
		"obfuscated": "net/minecraft/class_3966",
		"signature": "Lnet/minecraft/class_3966;"
	},
	"net/minecraft/class_310": {
		"obfuscated": "net/minecraft/class_310",
		"fields": [
			{
				"name": "theMinecraft",
				"obfuscated": "field_1700",
				"signature": "Lnet/minecraft/class_310;",
				"static": true
			},
			{
				"name": "hitResult",
				"obfuscated": "field_1765",
				"signature": "Lnet/minecraft/class_239;",
				"static": true
			},
			{
				"name": "thePlayer",
				"obfuscated": "field_1724",
				"signature": "Lnet/minecraft/class_746;",
				"static": false
			},
			{
				"name": "theWorld",
				"obfuscated": "field_1687",
				"signature": "Lnet/minecraft/class_638;",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/class_3966": {
		"obfuscated": "net/minecraft/class_3966",
		"fields": [
			{
				"name": "entity",
				"obfuscated": "field_17592",
				"signature": "Lnet/minecraft/class_1297;",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/class_1297": {
		"obfuscated": "net/minecraft/class_1297",
		"fields": [
			{
				"name": "onGround",
				"obfuscated": "field_5952",
				"signature": "Z",
				"static": false
			},
			{
				"name": "deltaMovement",
				"obfuscated": "field_18276",
				"signature": "Lnet/minecraft/class_243;",
				"static": false
			}
		],
		"methods": [
			{
				"name": "isInvisible",
				"obfuscated": "method_5767",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "isAlive",
				"obfuscated": "method_5805",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "getX",
				"obfuscated": "method_23317",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getY",
				"obfuscated": "method_23318",
				"signature": "()D",
				"static": false
			},
			{
				"name": "getZ",
				"obfuscated": "method_23321",
				"signature": "()D",
				"static": false
			}
		]
	},
	"net/minecraft/class_638": {
		"obfuscated": "net/minecraft/class_638",
		"fields": [
			{
				"name": "entityList",
				"obfuscated": "field_18226",
				"signature": "Ljava/util/List;",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/class_898": {
		"obfuscated": "net/minecraft/class_898",
		"fields": [],
		"methods": [
			{
				"name": "renderEntityStatic",
				"obfuscated": "method_3954",
				"signature": "(Lnet/minecraft/class_1297;DDDFLnet/minecraft/class_4587;Lnet/minecraft/class_4597;I)V",
				"static": false
			}
		]
	},
	"net/minecraft/class_243": {
		"obfuscated": "net/minecraft/class_243",
		"fields": [
			{
				"name": "y",
				"obfuscated": "field_1351",
				"signature": "D",
				"static": false
			}
		],
		"methods": []
	}
}
)");
}