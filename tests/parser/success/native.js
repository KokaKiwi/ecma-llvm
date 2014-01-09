
var memcpy = native function memcpy(dst: *u8, src: *u8): void;
var strdup = native function strdup(s: *u8): *u8;

var a: int = 25;
var str: string = "Hello world!";
var a: u8 = 'a', b: uint = 25, c: u32 = 0x01234567;
var ptr: *void = memcpy;
