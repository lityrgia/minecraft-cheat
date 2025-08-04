#pragma once
namespace Mappings
{
	auto mappings_fabric_1_21_4 = XOR_STR_S(R"(
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
	"playerEntity": {
		"obfuscated": "net/minecraft/class_1657",
		"signature": "Lnet/minecraft/class_1657;",
		"fields": [],
		"methods": []
	},
	"otherPlayer": {
		"obfuscated": "net/minecraft/class_745",
		"signature": "Lnet/minecraft/class_745;",
		"fields": [],
		"methods": []
	},
	"axisAligned": {
		"obfuscated": "net/minecraft/class_238",
		"signature": "Lnet/minecraft/class_238;"
	},
	"vec3": {
		"obfuscated": "net/minecraft/class_243",
		"signature": "Lnet/minecraft/class_243;"
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
	"timer": {
		"obfuscated": "net/minecraft/class_9779$class_9781",
		"signature": "Lnet/minecraft/class_9779$class_9781;"
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
				"name": "theTimer",
				"obfuscated": "field_52750",
				"signature": "Lnet/minecraft/class_9779$class_9781;",
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
	"net/minecraft/class_9779$class_9781": {
		"obfuscated": "net/minecraft/class_9779$class_9781",
		"fields": [
			{
				"name": "partialTick",
				"obfuscated": "field_51958",
				"signature": "F",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/class_1657": {
		"obfuscated": "net/minecraft/class_1657",
		"fields": [],
		"methods": [
			{
				"name": "getAttackStrength",
				"obfuscated": "method_7261",
				"signature": "(F)F",
				"static": false
			}
		]
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
				"name": "rotationYaw",
				"obfuscated": "field_6031",
				"signature": "F",
				"static": false
			},
			{
				"name": "rotationPitch",
				"obfuscated": "field_5965",
				"signature": "F",
				"static": false
			},
			{
				"name": "ticksExisted",
				"obfuscated": "field_6012",
				"signature": "I",
				"static": false
			},
			{
				"name": "deltaMovement",
				"obfuscated": "field_18276",
				"signature": "Lnet/minecraft/class_243;",
				"static": false
			},
			{
				"name": "lastTickX",
				"obfuscated": "field_6014",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickY",
				"obfuscated": "field_6036",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickZ",
				"obfuscated": "field_5969",
				"signature": "D",
				"static": false
			},
			{
				"name": "boundingBox",
				"obfuscated": "field_6005",
				"signature": "Lnet/minecraft/class_238;",
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
				"name": "getEyeHeight",
				"obfuscated": "method_5751",
				"signature": "()F",
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
				"signature": "(Lnet/minecraft/class_1297;DDDFFLnet/minecraft/class_4587;Lnet/minecraft/class_4597;I)V",
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
	},
	"net/minecraft/class_238": {
		"obfuscated": "net/minecraft/class_238",
		"fields": [
			{
				"name": "minX",
				"obfuscated": "field_1323",
				"signature": "D",
				"static": false
			},
			{
				"name": "minY",
				"obfuscated": "field_1322",
				"signature": "D",
				"static": false
			},
			{
				"name": "minZ",
				"obfuscated": "field_1321",
				"signature": "D",
				"static": false
			},
			{
				"name": "maxX",
				"obfuscated": "field_1320",
				"signature": "D",
				"static": false
			},
			{
				"name": "maxY",
				"obfuscated": "field_1325",
				"signature": "D",
				"static": false
			},
			{
				"name": "maxZ",
				"obfuscated": "field_1324",
				"signature": "D",
				"static": false
			}
		],
		"methods": []
	}
}
)");
}