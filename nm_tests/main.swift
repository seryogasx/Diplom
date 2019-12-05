#!/usr/bin/swift
import Darwin
var a: Int = 228
var b: Int = 227
let c = CommandLine.arguments

for i in 0..<c.count {
	print("\(i): \(c[i])")
}
